#include <stdio.h>
#include <string.h>
#include "MEM.h"
#include "crowbar.h"

#define STRING_ALLOC_SIZE       (256)

static char *st_string_literal_buffer = NULL;
static int st_string_literal_buffer_size = 0;
static int st_string_literal_buffer_alloc_size = 0;

// 打开字面量字符串
void crb_open_string_literal(void)
{
    st_string_literal_buffer_size = 0;
}

// 添加字面量字符串
void crb_add_string_literal(int letter)
{
    if (st_string_literal_buffer_size == st_string_literal_buffer_alloc_size) {
        st_string_literal_buffer_alloc_size += STRING_ALLOC_SIZE;
        st_string_literal_buffer
            = MEM_realloc(st_string_literal_buffer,
                          st_string_literal_buffer_alloc_size);
    }
    st_string_literal_buffer[st_string_literal_buffer_size] = letter;
    st_string_literal_buffer_size++;
}

// 重置字面量字符串的buffer
void crb_reset_string_literal_buffer(void)
{
    MEM_free(st_string_literal_buffer);
    st_string_literal_buffer = NULL;
    st_string_literal_buffer_size = 0;
    st_string_literal_buffer_alloc_size = 0;
}

// 关闭字面量字符串
char * crb_close_string_literal(void)
{
    char *new_str;

    new_str = crb_malloc(st_string_literal_buffer_size + 1);

    memcpy(new_str, st_string_literal_buffer, st_string_literal_buffer_size);
    new_str[st_string_literal_buffer_size] = '\0';

    return new_str;
}

// 创建一个标识（变量）
char * crb_create_identifier(char *str)
{
    char *new_str;

    new_str = crb_malloc(strlen(str) + 1);

    strcpy(new_str, str);

    return new_str;
}

