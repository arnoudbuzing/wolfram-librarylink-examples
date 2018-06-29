(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

Needs["CCompilerDriver`"];
lib = CreateLibrary[{"DoNothing.c"},"DoNothing"];
Print[lib];
DoNothing = LibraryFunctionLoad[lib,"DoNothing",{},"Void"];
Print["DoNothing[]: ", DoNothing[]];
LibraryUnload[lib];
DeleteFile[lib];
