#pragma once

#include "global.h"

class PrintString {
private:
	ostream & os;
	char delimiter;
public:
	PrintString(ostream &o = cout, char d = ' ') :os(o), delimiter(d) {}
	// 重载函数调用运算符，使类的行为看起来像函数
	void operator()(const string &s) const { os << s << delimiter; }
};

class divide {
public:
	int operator()(int a, int b) {
		return a / b;
	}
};