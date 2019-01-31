#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 1 "crowbar.y"

#include <stdio.h>
#include "crowbar.h"
#define YYDEBUG 1
#line 6 "crowbar.y"
typedef union {
    char                *identifier;
    ParameterList       *parameter_list;
    ArgumentList        *argument_list;
    Expression          *expression;
    Statement           *statement;
    StatementList       *statement_list;
    Block               *block;
    Elsif               *elsif;
    IdentifierList      *identifier_list;
} YYSTYPE;
#line 40 "y.tab.c"
#define INT_LITERAL 257
#define DOUBLE_LITERAL 258
#define STRING_LITERAL 259
#define IDENTIFIER 260
#define FUNCTION 261
#define IF 262
#define ELSE 263
#define ELSIF 264
#define WHILE 265
#define FOR 266
#define RETURN_T 267
#define BREAK 268
#define CONTINUE 269
#define NULL_T 270
#define LP 271
#define RP 272
#define LC 273
#define RC 274
#define SEMICOLON 275
#define COMMA 276
#define ASSIGN 277
#define LOGICAL_AND 278
#define LOGICAL_OR 279
#define EQ 280
#define NE 281
#define GT 282
#define GE 283
#define LT 284
#define LE 285
#define ADD 286
#define SUB 287
#define MUL 288
#define DIV 289
#define MOD 290
#define TRUE_T 291
#define FALSE_T 292
#define GLOBAL_T 293
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,   26,   26,   27,   27,    1,    1,    2,    2,
   21,   21,    3,    3,    6,    6,    5,    5,    7,    7,
    7,    8,    8,    8,    8,    8,    9,    9,    9,   10,
   10,   10,   10,   11,   11,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   13,   13,   13,   13,   13,
   13,   13,   13,   14,   25,   25,   15,   15,   15,   15,
   24,   24,   23,   16,   17,    4,    4,   18,   19,   20,
   22,   22,
};
short yylen[] = {                                         2,
    1,    2,    1,    1,    6,    5,    1,    3,    1,    3,
    1,    2,    1,    3,    1,    3,    1,    3,    1,    3,
    3,    1,    3,    3,    3,    3,    1,    3,    3,    1,
    3,    3,    3,    1,    2,    4,    3,    3,    1,    1,
    1,    1,    1,    1,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    3,    5,    7,    6,    8,
    1,    2,    5,    5,    9,    0,    1,    3,    2,    2,
    3,    2,
};
short yydefred[] = {                                      0,
   40,   41,   42,    0,    0,    0,    0,    0,    0,    0,
    0,   45,    0,    0,   43,   44,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,   34,    4,   47,   48,
   49,   50,   51,   52,   53,    1,    3,    0,    0,    0,
    0,    0,    0,   67,    0,   69,   70,    0,    0,   35,
   55,    0,    2,   46,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   37,    0,    9,
   14,    0,    0,    0,    0,   68,   38,   54,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   31,
   32,   33,   36,    0,    7,    0,    0,    0,    0,    0,
   56,   10,    0,    6,    0,    0,    0,   64,    0,   72,
   11,    0,    5,    8,    0,    0,   61,    0,    0,   71,
   12,   58,    0,    0,   62,    0,    0,   60,    0,    0,
   65,   63,
};
short yydgoto[] = {                                      18,
   97,   69,   19,   45,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   30,   31,   32,   33,   34,   35,
  112,  104,  117,  118,   52,   36,   37,
};
short yysindex[] = {                                   -252,
    0,    0,    0, -250, -248, -249, -243, -227, -234, -228,
 -223,    0, -234, -118,    0,    0, -196, -252, -194, -199,
 -181, -214,  -29, -165,   96,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -124, -234, -158,
 -234, -234, -234,    0, -156,    0,    0, -112, -105,    0,
    0, -145,    0,    0, -118, -118, -118, -118, -118, -118,
 -118, -118, -118, -118, -118, -118, -118,    0, -179,    0,
    0, -229, -102, -101, -121,    0,    0,    0,  -83, -214,
 -199,  -29,  -29, -165, -165, -165, -165,   96,   96,    0,
    0,    0,    0, -234,    0,  -80, -172,  -80,  -80, -234,
    0,    0, -197,    0,  -80,  -68, -126,    0,  -79,    0,
    0, -142,    0,    0,  -80,  -63,    0, -120, -234,    0,
    0,    0, -234,  -80,    0,  -60,  -48,    0,  -80,  -80,
    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -100,    0,    0,    0,    0,  -66,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   98,
 -173, -167, -230,  -33,  -81,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -66,    0,    0,    0,    0,    0, -100,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -117,
  100, -192,   88,    2,   39,   60,   74,  -65,  -49,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -66,
    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   38,  -47,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
    0,    0,   -9,  -41,  172,    0,  185,   99,  321,  101,
  -11,    0,  -92,    0,    0,    0,    0,    0,    0,    0,
    0,  -23,  123,    0,    0,  226,    0,
};
#define YYTABLESIZE 386
short yytable[] = {                                      44,
   57,   75,   50,   48,    1,    2,    3,    4,    5,    6,
  111,   40,    7,    8,    9,   10,   11,   12,   13,  121,
   38,   41,    1,    2,    3,    4,   39,   42,   70,   71,
   95,   73,   74,   44,   14,   12,   13,   59,   15,   16,
   17,   19,   96,   43,   19,   19,   46,   19,   19,   19,
   19,   47,   14,   90,   91,   92,   15,   16,  109,    1,
    2,    3,    4,   51,    6,   57,   58,    7,    8,    9,
   10,   11,   12,   13,  107,  108,  110,  126,   55,   20,
   54,  113,   20,   20,  102,   20,   20,   20,   20,   14,
   44,  122,   93,   15,   16,   17,   94,   56,   13,  105,
  128,   13,   13,  106,   17,  131,  132,   17,   17,   44,
   17,   17,   72,  127,    1,    2,    3,    4,   76,    6,
   63,   64,    7,    8,    9,   10,   11,   12,   13,   78,
   79,  120,    1,    2,    3,    4,  115,  116,    1,    2,
    3,   49,  124,  116,   14,   12,   13,   68,   15,   16,
   17,   12,   13,  100,   18,   82,   83,   18,   18,   77,
   18,   18,   14,   88,   89,   38,   15,   16,   14,   98,
   99,   39,   15,   16,   39,   39,  101,   39,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   27,  114,  103,   27,   27,  119,   27,   27,   27,   27,
   27,   27,   27,   27,   27,   27,   28,  123,   66,   28,
   28,  129,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   29,  130,   66,   29,   29,   81,   29,   29,
   29,   29,   29,   29,   29,   29,   29,   29,   22,   80,
  125,   22,   22,   53,   22,   22,   22,   22,   22,   22,
   22,   22,   59,   60,   61,   62,    0,   57,   57,   57,
   57,   57,   57,    0,    0,   57,   57,   57,   57,   57,
   57,   57,    0,   23,   57,    0,   23,   23,    0,   23,
   23,   23,   23,   23,   23,   23,   23,   57,    0,    0,
    0,   57,   57,   57,   59,   59,   59,   59,   59,   59,
    0,    0,   59,   59,   59,   59,   59,   59,   59,    0,
   24,   59,    0,   24,   24,    0,   24,   24,   24,   24,
   24,   24,   24,   24,   59,    0,    0,    0,   59,   59,
   59,   25,    0,    0,   25,   25,    0,   25,   25,   25,
   25,   25,   25,   25,   25,   26,    0,    0,   26,   26,
    0,   26,   26,   26,   26,   26,   26,   26,   26,   21,
    0,    0,   21,   21,    0,   21,   21,   21,   21,   15,
    0,   16,   15,   15,   16,   16,   15,    0,   16,   84,
   85,   86,   87,   65,   66,   67,
};
short yycheck[] = {                                       9,
    0,   43,   14,   13,  257,  258,  259,  260,  261,  262,
  103,  260,  265,  266,  267,  268,  269,  270,  271,  112,
  271,  271,  257,  258,  259,  260,  277,  271,   38,   39,
  260,   41,   42,   43,  287,  270,  271,    0,  291,  292,
  293,  272,  272,  271,  275,  276,  275,  278,  279,  280,
  281,  275,  287,   65,   66,   67,  291,  292,  100,  257,
  258,  259,  260,  260,  262,  280,  281,  265,  266,  267,
  268,  269,  270,  271,   98,   99,  274,  119,  278,  272,
  275,  105,  275,  276,   94,  278,  279,  280,  281,  287,
  100,  115,  272,  291,  292,  293,  276,  279,  272,  272,
  124,  275,  276,  276,  272,  129,  130,  275,  276,  119,
  278,  279,  271,  123,  257,  258,  259,  260,  275,  262,
  286,  287,  265,  266,  267,  268,  269,  270,  271,  275,
  276,  274,  257,  258,  259,  260,  263,  264,  257,  258,
  259,  260,  263,  264,  287,  270,  271,  272,  291,  292,
  293,  270,  271,  275,  272,   57,   58,  275,  276,  272,
  278,  279,  287,   63,   64,  271,  291,  292,  287,  272,
  272,  272,  291,  292,  275,  276,  260,  278,  279,  280,
  281,  282,  283,  284,  285,  286,  287,  288,  289,  290,
  272,  260,  273,  275,  276,  275,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  287,  272,  271,  275,  275,
  276,  272,  278,  279,  280,  281,  282,  283,  284,  285,
  286,  287,  272,  272,  272,  275,  276,   56,  278,  279,
  280,  281,  282,  283,  284,  285,  286,  287,  272,   55,
  118,  275,  276,   18,  278,  279,  280,  281,  282,  283,
  284,  285,  282,  283,  284,  285,   -1,  257,  258,  259,
  260,  261,  262,   -1,   -1,  265,  266,  267,  268,  269,
  270,  271,   -1,  272,  274,   -1,  275,  276,   -1,  278,
  279,  280,  281,  282,  283,  284,  285,  287,   -1,   -1,
   -1,  291,  292,  293,  257,  258,  259,  260,  261,  262,
   -1,   -1,  265,  266,  267,  268,  269,  270,  271,   -1,
  272,  274,   -1,  275,  276,   -1,  278,  279,  280,  281,
  282,  283,  284,  285,  287,   -1,   -1,   -1,  291,  292,
  293,  272,   -1,   -1,  275,  276,   -1,  278,  279,  280,
  281,  282,  283,  284,  285,  272,   -1,   -1,  275,  276,
   -1,  278,  279,  280,  281,  282,  283,  284,  285,  272,
   -1,   -1,  275,  276,   -1,  278,  279,  280,  281,  272,
   -1,  272,  275,  276,  275,  276,  279,   -1,  279,   59,
   60,   61,   62,  288,  289,  290,
};
#define YYFINAL 18
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 293
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT_LITERAL","DOUBLE_LITERAL",
"STRING_LITERAL","IDENTIFIER","FUNCTION","IF","ELSE","ELSIF","WHILE","FOR",
"RETURN_T","BREAK","CONTINUE","NULL_T","LP","RP","LC","RC","SEMICOLON","COMMA",
"ASSIGN","LOGICAL_AND","LOGICAL_OR","EQ","NE","GT","GE","LT","LE","ADD","SUB",
"MUL","DIV","MOD","TRUE_T","FALSE_T","GLOBAL_T",
};
char *yyrule[] = {
"$accept : translation_unit",
"translation_unit : definition_or_statement",
"translation_unit : translation_unit definition_or_statement",
"definition_or_statement : function_definition",
"definition_or_statement : statement",
"function_definition : FUNCTION IDENTIFIER LP parameter_list RP block",
"function_definition : FUNCTION IDENTIFIER LP RP block",
"parameter_list : IDENTIFIER",
"parameter_list : parameter_list COMMA IDENTIFIER",
"argument_list : expression",
"argument_list : argument_list COMMA expression",
"statement_list : statement",
"statement_list : statement_list statement",
"expression : logical_or_expression",
"expression : IDENTIFIER ASSIGN expression",
"logical_or_expression : logical_and_expression",
"logical_or_expression : logical_or_expression LOGICAL_OR logical_and_expression",
"logical_and_expression : equality_expression",
"logical_and_expression : logical_and_expression LOGICAL_AND equality_expression",
"equality_expression : relational_expression",
"equality_expression : equality_expression EQ relational_expression",
"equality_expression : equality_expression NE relational_expression",
"relational_expression : additive_expression",
"relational_expression : relational_expression GT additive_expression",
"relational_expression : relational_expression GE additive_expression",
"relational_expression : relational_expression LT additive_expression",
"relational_expression : relational_expression LE additive_expression",
"additive_expression : multiplicative_expression",
"additive_expression : additive_expression ADD multiplicative_expression",
"additive_expression : additive_expression SUB multiplicative_expression",
"multiplicative_expression : unary_expression",
"multiplicative_expression : multiplicative_expression MUL unary_expression",
"multiplicative_expression : multiplicative_expression DIV unary_expression",
"multiplicative_expression : multiplicative_expression MOD unary_expression",
"unary_expression : primary_expression",
"unary_expression : SUB unary_expression",
"primary_expression : IDENTIFIER LP argument_list RP",
"primary_expression : IDENTIFIER LP RP",
"primary_expression : LP expression RP",
"primary_expression : IDENTIFIER",
"primary_expression : INT_LITERAL",
"primary_expression : DOUBLE_LITERAL",
"primary_expression : STRING_LITERAL",
"primary_expression : TRUE_T",
"primary_expression : FALSE_T",
"primary_expression : NULL_T",
"statement : expression SEMICOLON",
"statement : global_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : return_statement",
"statement : break_statement",
"statement : continue_statement",
"global_statement : GLOBAL_T identifier_list SEMICOLON",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list COMMA IDENTIFIER",
"if_statement : IF LP expression RP block",
"if_statement : IF LP expression RP block ELSE block",
"if_statement : IF LP expression RP block elsif_list",
"if_statement : IF LP expression RP block elsif_list ELSE block",
"elsif_list : elsif",
"elsif_list : elsif_list elsif",
"elsif : ELSIF LP expression RP block",
"while_statement : WHILE LP expression RP block",
"for_statement : FOR LP expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RP block",
"expression_opt :",
"expression_opt : expression",
"return_statement : RETURN_T expression_opt SEMICOLON",
"break_statement : BREAK SEMICOLON",
"continue_statement : CONTINUE SEMICOLON",
"block : LC statement_list RC",
"block : LC RC",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 318 "crowbar.y"

#line 370 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 4:
#line 46 "crowbar.y"
{
            CRB_Interpreter *inter = crb_get_current_interpreter();

            inter->statement_list
                = crb_chain_statement_list(inter->statement_list, yyvsp[0].statement);
        }
break;
case 5:
#line 55 "crowbar.y"
{
            crb_function_define(yyvsp[-4].identifier, yyvsp[-2].parameter_list, yyvsp[0].block);
        }
break;
case 6:
#line 59 "crowbar.y"
{
            crb_function_define(yyvsp[-3].identifier, NULL, yyvsp[0].block);
        }
break;
case 7:
#line 65 "crowbar.y"
{
            yyval.parameter_list = crb_create_parameter(yyvsp[0].identifier);
        }
break;
case 8:
#line 69 "crowbar.y"
{
            yyval.parameter_list = crb_chain_parameter(yyvsp[-2].parameter_list, yyvsp[0].identifier);
        }
break;
case 9:
#line 75 "crowbar.y"
{
            yyval.argument_list = crb_create_argument_list(yyvsp[0].expression);
        }
break;
case 10:
#line 79 "crowbar.y"
{
            yyval.argument_list = crb_chain_argument_list(yyvsp[-2].argument_list, yyvsp[0].expression);
        }
break;
case 11:
#line 85 "crowbar.y"
{
            yyval.statement_list = crb_create_statement_list(yyvsp[0].statement);
        }
break;
case 12:
#line 89 "crowbar.y"
{
            yyval.statement_list = crb_chain_statement_list(yyvsp[-1].statement_list, yyvsp[0].statement);
        }
break;
case 14:
#line 96 "crowbar.y"
{
            yyval.expression = crb_create_assign_expression(yyvsp[-2].identifier, yyvsp[0].expression);
        }
break;
case 16:
#line 103 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(LOGICAL_OR_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 18:
#line 110 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(LOGICAL_AND_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 20:
#line 117 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(EQ_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 21:
#line 121 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(NE_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 23:
#line 128 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(GT_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 24:
#line 132 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(GE_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 25:
#line 136 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(LT_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 26:
#line 140 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(LE_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 28:
#line 147 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(ADD_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 29:
#line 151 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(SUB_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 31:
#line 158 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(MUL_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 32:
#line 162 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(DIV_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 33:
#line 166 "crowbar.y"
{
            yyval.expression = crb_create_binary_expression(MOD_EXPRESSION, yyvsp[-2].expression, yyvsp[0].expression);
        }
break;
case 35:
#line 173 "crowbar.y"
{
            yyval.expression = crb_create_minus_expression(yyvsp[0].expression);
        }
break;
case 36:
#line 179 "crowbar.y"
{
            yyval.expression = crb_create_function_call_expression(yyvsp[-3].identifier, yyvsp[-1].argument_list);
        }
break;
case 37:
#line 183 "crowbar.y"
{
            yyval.expression = crb_create_function_call_expression(yyvsp[-2].identifier, NULL);
        }
break;
case 38:
#line 187 "crowbar.y"
{
            yyval.expression = yyvsp[-1].expression;
        }
break;
case 39:
#line 191 "crowbar.y"
{
            yyval.expression = crb_create_identifier_expression(yyvsp[0].identifier);
        }
break;
case 43:
#line 198 "crowbar.y"
{
            yyval.expression = crb_create_boolean_expression(CRB_TRUE);
        }
break;
case 44:
#line 202 "crowbar.y"
{
            yyval.expression = crb_create_boolean_expression(CRB_FALSE);
        }
break;
case 45:
#line 206 "crowbar.y"
{
            yyval.expression = crb_create_null_expression();
        }
break;
case 46:
#line 212 "crowbar.y"
{
          yyval.statement = crb_create_expression_statement(yyvsp[-1].expression);
        }
break;
case 54:
#line 225 "crowbar.y"
{
            yyval.statement = crb_create_global_statement(yyvsp[-1].identifier_list);
        }
break;
case 55:
#line 231 "crowbar.y"
{
            yyval.identifier_list = crb_create_global_identifier(yyvsp[0].identifier);
        }
break;
case 56:
#line 235 "crowbar.y"
{
            yyval.identifier_list = crb_chain_identifier(yyvsp[-2].identifier_list, yyvsp[0].identifier);
        }
break;
case 57:
#line 241 "crowbar.y"
{
            yyval.statement = crb_create_if_statement(yyvsp[-2].expression, yyvsp[0].block, NULL, NULL);
        }
break;
case 58:
#line 245 "crowbar.y"
{
            yyval.statement = crb_create_if_statement(yyvsp[-4].expression, yyvsp[-2].block, NULL, yyvsp[0].block);
        }
break;
case 59:
#line 249 "crowbar.y"
{
            yyval.statement = crb_create_if_statement(yyvsp[-3].expression, yyvsp[-1].block, yyvsp[0].elsif, NULL);
        }
break;
case 60:
#line 253 "crowbar.y"
{
            yyval.statement = crb_create_if_statement(yyvsp[-5].expression, yyvsp[-3].block, yyvsp[-2].elsif, yyvsp[0].block);
        }
break;
case 62:
#line 260 "crowbar.y"
{
            yyval.elsif = crb_chain_elsif_list(yyvsp[-1].elsif, yyvsp[0].elsif);
        }
break;
case 63:
#line 266 "crowbar.y"
{
            yyval.elsif = crb_create_elsif(yyvsp[-2].expression, yyvsp[0].block);
        }
break;
case 64:
#line 272 "crowbar.y"
{
            yyval.statement = crb_create_while_statement(yyvsp[-2].expression, yyvsp[0].block);
        }
break;
case 65:
#line 279 "crowbar.y"
{
            yyval.statement = crb_create_for_statement(yyvsp[-6].expression, yyvsp[-4].expression, yyvsp[-2].expression, yyvsp[0].block);
        }
break;
case 66:
#line 285 "crowbar.y"
{
            yyval.expression = NULL;
        }
break;
case 68:
#line 292 "crowbar.y"
{
            yyval.statement = crb_create_return_statement(yyvsp[-1].expression);
        }
break;
case 69:
#line 298 "crowbar.y"
{
            yyval.statement = crb_create_break_statement();
        }
break;
case 70:
#line 304 "crowbar.y"
{
            yyval.statement = crb_create_continue_statement();
        }
break;
case 71:
#line 310 "crowbar.y"
{
            yyval.block = crb_create_block(yyvsp[-1].statement_list);
        }
break;
case 72:
#line 314 "crowbar.y"
{
            yyval.block = crb_create_block(NULL);
        }
break;
#line 848 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
