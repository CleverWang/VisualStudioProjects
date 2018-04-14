#pragma once

#include "global.h"

class NoCopy {
private:
	string s;
public:
	NoCopy() = default; // ʹ�ñ������ϳɵ�Ĭ�Ϲ��캯��
	NoCopy(const string &str) :s(str) {}

	NoCopy(const NoCopy &) = delete; // ��ֹ����
	NoCopy &operator=(const NoCopy &) = delete; // ��ֹ��ֵ����
	~NoCopy() = default; // ʹ�ñ������ϳɵ���������

	ostream &print_NoCopy(ostream &os) {
		os << "string: " << s;
		return os;
	}
};