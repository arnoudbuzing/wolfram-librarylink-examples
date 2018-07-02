# HelloWorld

This example shows how to return the string "Hello World" from a `LibraryLink` library
to the Wolfram Language.

The Wolfram Language function arguments are passed in as a list expression: `{ arg1, arg2, ... }`

To keep the WSTP link in sync, the C/C++ code must first read in this entire list expression.

In this simple case, there are no arguments, so we're dealing with an empty list `{}`. This can be read off the WSTP link with the `MLCheckFunction` function.

In general the code pattern is:

1. Read the entire WSTP argument list expression.
2. Execute the code functionality the C/C++ code is supposed to provide.
3. Construct a WSTP expression that is returned to the Wolfram Language.
