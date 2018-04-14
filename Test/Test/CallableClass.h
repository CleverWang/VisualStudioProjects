#pragma once

#include "global.h"

class PrintString {
private:
	ostream & os;
	char delimiter;
public:
	PrintString(ostream &o = cout, char d = ' ') :os(o), delimiter(d) {}
	// ���غ��������������ʹ�����Ϊ����������
	void operator()(const string &s) const { os << s << delimiter; }
};

class divide {
public:
	int operator()(int a, int b) {
		return a / b;
	}
};