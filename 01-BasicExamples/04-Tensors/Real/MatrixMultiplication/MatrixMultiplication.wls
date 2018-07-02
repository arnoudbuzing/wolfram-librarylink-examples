(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name="MatrixMultiplication";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
MatrixMultiplication = LibraryFunctionLoad[lib,name,{{Real,2},{Real,2}},{Real,2}];
Print["MatrixMultiplication[...]: ", MatrixMultiplication[ {{1,2,3},{4,5,6}}, {{1,2},{3,4},{5,6}} ]];
LibraryUnload[lib];
DeleteFile[lib];
