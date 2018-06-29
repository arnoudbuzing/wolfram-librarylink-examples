(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name = "HelloWorld";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
HelloWorld = LibraryFunctionLoad[lib,name,LinkObject,LinkObject];
Print["HelloWorld[]: ", HelloWorld[]];
LibraryUnload[lib];
DeleteFile[lib];
