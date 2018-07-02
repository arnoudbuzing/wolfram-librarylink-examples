(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name="Addition";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
Addition = LibraryFunctionLoad[lib,name,{Integer,Integer},Integer];
Print["Addition[3,4]: ", Addition[3,4]];
LibraryUnload[lib];
DeleteFile[lib];
