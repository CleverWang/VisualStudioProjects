#include "global.h"

// �Ѻ����������µ����ͣ�������Ϊ�βλ��Զ�ת���ɺ���ָ�룩
//typedef const string& f_as_p_1(const string&, const string&);
//using f_as_p_2 = const string& (const string&, const string&);

// �Ѻ���ָ���������µ�����
//typedef const string& (*f_as_p_3)(const string&, const string&);
//using f_as_p_4 = const string& (*)(const string&, const string&);

// ��������⣬�����֪����func��Ҳ����ʹ��:
// typedef decltype(func) f��typedef decltype(func) *f
// using f=decltype(func)��using f=decltype(func) *

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