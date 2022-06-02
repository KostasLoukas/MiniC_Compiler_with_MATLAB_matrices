%language "C++"


%{
	#include "Grammar.tab.h"

	#include "SymbolNodes.h"  //so that the classes used to create new nodes for the tree are visible

	extern int yylex(yy::parser::semantic_type *yylval);

	

%}



%code requires
{
	#include "STNode.h"   //so that we can use the STNode type for the *node
	
	

}




%union
{
	STNode *node;
	
	

}







%start calculator


%type <node> calculator statements statement expression if_statement compound_statement statement_list while_statement array elements element


%token <node> NUMBER IDENTIFIER
%token IF ELSE WHILE BREAK



 //C's operators precedence is taken into account

%nonassoc IFPREC
%right '='
%left LOGICAL_AND LOGICAL_OR
%left '&' '|' '^'
%left GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL EQUAL NON_EQUAL
%left SHIFT_LEFT SHIFT_RIGHT
%left '+' '-'
%left '*' '/' '%'
%nonassoc ELSE
%right '~'
%right LOGICAL_NOT
%left POSTFIX_INCREMENT POSTFIX_DECREMENT







%%


calculator : statements  { g_root = $$ = new CCalculator();
						   $$->AddChild($1); }
		   ;





statements : statement			{ $$ = new CStatements();
								  $$->AddChild($1); }
		| statements statement  { $$ = new CStatements();
								  $$->AddChild($1);
								  $$->AddChild($2); }
		;





statement : expression ';'  { $$ = new CStatement();
							  $$->AddChild($1); }
		| ';'				{ $$ = new CStatement(); }          //Εδω επιτρεπουμε την εισαγωγη κενης εκφρασης
		| compound_statement
		| if_statement
		| while_statement
		| BREAK ';'         { $$ = new CBreak(); }
		;





if_statement : IF '(' expression ')' statement %prec IFPREC    { $$ = new CIf(); 
																 $$->AddChild($3);
																 $$->AddChild($5); }
			 | IF '(' expression ')' statement ELSE statement  { $$ = new CIf();
																 $$->AddChild($3);
																 $$->AddChild($5);
																 $$->AddChild($7); }
			 ;




while_statement : WHILE '(' expression ')' statement  { $$ = new CWhile();
														$$->AddChild($3);
														$$->AddChild($5); }
				;




compound_statement : '{' '}'				   { $$ = new CCompound_Statement(); }
				   | '{' statement_list '}'    { $$ = new CCompound_Statement();
												 $$->AddChild($2); }
				   ;




statement_list : statement					{ $$ = new CStatement_List(); 
											  $$->AddChild($1); }
			   | statement_list statement	{ $$ = new CStatement_List();
											  $$->AddChild($1); 
											  $$->AddChild($2); }
			   ;


expression : NUMBER
			| IDENTIFIER
			| array
			| IDENTIFIER '=' expression { $$ = new CAssignment(); 
										  $$->AddChild($1);
										  $$->AddChild($3); }
			| '(' expression ')'		{ $$ = $2; }    //Δεν τις θεωρουμε ως κομβους του δεντρου, αλλα η προτεραιοτητα αποδιδεται κανονικα
			| expression LOGICAL_AND expression { $$ = new CLogical_And();
												  $$->AddChild($1);
												  $$->AddChild($3); }
			| expression LOGICAL_OR expression { $$ = new CLogical_Or();
												 $$->AddChild($1);
												 $$->AddChild($3); }
			| LOGICAL_NOT expression	{ $$ = new CLogical_Not();
										  $$->AddChild($2); }
			| expression GREATER_THAN expression { $$ = new CGreater_Than();
												   $$->AddChild($1);
												   $$->AddChild($3); }
			| expression GREATER_THAN_EQUAL expression { $$ = new CGreater_Than_Equal();
														 $$->AddChild($1);
														 $$->AddChild($3); }
			| expression LESS_THAN expression { $$ = new CLess_Than();
												$$->AddChild($1);
												$$->AddChild($3); }
			| expression LESS_THAN_EQUAL expression { $$ = new CLess_Than_Equal();
													  $$->AddChild($1);
													  $$->AddChild($3); }
			| expression EQUAL expression { $$ = new CEqual();
											$$->AddChild($1);
											$$->AddChild($3); }
			| expression NON_EQUAL expression { $$ = new CNon_Equal();
												$$->AddChild($1);
												$$->AddChild($3); }
			| expression '&' expression { $$ = new CBitwise_And();
										  $$->AddChild($1);
										  $$->AddChild($3); }
			| expression '|' expression { $$ = new CBitwise_Or();
										  $$->AddChild($1);
										  $$->AddChild($3); }
			| '~' expression			{ $$ = new CBitwise_Not();
										  $$->AddChild($2); }
			| expression '^' expression { $$ = new CBitwise_Xor();
										  $$->AddChild($1);
										  $$->AddChild($3); }
			| expression SHIFT_LEFT expression { $$ = new CShift_Left();
												 $$->AddChild($1);
												 $$->AddChild($3); }
			| expression SHIFT_RIGHT expression { $$ = new CShift_Right();
												  $$->AddChild($1);
												  $$->AddChild($3); }
			| expression '+' expression { $$ = new CAddition();
										  $$->AddChild($1);
										  $$->AddChild($3); }
			| expression '-' expression { $$ = new CSubtraction();
										  $$->AddChild($1);
										  $$->AddChild($3); }
			| expression '*' expression { $$ = new CMultiplication();
										  $$->AddChild($1);
										  $$->AddChild($3); }
			| expression '/' expression { if($3==0){printf("ERROR! Could not divide with zero!\n"); exit(1);} else{ $$ = new CDivision();
																													$$->AddChild($1);
																													$$->AddChild($3); } }   //Το προγραμμα θα πεταξει μηνυμα λαθους για προσπαθεια διαιρεσης με το μηδεν και θα τερματισει
			| expression '%' expression { $$ = new CModulo();
										  $$->AddChild($1);
										  $$->AddChild($3); }
			| expression POSTFIX_INCREMENT { $$ = new CPostfix_Increment();
											 $$->AddChild($1); }
			| expression POSTFIX_DECREMENT { $$ = new CPostfix_Decrement();
											 $$->AddChild($1); }
			;



array : '[' elements ']'		{ $$ = new CArray();
								  $$->AddChild($2); }
	  | '[' ']'					{ $$ = new CArray(); }
	  ;



elements : element				{ $$ = new CElements(); 
								  $$->AddChild($1); }
		 | elements ',' element { $$ = new CElements();
								  $$->AddChild($1);
								  $$->AddChild($3); }
		 ;


element : expression { $$=new CElement();
					   $$->AddChild($1); }







%%


//Η συναρτηση error του parser
namespace yy
{
	void parser::error (const location_type& loc, const std::string& msg)
	{
		std::cerr << "WARNING! Error at " << loc << ": " << msg << std::endl;

	}

}