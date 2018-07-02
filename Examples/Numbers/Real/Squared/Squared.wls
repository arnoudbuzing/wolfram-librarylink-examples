(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

Needs["CCompilerDriver`"];
lib = CreateLibrary[{"Squared.cpp"},"Squared"];
Print[lib];
Squared = LibraryFunctionLoad[lib,"Squared",{Integer},Integer];
Print["Squared[5]: ", Squared[5]];
LibraryUnload[lib];
DeleteFile[lib];
