(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name = "EchoRawArray";

Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
EchoRawArray = LibraryFunctionLoad[lib,name,{RawArray},RawArray];
Print["EchoRawArray[ RawArray[\"Integer8\", {1, 2, 3}] ]: ", EchoRawArray[ RawArray["Integer8", {1,2,3}]]];
LibraryUnload[lib];
DeleteFile[lib];
