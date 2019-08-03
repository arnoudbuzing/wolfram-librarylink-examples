(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name = "StringToNumber";

Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
strtol = LibraryFunctionLoad[lib,"wolfram_strtol",{"UTF8String",Integer},Integer];
strtod = LibraryFunctionLoad[lib,"wolfram_strtod",{"UTF8String"},Real];
Print[ strtol["104",10] ];
Print[ strtod["10e4"] ];
LibraryUnload[lib];
DeleteFile[lib];
