(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name="Multiplication";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
Multiplication = LibraryFunctionLoad[lib,"Multiplication",{Complex,Complex},Complex];
Print["Multiplication[3+4I,5+6I]: ", Multiplication[3+4I,5+6I]];
LibraryUnload[lib];
DeleteFile[lib];
