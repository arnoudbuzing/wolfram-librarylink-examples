(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

Needs["CCompilerDriver`"];
lib = CreateLibrary[{"Greetings.cpp"},"Greetings"];
Print[lib];
Greetings = LibraryFunctionLoad[lib,"Greetings",{"UTF8String"},"UTF8String"];
Print["Greetings[\"Arnoud\"]: ", Greetings["Arnoud"]];
LibraryUnload[lib];
DeleteFile[lib];
