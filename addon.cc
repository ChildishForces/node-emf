#include <napi.h>
#include "emf2svg.h"

Napi::Value Convert(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  char *svg_out = NULL;
  size_t svg_len;
  generatorOptions *options = (generatorOptions *)calloc(1, sizeof(generatorOptions));
  options->verbose = NULL;
  options->emfplus = NULL;
  options->svgDelimiter = true;
  options->imgWidth = 0;
  options->imgHeight = 0;
  std::string input = info[0].ToString();

  int ret = emf2svg((char *)input.c_str(), input.size(), &svg_out, &svg_len, options);

  if (ret != 0) {
    Napi::String retVal = Napi::String::New(env, std::string(svg_out));

    free(svg_out);
    free(options);
    return retVal;
  }

  free(svg_out);
  free(options);

//  Napi::TypeError::New(env, input).ThrowAsJavaScriptException();
  Napi::TypeError::New(env, "An error occurred whilst converting the file").ThrowAsJavaScriptException();
  return env.Null();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "convert"), Napi::Function::New(env, Convert));
  return exports;
}

NODE_API_MODULE(addon, Init)
