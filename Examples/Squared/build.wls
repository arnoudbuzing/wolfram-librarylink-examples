Needs["CCompilerDriver`"];
lib = CreateLibrary[{"Squared.cpp"},"Squared"];
Squared = LibraryFunctionLoad[lib,"Squared",{Integer},Integer];
