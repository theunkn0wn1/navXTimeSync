# libnavx
This repository provides a driver for the  [Kauailabs Navx](https://pdocs.kauailabs.com/navx-mxp/) series of IMU sensors.

Both CMake and Bazel bindings are provided.

# Native Dependencies
the library depends on `pthread` to be available for linkage at build time.


# Usage(Bazel)
This repository provides bindings use `libnavx` in larger bazel builds.
## `WORKSPACE`
```python
def navx_workspace():
    # bring navx driver into scope so it can be linked against.

    # Note: an HTTP archive rule is used as its more lightweight and has less overhead
    # than using a git source directly.
    http_archive(
        name = "navx",
        licenses = ["https://github.com/theunkn0wn1/navXTimeSync/blob/master/LICENSE"],
        type = "zip",
        url = "https://github.com/theunkn0wn1/navXTimeSync/archive/master.zip",
        strip_prefix = "navXTimeSync-master",  # archive from gh has a prefix
        # enable canonical reproducible builds
        sha256 = "fd1107fb1e4cf40b33e95bcf27c6201d1ee0be82b89bec9d18cd651813abed57",
    )

navx_workspace()
```

## Usage in a BUILD rule

```python
cc_module(
    ...,
    deps = [
        "@navx//:libnavx",
    ],
)
```
# CMake
Mount this git repo somewhere in your project path where cmake can find it, 
for the sake of this example it will be assumed to exist under
`./third_party/navx` 
```cmake
# load this repo's CMakeLists
add_subdirectory(./third_party/navx)
# you can now link against libnavx
# Assuming your build target is `_core`
target_link_libraries(_core PUBLIC navx)


# ...
```


# Example binary
An example binary target is provided in both CMake and Bazel.

