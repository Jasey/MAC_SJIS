#include <string.h>
#include "crowbar.h"

/*
** ��ʽ���ı���ʱ������Ϣ
*/

// delete by mobinsheng for �ظ����� begin
/*MessageFormat crb_compile_error_message_format[] = {
    {"dummy"},
    {"��($(token))���������﷨����"},
    {"����ȷ���ַ�($(bad_char))"},
    {"�������ظ�($(name))"},
    {"dummy"},
};
*/
/*
** ��ʽ��������ʱ������Ϣ
*//*
MessageFormat crb_runtime_error_message_format[] = {
    {"dummy"},
    {"�Ҳ�������($(name))��"},
    {"�Ҳ�������($(name))��"},
    {"����Ĳ����������ں������塣"},
    {"����Ĳ����������ں������塣"},
    {"�������ʽ��ֵ������boolean�͡�"},
    {"��������Ĳ�������������ֵ���͡�"},
    {"˫Ŀ������$(operator)�Ĳ��������Ͳ���ȷ��"},
    {"$(operator)��������������boolean�͡�"},
    {"��Ϊfopen()���������ļ���·���ʹ򿪷�ʽ�����߶����ַ������͵ģ���"},
    {"��Ϊfclose()���������ļ�ָ�롣"},
    {"��Ϊfgets()���������ļ�ָ�롣"},
    {"��Ϊfputs()���������ļ�ָ����ַ�����"},
    {"nullֻ����������� == �� !=(���ܽ���$(operator)����)��"},
    {"���ܱ�0����"},
    {"ȫ�ֱ���$(name)�����ڡ�"},
    {"�����ں�����ʹ��global��䡣"},
    {"�����$(operator)���������ַ������͡�"},
    {"dummy"},
};*/
// delete by mobinsheng for �ظ����� end