(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name = "ReverseString";

Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
ReverseString = LibraryFunctionLoad[lib,name,{"UTF8String"},"UTF8String"];
Print["ReverseString[\"hello\"]: ", ReverseString["hello"]];
LibraryUnload[lib];
DeleteFile[lib];
