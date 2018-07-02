(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

Needs["CCompilerDriver`"];
lib = CreateLibrary[{"HelloWorld.cpp"},"HelloWorld"];
Print[lib];
HelloWorld = LibraryFunctionLoad[lib,"HelloWorld",{},"UTF8String"];
Print["HelloWorld[]: ", HelloWorld[]];
LibraryUnload[lib];
DeleteFile[lib];
