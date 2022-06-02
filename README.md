# MiniC Compiler with MATLAB matrices
This compiler generates the syntax tree for MiniC inputs as well as MATLAB's matrices (according to its syntax).
It also implements MiniC parts (if-else, while and break structures) and
mathematical operations of the tables from the MATLAB tool. The tables are declared as is (e.g.
A = [1,2,3] where A is a table of three elements and its elements
are in order 1, 2 and 3). You can add, subtract and multiply the forementioned tables.
Furthermore, the program supports the storaging of variables with identifier (e.g. var = 1
where var is the name of the variable and 1 is its value) 
and the operations of addition, subtraction and multiplication
of these variables with arrays (in any order those may appear). 
The operations between the numbers/variables that are supported are (with C++ symbolism):
+, -, *, /,%, ++, -, &&, ||,!,>,> =, ==, <, <=,! =, &, |, ~, ^, << and >>.

To run this solution/project, you would need Visual Studio 2017 or higher, FlexBison installed on your C:\ drive and Graphviz.

The input.txt file is the input commands that the compiler will process (i.e. the MiniC and/or MATLAB expressions mentioned earlier).
