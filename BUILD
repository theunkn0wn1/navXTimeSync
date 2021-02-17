cc_library(
    name = "libnavx",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob([
        "include/*.h",
        "include/*.cpp",
    ]),
    copts = ["-w"],
    linkopts = ["-lpthread"],  # this library depends on threading..
    strip_include_prefix = "include/",
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "navXTimeStamp",
    srcs = glob(["NavXTimeStamp/*.cpp"]),
    visibility = ["//visibility:public"],
    deps = [":libnavx"],
)
