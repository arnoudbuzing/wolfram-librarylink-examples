# wolfram-librarylink-examples

LibraryLink is a tool which lets you extend the Wolfram Language with C/C++ libraries. This repository is a collection of examples which show how you to do this. It is useful for developers who want to either add their own C/C++ functions to the Wolfram Language *or*
want to incorporate functionality from an existing C/C++ library.

## Building the examples using CMake

In a command line shell or terminal, change the directory to the example of interest:

```
cd Examples
cd <example>
```

The examples all use the cross-platform `CMake` tool (https://cmake.org/):

CMake is an open-source, cross-platform family of tools designed to build, test and package software. CMake is used to control the software compilation process using simple platform and compiler independent configuration files, and generate native makefiles and workspaces that can be used in the compiler environment of your choice. The suite of CMake tools were created by Kitware in response to the need for a powerful, cross-platform build environment for open-source projects such as ITK and VTK.

* Create a `build` subdirectory and change into that directory:

```
mkdir build
cd build
```

* Configure `CMake` for your operating system:


 1. Windows

```
cmake -G "Visual Studio 15 2017 Win64" ..
```

2. Linux

```
cmake ..
```

3. MacOSX (?)

```
cmake ..
```

* Build the project:

```
cmake --build .
```



## Notes

* `DLLEXPORT` is only required on Windows, but is typically include for all platforms to keep the code platform independent
