#pragma once

#include "global.h"

// 模板类的声明和定义一般放在同一个头文件中，而普通函数的声明和普通类的定义一般放在头文件中，普通函数的定义和普通类的成员函数的定义一般放在源文件中

template <typename T>
class Blob {
public:
	using value_type = T;
	using size_type = typename vector<T>::size_type; // 使用::运算符时（访问类型成员和static成员），typename可以告诉编译器后面的名字是一个类型，否则编译器默认名字不是一个类型

	Blob();
	Blob(initializer_list<T> il);
	// 类模板的成员模板构造函数（即类模板中可以有模板函数）
	template <typename It> Blob(It b, It e);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T &t) { data->push_back(t); }
	void pop_back();

	T &back();
	T &front();
	T &operator[](size_type i);

	// const重载版本

	const T &back() const;
	const T &front() const;
	const T &operator[](size_type i) const;
private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string &msg) const;
};

template <typename T>
Blob<T>::Blob() :data(make_shared<vector<T>>()) {}

template <typename T>
Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

template <typename T>
template <typename It> Blob<T>::Blob(It b, It e) : data(make_shared<vector<T>>(b, e)) {}

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}

template <typename T>
T &Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T &Blob<T>::front() {
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T &Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T &Blob<T>::back() const {
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
const T &Blob<T>::front() const {
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T &Blob<T>::operator[](size_type i) const {
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
class BlobPtr {
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &b, size_t sz = 0) :wptr(b.data), curr(sz) {}

	T &operator*() const { auto p = check(curr, "dereference past end"); return (*p)[curr]; }

	// 在模板作用域里面我们可以直接使用模板名而不必指定模板实参，下面的BlobPtr等价于BlobPtr<T>

	BlobPtr &operator++();
	BlobPtr &operator--();
	BlobPtr &operator++(int);
	BlobPtr &operator--(int);
private:
	shared_ptr<vector<T>> check(size_t i, const string &s) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

// 在模板作用域外面定义函数时，需要指定模板实参直到进入模板作用域(::之前）

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &s) const {
	auto ret = wptr.lock();
	if (!ret) {
		throw runtime_error("unbound BlobPtr");
	}
	if (i >= ret->size()) {
		throw out_of_range(s);
	}
	return ret;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
	--curr;
	check(curr, "decrement past begin of BlobPtr");
	return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++(int) {
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--(int) {
	BlobPtr ret = *this;
	--*this;
	return ret;
}