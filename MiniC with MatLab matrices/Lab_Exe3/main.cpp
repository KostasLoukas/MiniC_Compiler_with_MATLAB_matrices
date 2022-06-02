#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Grammar.tab.h"
#include "STNode.h"


extern FILE* yyin;

using namespace std;



int main (int argc, char *argv[])
{
	fopen_s(&yyin, "input.txt", "r");
	if (yyin==NULL)
	{
		printf("Could not open input file!\n");
		exit(1);
	}
	

	yy::parser* p = new yy::parser();
	
	p->parse();

	
	ofstream* f = new ofstream("stree.dot", ofstream::out);

	g_root->Visit_SyntaxTreePrinter(f, nullptr);

	system("dot -Tgif stree.dot -o stree.dot.gif");

	g_root->Visit_GetArrayType(nullptr);
	g_root->Visit_Eval(nullptr);


	
	return 0;
}