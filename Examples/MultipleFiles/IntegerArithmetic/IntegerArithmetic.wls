(* Wolfram Language script to build and test library using CCompilerDriver paclet *)

name = "IntegerArithmetic";
Needs["CCompilerDriver`"];
lib = CreateLibrary[{"Initialize.cpp","Add.cpp","Multiply.cpp"},name];
Print[lib];
addIntegers = LibraryFunctionLoad[lib,"AddIntegers",{Integer,Integer},Integer];
multiplyIntegers = LibraryFunctionLoad[lib,"MultiplyIntegers",{Integer,Integer},Integer];
Print["addIntegers[3,4]: ", addIntegers[3,4]];
Print["multiplyIntegers[3,4]: ", multiplyIntegers[3,4]];
LibraryUnload[lib];
DeleteFile[lib];
