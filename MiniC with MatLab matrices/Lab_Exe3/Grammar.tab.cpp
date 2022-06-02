/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */
/* Line 279 of lalr1.cc  */
#line 4 "Grammar.y"

	#include "Grammar.tab.h"

	#include "SymbolNodes.h"  //so that the classes used to create new nodes for the tree are visible

	extern int yylex(yy::parser::semantic_type *yylval);

	


/* Line 279 of lalr1.cc  */
#line 49 "Grammar.tab.cpp"


#include "Grammar.tab.h"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 57 "Grammar.tab.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
/* Line 353 of lalr1.cc  */
#line 152 "Grammar.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 77 "Grammar.y"
    { g_root = (yyval.node) = new CCalculator();
						   (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 85 "Grammar.y"
    { (yyval.node) = new CStatements();
								  (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 87 "Grammar.y"
    { (yyval.node) = new CStatements();
								  (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node));
								  (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 96 "Grammar.y"
    { (yyval.node) = new CStatement();
							  (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); }
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 98 "Grammar.y"
    { (yyval.node) = new CStatement(); }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 102 "Grammar.y"
    { (yyval.node) = new CBreak(); }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 109 "Grammar.y"
    { (yyval.node) = new CIf(); 
																 (yyval.node)->AddChild((yysemantic_stack_[(5) - (3)].node));
																 (yyval.node)->AddChild((yysemantic_stack_[(5) - (5)].node)); }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 112 "Grammar.y"
    { (yyval.node) = new CIf();
																 (yyval.node)->AddChild((yysemantic_stack_[(7) - (3)].node));
																 (yyval.node)->AddChild((yysemantic_stack_[(7) - (5)].node));
																 (yyval.node)->AddChild((yysemantic_stack_[(7) - (7)].node)); }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 121 "Grammar.y"
    { (yyval.node) = new CWhile();
														(yyval.node)->AddChild((yysemantic_stack_[(5) - (3)].node));
														(yyval.node)->AddChild((yysemantic_stack_[(5) - (5)].node)); }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 129 "Grammar.y"
    { (yyval.node) = new CCompound_Statement(); }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 130 "Grammar.y"
    { (yyval.node) = new CCompound_Statement();
												 (yyval.node)->AddChild((yysemantic_stack_[(3) - (2)].node)); }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 137 "Grammar.y"
    { (yyval.node) = new CStatement_List(); 
											  (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 139 "Grammar.y"
    { (yyval.node) = new CStatement_List();
											  (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); 
											  (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 148 "Grammar.y"
    { (yyval.node) = new CAssignment(); 
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 151 "Grammar.y"
    { (yyval.node) = (yysemantic_stack_[(3) - (2)].node); }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 152 "Grammar.y"
    { (yyval.node) = new CLogical_And();
												  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
												  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 155 "Grammar.y"
    { (yyval.node) = new CLogical_Or();
												 (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
												 (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 158 "Grammar.y"
    { (yyval.node) = new CLogical_Not();
										  (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 160 "Grammar.y"
    { (yyval.node) = new CGreater_Than();
												   (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
												   (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 163 "Grammar.y"
    { (yyval.node) = new CGreater_Than_Equal();
														 (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
														 (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 166 "Grammar.y"
    { (yyval.node) = new CLess_Than();
												(yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
												(yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 169 "Grammar.y"
    { (yyval.node) = new CLess_Than_Equal();
													  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
													  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 172 "Grammar.y"
    { (yyval.node) = new CEqual();
											(yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
											(yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 175 "Grammar.y"
    { (yyval.node) = new CNon_Equal();
												(yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
												(yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 178 "Grammar.y"
    { (yyval.node) = new CBitwise_And();
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 181 "Grammar.y"
    { (yyval.node) = new CBitwise_Or();
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 184 "Grammar.y"
    { (yyval.node) = new CBitwise_Not();
										  (yyval.node)->AddChild((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 186 "Grammar.y"
    { (yyval.node) = new CBitwise_Xor();
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 189 "Grammar.y"
    { (yyval.node) = new CShift_Left();
												 (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
												 (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 192 "Grammar.y"
    { (yyval.node) = new CShift_Right();
												  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
												  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 195 "Grammar.y"
    { (yyval.node) = new CAddition();
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 198 "Grammar.y"
    { (yyval.node) = new CSubtraction();
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 201 "Grammar.y"
    { (yyval.node) = new CMultiplication();
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 204 "Grammar.y"
    { if((yysemantic_stack_[(3) - (3)].node)==0){printf("ERROR! Could not divide with zero!\n"); exit(1);} else{ (yyval.node) = new CDivision();
																													(yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
																													(yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); } }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 207 "Grammar.y"
    { (yyval.node) = new CModulo();
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
										  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 210 "Grammar.y"
    { (yyval.node) = new CPostfix_Increment();
											 (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 212 "Grammar.y"
    { (yyval.node) = new CPostfix_Decrement();
											 (yyval.node)->AddChild((yysemantic_stack_[(2) - (1)].node)); }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 218 "Grammar.y"
    { (yyval.node) = new CArray();
								  (yyval.node)->AddChild((yysemantic_stack_[(3) - (2)].node)); }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 220 "Grammar.y"
    { (yyval.node) = new CArray(); }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 225 "Grammar.y"
    { (yyval.node) = new CElements(); 
								  (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 227 "Grammar.y"
    { (yyval.node) = new CElements();
								  (yyval.node)->AddChild((yysemantic_stack_[(3) - (1)].node));
								  (yyval.node)->AddChild((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 233 "Grammar.y"
    { (yyval.node)=new CElement();
					   (yyval.node)->AddChild((yysemantic_stack_[(1) - (1)].node)); }
    break;


/* Line 670 of lalr1.cc  */
#line 738 "Grammar.tab.cpp"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
          }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char parser::yypact_ninf_ = -30;
  const short int
  parser::yypact_[] =
  {
        96,   -30,     4,   -29,   -16,    -3,    78,    78,   -30,    78,
      50,    22,    29,    96,   -30,   -30,   -30,   -30,   199,   -30,
      78,    78,    78,   -30,   -21,   -21,   124,   -30,   -30,    60,
     -30,   222,    10,   -30,   -30,   -30,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,   -30,   -30,   -30,   222,   149,   174,
     -30,   -30,   -30,   -30,    78,   242,   242,   259,   259,   259,
     270,   270,   270,   270,   270,   270,    -4,    -4,   -19,   -19,
     -21,   -21,   -21,    96,    96,   -30,    56,   -30,    96,   -30
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,    18,    19,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     2,     3,     8,     9,     7,     0,    20,
       0,     0,     0,    10,    34,    25,     0,    14,    16,     0,
      46,    49,     0,    47,     1,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    43,     5,    21,     0,     0,
      22,    15,    17,    45,     0,    24,    23,    32,    33,    35,
      31,    30,    29,    28,    27,    26,    37,    36,    38,    39,
      40,    41,    42,     0,     0,    48,    11,    13,     0,    12
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  parser::yypgoto_[] =
  {
       -30,   -30,   -30,   -10,   -30,   -30,   -30,   -30,    -5,   -30,
     -30,     2
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,    12,    13,    14,    15,    16,    17,    29,    18,    19,
      32,    33
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -1;
  const unsigned char
  parser::yytable_[] =
  {
        28,    24,    25,    35,    26,    21,    31,    51,    52,    53,
      54,    55,    54,    55,    20,    57,    58,    59,    22,    62,
      49,    50,    51,    52,    53,     1,     2,    54,    55,    34,
      23,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    63,
      64,     6,     7,     1,     2,     3,     9,     4,     5,    31,
      11,    30,    88,     1,     2,     3,    85,     4,     5,     0,
       0,     0,     0,    86,    87,     0,     0,     0,    89,     6,
       7,     1,     2,     8,     9,     0,    10,    27,    11,     6,
       7,     0,     0,     8,     9,     0,    10,    61,    11,     1,
       2,     3,     0,     4,     5,     0,     0,     6,     7,     0,
       0,     0,     9,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,     8,
       9,     0,    10,     0,    11,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,    54,    55,     0,     0,    60,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,    55,     0,     0,    83,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,    54,    55,     0,     0,    84,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,    55,    56,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,    54,    55,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,    54,    55,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,    55,    47,    48,    49,    50,    51,    52,    53,     0,
       0,    54,    55
  };

  /* YYCHECK.  */
  const signed char
  parser::yycheck_[] =
  {
        10,     6,     7,    13,     9,    34,    11,    26,    27,    28,
      31,    32,    31,    32,    10,    20,    21,    22,    34,    29,
      24,    25,    26,    27,    28,     3,     4,    31,    32,     0,
      33,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    39,
      40,    29,    30,     3,     4,     5,    34,     7,     8,    64,
      38,    39,     6,     3,     4,     5,    64,     7,     8,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    88,    29,
      30,     3,     4,    33,    34,    -1,    36,    37,    38,    29,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    29,    30,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    -1,    36,    -1,    38,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    -1,    -1,    35,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    -1,    -1,    35,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    -1,    -1,    35,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,     3,     4,     5,     7,     8,    29,    30,    33,    34,
      36,    38,    42,    43,    44,    45,    46,    47,    49,    50,
      10,    34,    34,    33,    49,    49,    49,    37,    44,    48,
      39,    49,    51,    52,     0,    44,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    31,    32,    33,    49,    49,    49,
      35,    37,    44,    39,    40,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    35,    35,    52,    44,    44,     6,    44
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      61,   265,   266,    38,   124,    94,   267,   268,   269,   270,
     271,   272,   273,   274,    43,    45,    42,    47,    37,   126,
     275,   276,   277,    59,    40,    41,   123,   125,    91,    93,
      44
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    45,    45,    46,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    51,    52
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     5,     7,     5,     2,     3,     1,     2,     1,     1,
       1,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     2,     1,     3,     1
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMBER", "IDENTIFIER", "IF", "ELSE",
  "WHILE", "BREAK", "IFPREC", "'='", "LOGICAL_OR", "LOGICAL_AND", "'&'",
  "'|'", "'^'", "NON_EQUAL", "EQUAL", "LESS_THAN_EQUAL", "LESS_THAN",
  "GREATER_THAN_EQUAL", "GREATER_THAN", "SHIFT_RIGHT", "SHIFT_LEFT", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'~'", "LOGICAL_NOT", "POSTFIX_DECREMENT",
  "POSTFIX_INCREMENT", "';'", "'('", "')'", "'{'", "'}'", "'['", "']'",
  "','", "$accept", "calculator", "statements", "statement",
  "if_statement", "while_statement", "compound_statement",
  "statement_list", "expression", "array", "elements", "element", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        42,     0,    -1,    43,    -1,    44,    -1,    43,    44,    -1,
      49,    33,    -1,    33,    -1,    47,    -1,    45,    -1,    46,
      -1,     8,    33,    -1,     5,    34,    49,    35,    44,    -1,
       5,    34,    49,    35,    44,     6,    44,    -1,     7,    34,
      49,    35,    44,    -1,    36,    37,    -1,    36,    48,    37,
      -1,    44,    -1,    48,    44,    -1,     3,    -1,     4,    -1,
      50,    -1,     4,    10,    49,    -1,    34,    49,    35,    -1,
      49,    12,    49,    -1,    49,    11,    49,    -1,    30,    49,
      -1,    49,    21,    49,    -1,    49,    20,    49,    -1,    49,
      19,    49,    -1,    49,    18,    49,    -1,    49,    17,    49,
      -1,    49,    16,    49,    -1,    49,    13,    49,    -1,    49,
      14,    49,    -1,    29,    49,    -1,    49,    15,    49,    -1,
      49,    23,    49,    -1,    49,    22,    49,    -1,    49,    24,
      49,    -1,    49,    25,    49,    -1,    49,    26,    49,    -1,
      49,    27,    49,    -1,    49,    28,    49,    -1,    49,    32,
      -1,    49,    31,    -1,    38,    51,    39,    -1,    38,    39,
      -1,    52,    -1,    51,    40,    52,    -1,    49,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,    10,    13,    15,    17,    19,
      21,    24,    30,    38,    44,    47,    51,    53,    56,    58,
      60,    62,    66,    70,    74,    78,    81,    85,    89,    93,
      97,   101,   105,   109,   113,   116,   120,   124,   128,   132,
     136,   140,   144,   148,   151,   154,   158,   161,   163,   167
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  parser::yyrline_[] =
  {
         0,    77,    77,    85,    87,    96,    98,    99,   100,   101,
     102,   109,   112,   121,   129,   130,   137,   139,   145,   146,
     147,   148,   151,   152,   155,   158,   160,   163,   166,   169,
     172,   175,   178,   181,   184,   186,   189,   192,   195,   198,
     201,   204,   207,   210,   212,   218,   220,   225,   227,   233
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    28,    13,     2,
      34,    35,    26,    24,    40,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    10,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    15,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,    14,    37,    29,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    11,    12,    16,    17,    18,
      19,    20,    21,    22,    23,    30,    31,    32
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 302;
  const int parser::yynnts_ = 12;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 34;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 41;

  const unsigned int parser::yyuser_token_number_max_ = 277;
  const parser::token_number_type parser::yyundef_token_ = 2;


} // yy
/* Line 1141 of lalr1.cc  */
#line 1278 "Grammar.tab.cpp"
/* Line 1142 of lalr1.cc  */
#line 242 "Grammar.y"



//Η συναρτηση error του parser
namespace yy
{
	void parser::error (const location_type& loc, const std::string& msg)
	{
		std::cerr << "WARNING! Error at " << loc << ": " << msg << std::endl;

	}

}