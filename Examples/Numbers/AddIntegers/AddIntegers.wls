(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

Needs["CCompilerDriver`"];
lib = CreateLibrary[{"AddIntegers.cpp"},"AddIntegers"];
Print[lib];
AddIntegers = LibraryFunctionLoad[lib,"AddIntegers",{Integer,Integer},Integer];
Print["AddIntegers[3,4]: ", AddIntegers[3,4]];
LibraryUnload[lib];
DeleteFile[lib];
