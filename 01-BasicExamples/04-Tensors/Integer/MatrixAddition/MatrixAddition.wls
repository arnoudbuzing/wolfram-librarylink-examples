(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name="MatrixAddition";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
MatrixAddition = LibraryFunctionLoad[lib,name,{{Integer,2},{Integer,2}},{Integer,2}];
Print["MatrixAddition[...]: ", MatrixAddition[ {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} ]];
LibraryUnload[lib];
DeleteFile[lib];
