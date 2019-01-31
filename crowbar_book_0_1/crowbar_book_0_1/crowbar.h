#ifndef PRIVATE_CROWBAR_H_INCLUDED
#define PRIVATE_CROWBAR_H_INCLUDED
#include <stdio.h>
#include "MEM.h"
#include "CRB.h"
#include "CRB_dev.h"


#define smaller(a, b) ((a) < (b) ? (a) : (b))
#define larger(a, b) ((a) > (b) ? (a) : (b))

#define MESSAGE_ARGUMENT_MAX    (256)
#define LINE_BUF_SIZE           (1024)



// 数学操作符号
#define dkc_is_math_operator(operator) \
	((operator) == ADD_EXPRESSION || (operator) == SUB_EXPRESSION\
	|| (operator) == MUL_EXPRESSION || (operator) == DIV_EXPRESSION\
	|| (operator) == MOD_EXPRESSION)


// 比较符号
#define dkc_is_compare_operator(operator) \
	((operator) == EQ_EXPRESSION || (operator) == NE_EXPRESSION\
	|| (operator) == GT_EXPRESSION || (operator) == GE_EXPRESSION\
	|| (operator) == LT_EXPRESSION || (operator) == LE_EXPRESSION)

// 逻辑符号
#define dkc_is_logical_operator(operator) \
	((operator) == LOGICAL_AND_EXPRESSION || (operator) == LOGICAL_OR_EXPRESSION)



// 编译时的错误
typedef enum
{
	PARSE_ERR = 1,						// 语法分析错误
	CHARACTER_INVALID_ERR,				// 字符无效
	FUNCTION_MULTIPLE_DEFINE_ERR,		// 函数多重定义
	COMPILE_ERROR_COUNT_PLUS_1
} CompileError;

// 运行时错误
typedef enum 
{
	VARIABLE_NOT_FOUND_ERR = 1,			// 变量没找到
	FUNCTION_NOT_FOUND_ERR,				// 函数没找到
	ARGUMENT_TOO_MANY_ERR,				// 参数太多
	ARGUMENT_TOO_FEW_ERR,				// 参数不够
	NOT_BOOLEAN_TYPE_ERR,				// 没有bool类型
	MINUS_OPERAND_TYPE_ERR,				// 负号类型错误
	BAD_OPERAND_TYPE_ERR,				// 错误的操作负号
	NOT_BOOLEAN_OPERATOR_ERR,			// 没有布尔操作负号
	FOPEN_ARGUMENT_TYPE_ERR,			// 打开文件参数类型错误
	FCLOSE_ARGUMENT_TYPE_ERR,			// 关闭文件参数类型错误
	FGETS_ARGUMENT_TYPE_ERR,			// fgets参数错误
	FPUTS_ARGUMENT_TYPE_ERR,			// fputs参数错误
	NOT_NULL_OPERATOR_ERR,				// 没有null操作符
	DIVISION_BY_ZERO_ERR,				// 除0
	GLOBAL_VARIABLE_NOT_FOUND_ERR,		// 全局变量没找到
	GLOBAL_STATEMENT_IN_TOPLEVEL_ERR,	// 全局语句在顶层结构
	BAD_OPERATOR_FOR_STRING_ERR,		// string类型的错误
	RUNTIME_ERROR_COUNT_PLUS_1
} RuntimeError;

// 参数类型
typedef enum 
{
	INT_MESSAGE_ARGUMENT = 1,
	DOUBLE_MESSAGE_ARGUMENT,
	STRING_MESSAGE_ARGUMENT,
	CHARACTER_MESSAGE_ARGUMENT,
	POINTER_MESSAGE_ARGUMENT,
	MESSAGE_ARGUMENT_END
} MessageArgumentType;

// 参数格式
typedef struct 
{
	char *format;
} MessageFormat;

typedef struct Expression_tag Expression;

// 表达式类型
typedef enum 
{
	BOOLEAN_EXPRESSION = 1,				// 布尔表达式
	INT_EXPRESSION,									// 整数表达式
	DOUBLE_EXPRESSION,							// 浮点表达式
	STRING_EXPRESSION,							// 字符串表达式
	IDENTIFIER_EXPRESSION,						// 定义
	ASSIGN_EXPRESSION,							// 赋值
	ADD_EXPRESSION,								// 加法
	SUB_EXPRESSION,								// 减法
	MUL_EXPRESSION,								// 乘法
	DIV_EXPRESSION,								// 除法
	MOD_EXPRESSION,								// 求于
	EQ_EXPRESSION,									// 等于
	NE_EXPRESSION,									// 不等于
	GT_EXPRESSION,									// 大于
	GE_EXPRESSION,									// 大于等于
	LT_EXPRESSION,									// 小于
	LE_EXPRESSION,									// 小于等于
	LOGICAL_AND_EXPRESSION,				// &&
	LOGICAL_OR_EXPRESSION,					// ||
	MINUS_EXPRESSION,							// 取负号
	FUNCTION_CALL_EXPRESSION,			// 函数调用
	NULL_EXPRESSION,								// 空表达式
	EXPRESSION_TYPE_COUNT_PLUS_1
} ExpressionType;

// 参数列表
typedef struct ArgumentList_tag 
{
	Expression *expression;
	struct ArgumentList_tag *next;
} ArgumentList;

// 赋值表达式
typedef struct 
{
	char        *variable;			//变量名（即等号左边的变量）
	Expression  *operand;		// 操作数（即等号右边的变量）
} AssignExpression;

// 二元表达式？
typedef struct 
{
	Expression  *left;				// 二元符号的左边的表达式
	Expression  *right;				// 二元符号的右边的表达式
} BinaryExpression;

// 函数调用表达式
typedef struct 
{
	char						*identifier;			// 函数的名字或者
	ArgumentList        *argument;		// 形参列表
} FunctionCallExpression;

// 表达式
struct Expression_tag 
{
	ExpressionType type;													// 表达式类型
	int line_number;															// 行号（表达式所在位置）
	union 
	{
		CRB_Boolean             boolean_value;							// 布尔表达式
		int                     int_value;											// 整形表达式
		double                  double_value;								// 浮点表达式
		char                    *string_value;									// 字符串表达式
		char                    *identifier;										// 定义表达式
		AssignExpression        assign_expression;					// 赋值表达式
		BinaryExpression        binary_expression;					// 二元表达式
		Expression              *minus_expression;						// 负号表达式
		FunctionCallExpression  function_call_expression;		// 函数调用表达式
	} u;
};

typedef struct Statement_tag Statement;

// 语句列表
typedef struct StatementList_tag 
{
	Statement   *statement;						// 语句
	struct StatementList_tag    *next;			// 下一条语句
} StatementList;

// 一个语句块，即由一系列语句组成
typedef struct 
{
	StatementList       *statement_list;
} Block;

typedef struct IdentifierList_tag 
{
	char        *name;
	struct IdentifierList_tag   *next;
} IdentifierList;

typedef struct 
{
	IdentifierList      *identifier_list;
} GlobalStatement;

typedef struct Elsif_tag 
{
	Expression  *condition;
	Block       *block;
	struct Elsif_tag    *next;
} Elsif;

typedef struct 
{
	Expression  *condition;
	Block       *then_block;
	Elsif       *elsif_list;
	Block       *else_block;
} IfStatement;

typedef struct 
{
	Expression  *condition;
	Block       *block;
} WhileStatement;

typedef struct 
{
	Expression  *init;
	Expression  *condition;
	Expression  *post;
	Block       *block;
} ForStatement;

typedef struct 
{
	Expression *return_value;
} ReturnStatement;

typedef enum 
{
	EXPRESSION_STATEMENT = 1,		// 表达式语句
	GLOBAL_STATEMENT,					// global语句
	IF_STATEMENT,							// if语句
	WHILE_STATEMENT,						// while语句
	FOR_STATEMENT,							// for语句
	RETURN_STATEMENT,					// return语句
	BREAK_STATEMENT,						// break语句
	CONTINUE_STATEMENT,				// continue语句
	STATEMENT_TYPE_COUNT_PLUS_1
} StatementType;

// 语句（表达式也是一种语句）
struct Statement_tag 
{
	StatementType       type;				// 语句类型
	int                 line_number;			// 语句所在位置
	union 
	{
		Expression      *expression_s;		// 表达式语句
		GlobalStatement global_s;			// 全局，即带global的语句
		IfStatement     if_s;					// if语句
		WhileStatement  while_s;			// while语句
		ForStatement    for_s;				// for语句
		ReturnStatement return_s;		// return 语句
	} u;
};

// 形参列表（注意形参是没有值得）
typedef struct ParameterList_tag 
{
	char        *name;							// 形参名称
	struct ParameterList_tag *next;		// 下一个形参
} ParameterList;

typedef enum 
{
	CROWBAR_FUNCTION_DEFINITION = 1,		// 用户自定义函数
	NATIVE_FUNCTION_DEFINITION					// 内置函数
} FunctionDefinitionType;

// 函数定义
typedef struct FunctionDefinition_tag 
{
	char									*name;					// 函数名
	FunctionDefinitionType      type;					// 函数类型：用户自定义或者内置类型
	union 
	{
		struct														// 用户自定义函数
		{
			ParameterList			*parameter;			// 形参列表
			Block						*block;					// 语句块
		} crowbar_f;

		struct														// 内置函数
		{
			CRB_NativeFunctionProc      *proc;		// 内置函数指针
		} native_f;

	} u;
	struct FunctionDefinition_tag       *next;		// 下一个函数定义
} FunctionDefinition;

// 变量
typedef struct Variable_tag 
{
	char        *name;							// 变量名
	CRB_Value   value;						// 变量值
	struct Variable_tag *next;				// 下一个变量
} Variable;

// 语句执行完成的类型
typedef enum 
{
	NORMAL_STATEMENT_RESULT = 1,					// 语句正常执行
	RETURN_STATEMENT_RESULT,							// 语句由return返回
	BREAK_STATEMENT_RESULT,							// 语句由break中断返回
	CONTINUE_STATEMENT_RESULT,					// 语句由continue返回
	STATEMENT_RESULT_TYPE_COUNT_PLUS_1
} StatementResultType;

typedef struct 
{
	StatementResultType type;
	union
	{
		CRB_Value       return_value; //语句的返回值
	} u;
} StatementResult;

// 全局变量的引用
typedef struct GlobalVariableRef_tag 
{
	Variable    *variable;
	struct GlobalVariableRef_tag *next;
} GlobalVariableRef;

// 执行环境，用于存放局部变量和全局变量的引用
typedef struct 
{
	Variable    *variable;
	GlobalVariableRef   *global_variable;
} LocalEnvironment;

struct CRB_String_tag
{
	int         ref_count;
	char        *string;
	CRB_Boolean is_literal;
};

typedef struct 
{
	CRB_String  *strings;
} StringPool;

// 解释器
struct CRB_Interpreter_tag 
{

	MEM_Storage         interpreter_storage;	// 解释器的存储器
	MEM_Storage         execute_storage;		// 运行时的存储器
	Variable            *variable;							// 变量列表
	FunctionDefinition  *function_list;				// 函数列表
	StatementList       *statement_list;				// 语句列表（表达式也是一种语句）
	int                 current_line_number;			// 当前行号，当出现错误时用于指明出错位置
};


/* create.c */
void crb_function_define(char *identifier, ParameterList *parameter_list,Block *block);
ParameterList *crb_create_parameter(char *identifier);
ParameterList *crb_chain_parameter(ParameterList *list,char *identifier);
ArgumentList *crb_create_argument_list(Expression *expression);
ArgumentList *crb_chain_argument_list(ArgumentList *list, Expression *expr);
StatementList *crb_create_statement_list(Statement *statement);
StatementList *crb_chain_statement_list(StatementList *list,Statement *statement);
Expression *crb_alloc_expression(ExpressionType type);
Expression *crb_create_assign_expression(char *variable,Expression *operand);
Expression *crb_create_binary_expression(ExpressionType operator,Expression *left,Expression *right);
Expression *crb_create_minus_expression(Expression *operand);
Expression *crb_create_identifier_expression(char *identifier);
Expression *crb_create_function_call_expression(char *func_name,ArgumentList *argument);
Expression *crb_create_boolean_expression(CRB_Boolean value);
Expression *crb_create_null_expression(void);
Statement *crb_create_global_statement(IdentifierList *identifier_list);
IdentifierList *crb_create_global_identifier(char *identifier);
IdentifierList *crb_chain_identifier(IdentifierList *list, char *identifier);
Statement *crb_create_if_statement(Expression *condition,Block *then_block, Elsif *elsif_list,Block *else_block);
Elsif *crb_chain_elsif_list(Elsif *list, Elsif *add);
Elsif *crb_create_elsif(Expression *expr, Block *block);
Statement *crb_create_while_statement(Expression *condition, Block *block);
Statement *crb_create_for_statement(Expression *init, Expression *cond,Expression *post, Block *block);
Block *crb_create_block(StatementList *statement_list);
Statement *crb_create_expression_statement(Expression *expression);
Statement *crb_create_return_statement(Expression *expression);
Statement *crb_create_break_statement(void);
Statement *crb_create_continue_statement(void);

/* string.c */
char *crb_create_identifier(char *str);
void crb_open_string_literal(void);
void crb_add_string_literal(int letter);
void crb_reset_string_literal_buffer(void);
char *crb_close_string_literal(void);

/* execute.c */
StatementResult crb_execute_statement_list(CRB_Interpreter *inter,LocalEnvironment *env, StatementList *list);

/* eval.c */
CRB_Value crb_eval_binary_expression(CRB_Interpreter *inter,LocalEnvironment *env,ExpressionType operator,Expression *left, Expression *right);
CRB_Value crb_eval_minus_expression(CRB_Interpreter *inter,LocalEnvironment *env, Expression *operand);
CRB_Value crb_eval_expression(CRB_Interpreter *inter,LocalEnvironment *env, Expression *expr);

/* string_pool.c */
CRB_String *crb_literal_to_crb_string(CRB_Interpreter *inter, char *str);
void crb_refer_string(CRB_String *str);
void crb_release_string(CRB_String *str);
CRB_String *crb_search_crb_string(CRB_Interpreter *inter, char *str);
CRB_String *crb_create_crowbar_string(CRB_Interpreter *inter, char *str);

/* util.c */
CRB_Interpreter *crb_get_current_interpreter(void);
void crb_set_current_interpreter(CRB_Interpreter *inter);
void *crb_malloc(size_t size);
void *crb_execute_malloc(CRB_Interpreter *inter, size_t size);
Variable *crb_search_local_variable(LocalEnvironment *env,char *identifier);
Variable * crb_search_global_variable(CRB_Interpreter *inter, char *identifier);
void crb_add_local_variable(LocalEnvironment *env,char *identifier, CRB_Value *value);
CRB_NativeFunctionProc* crb_search_native_function(CRB_Interpreter *inter, char *name);
FunctionDefinition *crb_search_function(char *name);
char *crb_get_operator_string(ExpressionType type);

/* error.c */
void crb_compile_error(CompileError id, ...);
void crb_runtime_error(int line_number, RuntimeError id, ...);

/* native.c */
CRB_Value crb_nv_print_proc(CRB_Interpreter *interpreter,int arg_count, CRB_Value *args);
CRB_Value crb_nv_fopen_proc(CRB_Interpreter *interpreter,int arg_count, CRB_Value *args);
CRB_Value crb_nv_fclose_proc(CRB_Interpreter *interpreter,int arg_count, CRB_Value *args);
CRB_Value crb_nv_fgets_proc(CRB_Interpreter *interpreter,int arg_count, CRB_Value *args);
CRB_Value crb_nv_fputs_proc(CRB_Interpreter *interpreter,int arg_count, CRB_Value *args);
void crb_add_std_fp(CRB_Interpreter *inter);

#endif /* PRIVATE_CROWBAR_H_INCLUDED */
