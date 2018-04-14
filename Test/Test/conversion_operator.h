#pragma once

#include "global.h"

class SmallInt {
private:
	size_t val;
public:
	// 定义了int向SmallInt的隐式类型转换
	SmallInt(int i = 0) :val(i) {
		if (i < 0 || i > 255) throw out_of_range("Bad SmallInt value");
	}
	// 定义SmallInt向int转换的隐式类型转换运算符
	operator int() const { return val; }
	// 定义SmallInt向int转换的显式类型转换运算符，必须使用类型转换static_cast<int>()进行转换，但是在条件判断中能自动执行，比如if(cin>>i)
	// explicit operator int() const { return val; }
	explicit operator bool() const { return val; }
};
