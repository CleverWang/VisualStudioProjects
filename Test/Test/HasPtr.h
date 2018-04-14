#pragma once

#include "global.h"

// ʹ�����Ϊ��������ֵ
class HasPtr {
	friend void swap(HasPtr &lhs, HasPtr &rhs);
private:
	string * ps;
	int i;
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	ostream &print_HasPtr(ostream &os) { os << "string: " << *ps << " i: " << i; return os; }

	// ����������һ��Ҳ��Ҫ�������캯���Ϳ�����ֵ�����
	// �п������캯��һ��Ҳ��Ҫ������ֵ���������֮��Ȼ

	~HasPtr() { delete ps; }
	HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i) {}
	// ע�����Լ����Լ���ֵ������������Ϳ���������������ٿ����Ҳࣩ
	// HasPtr &operator=(const HasPtr &hp) { auto newps = new string(*hp.ps); delete ps; ps = newps; i = hp.i; return *this; }

	// �ƶ����캯��
	HasPtr(HasPtr &&hp) :ps(hp.ps), i(hp.i) { hp.ps = 0; }
	// �����ƶ���ֵ�����Ҳ�ǿ�����ֵ��������β��ȶ�ʵ�ν��п������ƶ���Ȼ��ִ��swap
	HasPtr &operator=(HasPtr hp) { swap(*this, hp); return *this; }
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

// ʹ��swap�ĸ�ֵ���������
//HasPtr &HasPtr::operator=(HasPtr hp) {
//	swap(*this, hp);
//	return *this;
//}

// ʹ�����Ϊ��������ָ��
//class HasPtr {
//private:
//	string *ps;
//	int i;
//	size_t *use;
//public:
//	HasPtr(const string &s = string()) :ps(new string(s)), i(0), use(new size_t(1)) {} // �½����󣬴�����ʼ���ü���
//	ostream &print_HasPtr(ostream &os) { os << "string: " << *ps << " i: " << i << " use: " << *use; return os; }
//
//	~HasPtr();
//	HasPtr(const HasPtr &hp) :ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
//	HasPtr &operator=(const HasPtr &);
//};
//
//HasPtr::~HasPtr() {
//	if (--*use == 0) { // �ݼ����ü��������Ϊ0�����������������
//		delete ps;
//		delete use;
//	}
//}
//
//HasPtr &HasPtr::operator=(const HasPtr &hp) {
//	++*hp.use; // �����Ҳ�������ü���
//	if (--*use == 0) { // �ݼ�������ü��������Ϊ0�����������������������
//		delete ps;
//		delete use;
//	}
//	ps = hp.ps;
//	i = hp.i;
//	use = hp.use;
//	return *this;
//}