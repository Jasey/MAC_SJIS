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
extern YYSTYPE yylval;
