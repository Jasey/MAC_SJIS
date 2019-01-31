#ifndef PUBLIC_MEM_H
#define PUBLIC_MEM_H

#include <stdio.h>
#include <stdlib.h>

/*
** 内存管理
*/

// 内存出错时的处理方式
typedef enum {
    MEM_FAIL_AND_EXIT,			// 程序直接退出
    MEM_FAIL_AND_RETURN		// 返回
} MEM_FailMode;

typedef struct MEM_Controller_tag *MEM_Controller;
typedef void (*MEM_ErrorHandler)(MEM_Controller, char *, int, char *);
typedef struct MEM_Storage_tag *MEM_Storage;

// 内存回收器
extern MEM_Controller mem_default_controller;

#ifdef MEM_CONTROLLER
#define MEM_CURRENT_CONTROLLER MEM_CONTROLLER
#else /* MEM_CONTROLLER */
#define MEM_CURRENT_CONTROLLER mem_default_controller
#endif /* MEM_CONTROLLER */

/*
 * Don't use mem_*_func function.
 * There are private functions of MEM module.
 */
 
// 创建内存回收器
MEM_Controller MEM_create_controller(void);

// 内存分配
void *MEM_malloc_func(MEM_Controller controller,
                      char *filename, int line, size_t size);
					  
// 内存重新分配					  
void *MEM_realloc_func(MEM_Controller controller,
                       char *filename, int line, void *ptr, size_t size);

// 作用不明？					   
char *MEM_strdup_func(MEM_Controller controller,
                      char *filename, int line, char *str);

// 打开创建一个存储器					  
MEM_Storage MEM_open_storage_func(MEM_Controller controller,
                                  char *filename, int line, int page_size);

// 从存储器中分配内存								  
void *MEM_storage_malloc_func(MEM_Controller controller,
                              char *filename, int line,
                              MEM_Storage storage, size_t size);

// 内存释放							  
void MEM_free_func(MEM_Controller controller, void *ptr);

// 从存储器中释放内存
void MEM_dispose_storage_func(MEM_Controller controller,
                              MEM_Storage storage);

// 设置内存分配失败处理函数
void MEM_set_error_handler(MEM_Controller controller,
                           MEM_ErrorHandler handler);

// 设置错误模式						   
void MEM_set_fail_mode(MEM_Controller controller,
                       MEM_FailMode mode);

// 打印已分配的内存块					   
void MEM_dump_blocks_func(MEM_Controller controller, FILE *fp);

// 检查内存块
void MEM_check_block_func(MEM_Controller controller,
                          char *filename, int line, void *p);

// 检查所有内存块						  
void MEM_check_all_blocks_func(MEM_Controller controller,
                               char *filename, int line);

#define MEM_malloc(size)\
  (MEM_malloc_func(MEM_CURRENT_CONTROLLER,\
                   __FILE__, __LINE__, size))
#define MEM_realloc(ptr, size)\
  (MEM_realloc_func(MEM_CURRENT_CONTROLLER, __FILE__, __LINE__, ptr, size))
#define MEM_strdup(str)\
  (MEM_strdup_func(MEM_CURRENT_CONTROLLER, __FILE__, __LINE__, str))
#define MEM_open_storage(page_size)\
  (MEM_open_storage_func(MEM_CURRENT_CONTROLLER,\
                         __FILE__, __LINE__, page_size))
#define MEM_storage_malloc(storage, size)\
  (MEM_storage_malloc_func(MEM_CURRENT_CONTROLLER,\
                           __FILE__, __LINE__, storage, size))
#define MEM_free(ptr) (MEM_free_func(MEM_CURRENT_CONTROLLER, ptr))
#define MEM_dispose_storage(storage)\
  (MEM_dispose_storage_func(MEM_CURRENT_CONTROLLER, storage))
#ifdef DEBUG
#define MEM_dump_blocks(fp)\
  (MEM_dump_blocks_func(MEM_CURRENT_CONTROLLER, fp))
#define MEM_check_block(p)\
  (MEM_check_block_func(MEM_CURRENT_CONTROLLER, __FILE__, __LINE__, p))
#define MEM_check_all_blocks()\
  (MEM_check_all_blocks_func(MEM_CURRENT_CONTROLLER, __FILE__, __LINE__))
#else /* DEBUG */
#define MEM_dump_blocks(fp) ((void)0)
#define MEM_check_block(p)  ((void)0)
#define MEM_check_all_blocks() ((void)0)
#endif /* DEBUG */

#endif  /* PUBLIC_MEM_H */
