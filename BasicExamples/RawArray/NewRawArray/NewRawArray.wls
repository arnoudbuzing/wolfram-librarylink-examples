(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name = "NewRawArray";

Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
NewRawArray = LibraryFunctionLoad[lib,name,{},RawArray];
Print["NewRawArray[]: ", NewRawArray[]];
LibraryUnload[lib];
DeleteFile[lib];
