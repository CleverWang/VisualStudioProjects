#pragma once

#include "global.h"

// 在自动类型推断的情况下，函数模板对于使用了模板类型参数的形参，只进行以下的类型转换：
// 1、非顶层const指针或引用向顶层const指针或引用的转换；
// 2、数组向指向数组第一个元素的指针的转换；
// 3、函数向函数指针的转换。
// 对那些未使用模板类型参数的形参，执行正常的类型转换。

// 在显式指定了类型实参的情况下，对实参到形参执行正常的类型转换。

template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2)
		return -1;
	else if (v2 < v1)
		return 1;
	else
		return 0;
}

// 函数模板特例化（相当于实例化了函数模板的一个实例）
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

// 可变参数函数模板
template <typename T, typename... T_args>
ostream &print(ostream &os, const T &t, const T_args &... rest) { // ...为包扩展，即分解rest成一个个元素，然后应用...左边的模式（const T_args&）到每一个元素
	os << t << ",";
	// 递归调用自身，rest中的一个参数赋给t，其余的参数作为下一次的rest
	return print(os, rest...); // ...为包扩展，即扩展成由包中元素组成的，逗号分隔的实参列表
	// return print(os,debug_rep(rest)...); // 等价于return print(os,debug_rep(v1),debug_rep(v2),debug_rep(v3),...debug_rep(vn));
}

// 类型转发
template <typename F,typename T1,typename T2>
void flip(F f, T1 &&arg1, T2 &&arg2) {
	/*引用折叠：
	1.传递左值，类型将被推断成T&，则T& &&被折叠成T&
	2.传递右值，类型将被推断成T，则保持T&&
	*/
	f(std::forward<T2>(arg2), std::forward<T1>(arg1)); // std::forward将保持原类型信息不变，即原来是什么类型，转发后还是什么类型
}