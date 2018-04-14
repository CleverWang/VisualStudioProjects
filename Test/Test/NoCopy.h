#pragma once

#include "global.h"

class NoCopy {
private:
	string s;
public:
	NoCopy() = default; // 使用编译器合成的默认构造函数
	NoCopy(const string &str) :s(str) {}

	NoCopy(const NoCopy &) = delete; // 阻止拷贝
	NoCopy &operator=(const NoCopy &) = delete; // 阻止赋值拷贝
	~NoCopy() = default; // 使用编译器合成的析构函数

	ostream &print_NoCopy(ostream &os) {
		os << "string: " << s;
		return os;
	}
};