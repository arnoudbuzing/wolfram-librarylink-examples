(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name="Objects";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{"Objects.cpp", "Rectangle.cpp"},name];
Print[lib];
set = LibraryFunctionLoad[lib,"set",{Integer,Integer},"Void"];
getW = LibraryFunctionLoad[lib,"get_w",{},Integer];
getH = LibraryFunctionLoad[lib,"get_h",{},Integer];
compute = LibraryFunctionLoad[lib,"compute",{},Integer];

Print["set[3,4]: ", set[3,4]];
Print["getW[]: ", getW[]];
Print["getH[]: ", getH[]];
Print["compute[]: ", compute[]];
LibraryUnload[lib];
DeleteFile[lib];
