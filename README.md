# wolfram-librarylink-examples
How to create dynamic libraries that can be loaded in the Wolfram Language.

## Building the examples

In a command line shell or terminal, change the directory to the example of interest:

```
cd <example>
```

The examples all use the cross-platform `CMake` tool, which lets you easily create
the requisite project and solution files to compile the example on your operating system.
Create a `build` subdirectory and change into that directory:

```
mkdir build
cd build
```

Then configure `CMake` for your operating system:

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

Next, build the project:

```
cmake --build .
```
