#ifndef PUBLIC_DBG_H_INCLUDED
#define PUBLIC_DBG_H_INCLUDED
#include <stdio.h>      
#include <stdarg.h>

/*
** 调试模块
*/


typedef struct DBG_Controller_tag *DBG_Controller;				// 调试器
void DBG_set(DBG_Controller controller, char *file, int line);	// 设置调试器
void DBG_set_expression(char *expression);						// 设置表达式

#ifdef DBG_NO_DEBUG
	#define DBG_create_controller()         ((void)0)
	#define DBG_set_debug_level(level)      ((void)0)
	#define DBG_set_debug_write_fp(fp)      ((void)0)
	#define DBG_assert(expression, arg)     ((void)0)
	#define DBG_panic(arg)                  ((void)0)
	#define DBG_debug_write(arg)            ((void)0)
#else /* DBG_NO_DEBUG */
	#ifdef DBG_CONTROLLER
		#define DBG_CURRENT_CONTROLLER  DBG_CONTROLLER
	#else /* DBG_CONTROLLER */
		#define DBG_CURRENT_CONTROLLER  dbg_default_controller
	#endif /* DBG_CONTROLLER */
	
	extern DBG_Controller DBG_CURRENT_CONTROLLER;

	#define DBG_create_controller() (DBG_create_controller_func())
	#define DBG_set_debug_level(level) \
	(DBG_set_debug_level_func(DBG_CURRENT_CONTROLLER, (level)))
	#define DBG_set_debug_write_fp(fp) \
	(DBG_set_debug_write_fp(DBG_CURRENT_CONTROLLER, (fp))
	#define DBG_assert(expression, arg) \
	 ((expression) ? (void)(0) :\
	  ((DBG_set(DBG_CURRENT_CONTROLLER, __FILE__, __LINE__)),\
	   (DBG_set_expression(#expression)),\
	   DBG_assert_func arg))
	#define DBG_panic(arg) \
	 ((DBG_set(DBG_CURRENT_CONTROLLER, __FILE__, __LINE__)),\
	  DBG_panic_func arg)
	#define DBG_debug_write(arg) \
	 ((DBG_set(DBG_CURRENT_CONTROLLER, __FILE__, __LINE__)),\
	  DBG_debug_write_func arg)
#endif /* DBG_NO_DEBUG */

// 调试的布尔型？
typedef enum {
    DBG_TRUE = 1,
    DBG_FALSE = 0
} DBG_Boolean;

DBG_Controller DBG_create_controller_func(void);						// 创建调试器
void DBG_set_debug_level_func(DBG_Controller controller, int level);	// 设置调试等级
void DBG_set_debug_write_fp_func(DBG_Controller controller, FILE *fp);	// 设置调试的输出流
void DBG_assert_func(char *fmt, ...);									// 断言
void DBG_panic_func(char *fmt, ...);									// 恐慌中断
void DBG_debug_write_func(int level, char *fmt, ...);					// 写调试信息
#endif /* PUBLIC_DBG_H_INCLUDED */
