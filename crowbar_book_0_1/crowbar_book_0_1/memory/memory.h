#ifndef PRIVATE_MEM_H_INCLUDED
#define PRIVATE_MEM_H_INCLUDED
#include "../MEM.h"

typedef union Header_tag Header;

// 内存控制器
struct MEM_Controller_tag {
    FILE        *error_fp;							// 错误（内存泄露、越界等）输出文件
    MEM_ErrorHandler    error_handler;	// 错误处理
    MEM_FailMode        fail_mode;			// 内存出错时的处理方式
    Header      *block_header;					// 出错的内存块列表
};
#endif /* PRIVATE_MEM_H_INCLUDED */

