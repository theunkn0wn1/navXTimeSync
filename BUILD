cc_library(
	name = "libnavx",
	srcs = glob(["src/*.cpp"]),
	hdrs = glob(["include/*.h", "include/*.cpp"]),
	strip_include_prefix = "include/",
	linkopts = ["-lpthread"],  # this library depends on threading..

)


cc_binary(
    name = "navXTimeStamp",
    srcs = glob(["NavXTimeStamp/*.cpp"]),
    deps = [":libnavx"],
    )