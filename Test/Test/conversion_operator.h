#pragma once

#include "global.h"

class SmallInt {
private:
	size_t val;
public:
	// ������int��SmallInt����ʽ����ת��
	SmallInt(int i = 0) :val(i) {
		if (i < 0 || i > 255) throw out_of_range("Bad SmallInt value");
	}
	// ����SmallInt��intת������ʽ����ת�������
	operator int() const { return val; }
	// ����SmallInt��intת������ʽ����ת�������������ʹ������ת��static_cast<int>()����ת���������������ж������Զ�ִ�У�����if(cin>>i)
	// explicit operator int() const { return val; }
	explicit operator bool() const { return val; }
};
