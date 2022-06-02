%option noyywrap


%{
	#define ECHO  //Για να μην πεταγονται τα σκουπιδια στο output

	#include "Grammar.tab.h"

	#include "SymbolNodes.h"  //so that the class used to create new node (NUMBER) for the tree is visible

	#include "SymbolTable.h"  //for the GetInitValue() function

	#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
	
	typedef yy::parser::token token;
	
%}





%%


"if" { return token::IF; }

"else" { return token::ELSE; }

"while" { return token::WHILE; }

"break" { return token::BREAK; }

"{" { return '{'; }

"}" { return '}'; }

"[" { return '['; }

"]" { return ']'; }

"," { return ','; }

"==" { return token::EQUAL; }

"!=" { return token::NON_EQUAL; }

"=" { return '='; }

"&&" { return token::LOGICAL_AND; }

"||" { return token::LOGICAL_OR; }

"!" { return token::LOGICAL_NOT; }

">" { return token::GREATER_THAN; }

">=" { return token::GREATER_THAN_EQUAL; }

"<" { return token::LESS_THAN; }

"<=" { return token::LESS_THAN_EQUAL; }

"&" { return '&'; }

"|" { return '|'; }

"~" { return '~'; }

"^" { return '^'; }

"<<" { return token::SHIFT_LEFT; }

">>" { return token::SHIFT_RIGHT; }

"+" { return '+'; }

"-" { return '-'; }

"*" { return '*'; }

"/" { return '/'; }

"%" { return '%'; }

"++" { return token::POSTFIX_INCREMENT; }

"--" { return token::POSTFIX_DECREMENT; }

"(" { return '('; }

")" { return ')'; }

";" { return ';'; }




0|[1-9][0-9]* { yylval->node = new CNUMBER(yytext);
				return token::NUMBER; }

[a-zA-Z][a-zA-Z0-9_]* { yylval->node = g_symbolTable.GetIdentifier(yytext);
						return token::IDENTIFIER; }


[ \t]
[\r\n]




%%


