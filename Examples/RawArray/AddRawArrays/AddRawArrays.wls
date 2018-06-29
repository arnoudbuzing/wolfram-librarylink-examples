(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name = "AddRawArrays";

Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
AddRawArrays = LibraryFunctionLoad[lib,name,{RawArray,RawArray},RawArray];
Print["AddRawArrays[...]: ", AddRawArrays[ RawArray["UnsignedInteger8",{1,2,3}], RawArray["UnsignedInteger8",{1,2,3}]]];
LibraryUnload[lib];
DeleteFile[lib];
