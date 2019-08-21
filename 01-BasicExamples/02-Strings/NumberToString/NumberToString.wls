(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name = "NumberToString";

Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
dtoa = LibraryFunctionLoad[lib,"wolfram_dtoa",{Real},"UTF8String"];
Print[ "Answer: ", dtoa[2.332] ];
LibraryUnload[lib];
DeleteFile[lib];
