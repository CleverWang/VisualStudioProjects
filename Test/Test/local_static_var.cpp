#include "global.h" // �����������������ñ��������

/*ͳ�ƺ��������õĴ���*/
size_t func_call_times()
{
	static size_t cnt = 0; // �ֲ���̬����
	return ++cnt;
}