#include "global.h"

// 把函数声明成新的类型（函数作为形参会自动转换成函数指针）
//typedef const string& f_as_p_1(const string&, const string&);
//using f_as_p_2 = const string& (const string&, const string&);

// 把函数指针声明成新的类型
//typedef const string& (*f_as_p_3)(const string&, const string&);
//using f_as_p_4 = const string& (*)(const string&, const string&);

// 除上面的外，如果已知函数func，也可以使用:
// typedef decltype(func) f或typedef decltype(func) *f
// using f=decltype(func)或using f=decltype(func) *

string func_as_param(const string& s1, const string& s2, const string& f_as_p(const string&, const string&))
{
	auto s = f_as_p(s1, s2);
	s[0] = toupper(s[0]);
	return s;
}

//string func_as_param(const string& s1, const string& s2, f_as_p_1 func)
//{
//	auto s = func(s1, s2);
//	s[0] = toupper(s[0]);
//	return s;
//}