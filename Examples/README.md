# Examples

1. DoNothing &mdash; simplest possible LibraryLink example, showing the minimal machinery
required to introduce a new library-based function in the Wolfram Language
2. Strings
    1. HelloWorld &mdash; example showing how to return a string from a library function
    2. Greetings &mdash; example showing how to pass in a string and return a string based
on that input
3. Numbers
    1. Squared &mdash; example showing how to square an integer
    2. AddIntegers &mdash; example showing how to add two integers
4. RawArray
    1. EchoRawArray &mdash; example showing how to return a `RawArray` unmodified


## Building the examples

There are two ways provided to build each example:

1. Using a Wolfram Language `.wls` build script in the directory. This builds the
example with the Wolfram Language (using the `CCompilerDriver` package), then runs
a simple example which illustrates the functions, and finally deletes the library.
This is a convenient and easy way to build simple LibraryLink examples.

2. Using a `CMake` build script  (https://cmake.org/): CMake is an open-source, cross-platform family of tools designed to build, test and package software. CMake is used to control the software compilation process using simple platform and compiler independent configuration files,
and generate native makefiles and workspaces that can be used in the compiler environment of your choice. The suite of CMake tools were created by Kitware in response to the need for a powerful, cross-platform build environment for open-source projects such as ITK and VTK.

### Building the examples using Wolfram Language

In a command line shell or terminal, change the directory to the example of
interest:

```
cd Examples
cd <example>
```

Then, run the build script (`.wls`) in that directory:

```
<example>.wls
```

The output will show the generated library and the output of a sample usage.

### Building the examples using CMake

In a command line shell or terminal, change the directory to the example of
interest:

```
cd Examples
cd <example>
```

* Create a `build` subdirectory and change into that directory:

``` mkdir build cd build ```

* Configure `CMake` for your operating system:

 1. Windows

``` cmake -G "Visual Studio 15 2017 Win64" .. ```

2. Linux

``` cmake .. ```

3. MacOSX (?)

``` cmake .. ```

* Build the project:

``` cmake --build . ```

After the build completes, open the `<example>.nb` notebook to try out the function
you just created.

## Notes

* `DLLEXPORT` is only required on Windows, but is typically include for all
* platforms to keep the code platform independent
