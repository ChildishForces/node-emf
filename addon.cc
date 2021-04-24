#include <napi.h>
#include "emf2svg.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

Napi::Value Convert(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsBuffer()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  char *svg_out = NULL;
  size_t svg_len;

  // Construct the lib options
  generatorOptions *options = (generatorOptions *)calloc(1, sizeof(generatorOptions));
  options->verbose = false; // Outputs information about the process
  options->emfplus = NULL; // Adds support for EMF+, unnecessary but potentially could be included with a config object later on
  options->svgDelimiter = true;
  options->imgWidth = 0; // 0 inherits the EMF/EMZ original width
  options->imgHeight = 0; // 0 inherits the EMF/EMZ original height

  // cast the Napi::Value to a Napi::Buffer<char>
  Napi::Buffer<char> buffer = info[0].As<Napi::Buffer<char>>();
  std::string inputString;

  // Iterate over the buffer to construct a std::string
  int x;
  for (x = 0; x < buffer.Length(); x++) {
    inputString += buffer[x];
  }

  // Perform the transformation
  int ret = emf2svg((char *)inputString.c_str(), inputString.size(), &svg_out, &svg_len, options);

  // If ret != 0, transform has succeeded and is now ready
  if (ret != 0) {
    Napi::String retVal = Napi::String::New(env, std::string(svg_out));

    free(svg_out);
    free(options);
    return retVal;
  }

  free(svg_out);
  free(options);
  Napi::TypeError::New(env, "An error occurred whilst converting the file").ThrowAsJavaScriptException();
  return env.Null();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "convert"), Napi::Function::New(env, Convert));
  return exports;
}

NODE_API_MODULE(addon, Init)
