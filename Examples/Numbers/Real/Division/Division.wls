(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name="Division";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
Division = LibraryFunctionLoad[lib,name,{Real,Real},Real];
Print["Division[3.14,2.71]: ", Division[3.14,2.71]];
LibraryUnload[lib];
DeleteFile[lib];
