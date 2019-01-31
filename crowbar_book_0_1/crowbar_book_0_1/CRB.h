// 面向普通用户的头文件

#ifndef PUBLIC_CRB_H_INCLUDED
#define PUBLIC_CRB_H_INCLUDED
#include <stdio.h>

typedef struct CRB_Interpreter_tag CRB_Interpreter;					// 指向解释器的指针

CRB_Interpreter *CRB_create_interpreter(void);							// 生成解释器

void CRB_compile(CRB_Interpreter *interpreter, FILE *fp);			// 生成分析树

void CRB_interpret(CRB_Interpreter *interpreter);						// 运行

void CRB_dispose_interpreter(CRB_Interpreter *interpreter);		// 运行完成后回收解释器

#endif /* PUBLIC_CRB_H_INCLUDED */
