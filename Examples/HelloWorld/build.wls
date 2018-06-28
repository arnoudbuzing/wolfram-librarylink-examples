Needs["CCompilerDriver`"];
lib = CreateLibrary[{"HelloWorld.c"},"HelloWorld"];
HelloWorld = LibraryFunctionLoad[lib,"HelloWorld",{},"UTF8String"];
