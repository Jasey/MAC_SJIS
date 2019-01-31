// 面向内置函数开发人员的接口

#ifndef PUBLIC_CRB_DEV_H_INCLUDED
#define PUBLIC_CRB_DEV_H_INCLUDED
#include "CRB.h"

// 布尔型
typedef enum {
    CRB_FALSE = 0,
    CRB_TRUE = 1
} CRB_Boolean;

// 字符串类型
typedef struct CRB_String_tag CRB_String;

// 指针信息
typedef struct {
    char        *name;
} CRB_NativePointerInfo;

// 值的类型
typedef enum {
    CRB_BOOLEAN_VALUE = 1,			// 布尔类型
    CRB_INT_VALUE,					// 整形
    CRB_DOUBLE_VALUE,				// 浮点型
    CRB_STRING_VALUE,				// 字符串类型
    CRB_NATIVE_POINTER_VALUE,		// 指针类型
    CRB_NULL_VALUE					// null
} CRB_ValueType;

// 指针类型
typedef struct {
    CRB_NativePointerInfo       *info;
    void                        *pointer;
} CRB_NativePointer;

// 值（整形、布尔、字符串、浮点、指针等等）
typedef struct {
    CRB_ValueType       type;
    union {
        CRB_Boolean     boolean_value;					// 布尔类型
        int             int_value;									// 整形
        double          double_value;						// 浮点型
        CRB_String      *string_value;						// 字符串
        CRB_NativePointer       native_pointer;		// 指针
    } u;
} CRB_Value;

// 调用c语言的函数
typedef CRB_Value CRB_NativeFunctionProc(CRB_Interpreter *interpreter,
                                         int arg_count, CRB_Value *args);
// 将函数c函数注册到解释器中
void CRB_add_native_function(CRB_Interpreter *interpreter,
                             char *name, CRB_NativeFunctionProc *proc);
							 
// 注册全局变量
void CRB_add_global_variable(CRB_Interpreter *inter,
                             char *identifier, CRB_Value *value);

#endif /* PUBLIC_CRB_DEV_H_INCLUDED */
