#include <stdio.h>
#include "CRB.h"
#include "MEM.h"

int
	main(int argc, char **argv)
{
	CRB_Interpreter     *interpreter;

	FILE *fp;

	if (argc != 2) 
	{
		fprintf(stderr, "usage:%s filename", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) 
	{
		fprintf(stderr, "%s not found.\n", argv[1]);
		exit(1);
	}

	interpreter = CRB_create_interpreter();				// 创建解释器
	CRB_compile(interpreter, fp);								// 编译
	CRB_interpret(interpreter);								// 解释
	CRB_dispose_interpreter(interpreter);				// 释放解释器

	MEM_dump_blocks(stdout);								// 检查内存是否释放

	return 0;
}
