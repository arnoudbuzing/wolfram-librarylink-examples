Needs["CCompilerDriver`"];
lib = CreateLibrary[{"Greetings.c"},"Greetings"];
Greetings = LibraryFunctionLoad[lib,"Greetings",{"UTF8String"},"UTF8String"];
