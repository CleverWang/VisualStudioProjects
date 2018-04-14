#pragma once

#include "global.h"

// 使类的行为看起来像值
class HasPtr {
	friend void swap(HasPtr &lhs, HasPtr &rhs);
private:
	string * ps;
	int i;
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	ostream &print_HasPtr(ostream &os) { os << "string: " << *ps << " i: " << i; return os; }

	// 有析构函数一般也需要拷贝构造函数和拷贝赋值运算符
	// 有拷贝构造函数一般也需要拷贝赋值运算符，反之亦然

	~HasPtr() { delete ps; }
	HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i) {}
	// 注意能自己给自己赋值，组合了析构和拷贝（先销毁左侧再拷贝右侧）
	// HasPtr &operator=(const HasPtr &hp) { auto newps = new string(*hp.ps); delete ps; ps = newps; i = hp.i; return *this; }

	// 移动构造函数
	HasPtr(HasPtr &&hp) :ps(hp.ps), i(hp.i) { hp.ps = 0; }
	// 既是移动赋值运算符也是拷贝赋值运算符，形参先对实参进行拷贝或移动，然后执行swap
	HasPtr &operator=(HasPtr hp) { swap(*this, hp); return *this; }
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

// 使用swap的赋值拷贝运算符
//HasPtr &HasPtr::operator=(HasPtr hp) {
//	swap(*this, hp);
//	return *this;
//}

// 使类的行为看起来像指针
//class HasPtr {
//private:
//	string *ps;
//	int i;
//	size_t *use;
//public:
//	HasPtr(const string &s = string()) :ps(new string(s)), i(0), use(new size_t(1)) {} // 新建对象，创建初始引用计数
//	ostream &print_HasPtr(ostream &os) { os << "string: " << *ps << " i: " << i << " use: " << *use; return os; }
//
//	~HasPtr();
//	HasPtr(const HasPtr &hp) :ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
//	HasPtr &operator=(const HasPtr &);
//};
//
//HasPtr::~HasPtr() {
//	if (--*use == 0) { // 递减引用计数，如果为0，销毁所管理的内容
//		delete ps;
//		delete use;
//	}
//}
//
//HasPtr &HasPtr::operator=(const HasPtr &hp) {
//	++*hp.use; // 递增右侧对象引用计数
//	if (--*use == 0) { // 递减左侧引用计数，如果为0，销毁左侧对象所管理的内容
//		delete ps;
//		delete use;
//	}
//	ps = hp.ps;
//	i = hp.i;
//	use = hp.use;
//	return *this;
//}