#include "global.h"
using std::abs;

int(*func_ptr_1())(int)
{
	return abs;
}

auto func_ptr_2() -> int(*)(int)
{
	return abs;
}

f *func_ptr_3()
{
	return abs;
}

fp func_ptr_4()
{
	return abs;
}

// 除上面的外，如果已知函数func，可以:
// decltype(func) *f()