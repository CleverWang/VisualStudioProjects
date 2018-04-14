#pragma once

#include "global.h"

/*
如果成员是引用、const或某种未提供默认构造函数的类类型，必须通过构造函数初始值列表初始化这些成员
*/
class ConstRef {
private:
	int var;
	const int var_const;
	int &var_ref;
public:
	ConstRef(int val) :var(val), var_const(val), var_ref(var) {};
	void print() const {
		cout << "var: " << var << "\nvar_const: " << var_const << "\nvar_ref: " << var_ref << endl;
	}
};

// 错误的构造函数，不能通过赋值进行初始化
//ConstRef::ConstRef(int val) {
//	var = val;
//	var_const = val; // 错误：常量var_const未被初始化
//	var_ref = var;
//}