Needs["CCompilerDriver`"];
lib = CreateLibrary[{"DoNothing.c"},"DoNothing"];
DoNothing = LibraryFunctionLoad[lib,"DoNothing",{},"Void"];
