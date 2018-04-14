#pragma once

#include "global.h"

// ���Զ������ƶϵ�����£�����ģ�����ʹ����ģ�����Ͳ������βΣ�ֻ�������µ�����ת����
// 1���Ƕ���constָ��������򶥲�constָ������õ�ת����
// 2��������ָ�������һ��Ԫ�ص�ָ���ת����
// 3����������ָ���ת����
// ����Щδʹ��ģ�����Ͳ������βΣ�ִ������������ת����

// ����ʽָ��������ʵ�ε�����£���ʵ�ε��β�ִ������������ת����

template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2)
		return -1;
	else if (v2 < v1)
		return 1;
	else
		return 0;
}

// ����ģ�����������൱��ʵ�����˺���ģ���һ��ʵ����
template <>
int compare(const char *const &p1, const char *const &p2) {
	return strcmp(p1, p2);
}

//template <typename T, typename F = less<T>>
//int compare(const T &v1, const T &v2, F f = F()) {
//	if (f(v1, v2)) return -1;
//	if (f(v2, v1)) return 1;
//	return 0;
//}

template <unsigned M, unsigned N>
int compare(const char(&a1)[M], const char(&a2)[N]) {
	return strcmp(a1, a2);
}

template <typename T1, typename T2, typename T3>
T1 sum(const T2 &a, const T3 &b) {
	return a + b;
}

template <typename T>
ostream &print(ostream &os, const T &t) {
	return os << t;
}

// �ɱ��������ģ��
template <typename T, typename... T_args>
ostream &print(ostream &os, const T &t, const T_args &... rest) { // ...Ϊ����չ�����ֽ�rest��һ����Ԫ�أ�Ȼ��Ӧ��...��ߵ�ģʽ��const T_args&����ÿһ��Ԫ��
	os << t << ",";
	// �ݹ��������rest�е�һ����������t������Ĳ�����Ϊ��һ�ε�rest
	return print(os, rest...); // ...Ϊ����չ������չ���ɰ���Ԫ����ɵģ����ŷָ���ʵ���б�
	// return print(os,debug_rep(rest)...); // �ȼ���return print(os,debug_rep(v1),debug_rep(v2),debug_rep(v3),...debug_rep(vn));
}

// ����ת��
template <typename F,typename T1,typename T2>
void flip(F f, T1 &&arg1, T2 &&arg2) {
	/*�����۵���
	1.������ֵ�����ͽ����ƶϳ�T&����T& &&���۵���T&
	2.������ֵ�����ͽ����ƶϳ�T���򱣳�T&&
	*/
	f(std::forward<T2>(arg2), std::forward<T1>(arg1)); // std::forward������ԭ������Ϣ���䣬��ԭ����ʲô���ͣ�ת������ʲô����
}