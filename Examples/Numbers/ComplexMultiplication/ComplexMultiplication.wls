(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name="ComplexMultiplication";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{name<>".cpp"},name];
Print[lib];
ComplexMultiplication = LibraryFunctionLoad[lib,"ComplexMultiplication",{Complex,Complex},Complex];
Print["ComplexMultiplication[...]: ", ComplexMultiplication[3+4I,5+6I]];
LibraryUnload[lib];
DeleteFile[lib];
