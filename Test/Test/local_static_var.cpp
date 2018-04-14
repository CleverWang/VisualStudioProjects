#include "global.h" // 包含函数的声明，让编译器检查

/*统计函数被调用的次数*/
size_t func_call_times()
{
	static size_t cnt = 0; // 局部静态变量
	return ++cnt;
}