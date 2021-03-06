{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "addon.cc",
        "libemf2svg/deps/libUEMF-0.2.5/uwmf_print.c",
        "libemf2svg/deps/libUEMF-0.2.5/uwmf_endian.c",
        "libemf2svg/deps/libUEMF-0.2.5/uwmf.c",
        "libemf2svg/deps/libUEMF-0.2.5/upmf_print.c",
        "libemf2svg/deps/libUEMF-0.2.5/upmf.c",
        "libemf2svg/deps/libUEMF-0.2.5/uemf_utf.c",
        "libemf2svg/deps/libUEMF-0.2.5/uemf_safe.c",
        "libemf2svg/deps/libUEMF-0.2.5/uemf_print.c",
        "libemf2svg/deps/libUEMF-0.2.5/uemf_endian.c",
        "libemf2svg/deps/libUEMF-0.2.5/uemf.c",
        "libemf2svg/deps/libUEMF-0.2.5/readwmf.c",
        "libemf2svg/deps/memstream-0.1/memstream.c",
        "libemf2svg/src/lib/emf2svg.c",
        "libemf2svg/src/lib/emf2svg_clip_utils.c",
        "libemf2svg/src/lib/emf2svg_img_utils.c",
        "libemf2svg/src/lib/emf2svg_print.c",
        "libemf2svg/src/lib/emf2svg_rec_bitmap.c",
        "libemf2svg/src/lib/emf2svg_rec_clipping.c",
        "libemf2svg/src/lib/emf2svg_rec_comment.c",
        "libemf2svg/src/lib/emf2svg_rec_control.c",
        "libemf2svg/src/lib/emf2svg_rec_drawing.c",
        "libemf2svg/src/lib/emf2svg_rec_object_creation.c",
        "libemf2svg/src/lib/emf2svg_rec_object_manipulation.c",
        "libemf2svg/src/lib/emf2svg_rec_path.c",
        "libemf2svg/src/lib/emf2svg_rec_state_record.c",
        "libemf2svg/src/lib/emf2svg_rec_transform.c",
        "libemf2svg/src/lib/emf2svg_utils.c",
        "libemf2svg/src/lib/memstream.c",
        "libemf2svg/src/lib/pmf2svg.c",
        "libemf2svg/src/lib/pmf2svg_print.c",
        "libemf2svg/src/lib/uemf.c",
        "libemf2svg/src/lib/uemf_endian.c",
        "libemf2svg/src/lib/uemf_utf.c",
        "libemf2svg/src/lib/upmf.c",
      ],
      "include_dirs": [
        "./libemf2svg/inc",
        "./libemf2svg/deps/libUEMF-0.2.5",
        "./libemf2svg/deps/memstream-0.1",
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
