#pragma once

#include "global.h"

class StrBlobPtr;

// 所有对象共用一个内存区
class StrBlob {
	// 友元类
	friend class StrBlobPtr;
public:
	using size_type = vector<string>::size_type;

	// 构造函数
	StrBlob();
	StrBlob(initializer_list<string> il);

	// 返回当前对象所指vector的大小
	size_type size() const { return data->size(); }
	// 判断是否为空
	bool empty() const { return data->empty(); }

	// 添加元素
	void push_back(const string &s) { data->push_back(s); }
	// 删除元素
	void pop_back();

	// 获取vector首元素
	string &front() { return do_front(); }
	// 获取vector尾元素
	string &back() { return do_back(); }
	// const重载版front
	const string &front() const { return do_front(); }
	// const重载版back
	const string &back() const { return do_back(); }

	// 获取指向首元素的指针迭代器
	StrBlobPtr begin();
	// 获取指向尾元素之后的指针迭代器
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data; // 使用智能指针shared_ptr进行内存管理
	void check(size_type i, const string &msg) const; // 检查是否越界

	string &do_front() const;
	string &do_back() const;
};

StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string &StrBlob::do_front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

string &StrBlob::do_back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}

// 使用weak_ptr的StrBlob伴随类
class StrBlobPtr {
public:
	using size_type = vector<string>::size_type;

	// 构造函数
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &sb, size_type sz = 0) :wptr(sb.data), curr(sz) {}

	// 解引用
	string &deref() const;
	string &operator*() const;
	string *operator->() const { return &(this->operator*()); } // 调用*，返回指针，指针将继续->


	// 递增指针（前置）
	StrBlobPtr &incr();
	StrBlobPtr &operator++();

	// 递减指针（前置）
	StrBlobPtr &operator--();

	// 递增指针（后置）
	StrBlobPtr &operator++(int); // int只是为了区分前后置

	// 递减指针（后置）
	StrBlobPtr &operator--(int);

	// 指针相等判断
	bool equal(const StrBlobPtr &sbp) const { return this->curr == sbp.curr && (this->wptr).lock().get() == (sbp.wptr).lock().get(); }
	bool operator==(const StrBlobPtr &sbp) const { return this->curr == sbp.curr && (this->wptr).lock().get() == (sbp.wptr).lock().get(); }
	bool operator!=(const StrBlobPtr &sbp) const { return !(*this == sbp); }
private:
	shared_ptr<vector<string>> check(size_type i, const string &s) const;
	weak_ptr<vector<string>> wptr; // 弱引用，不会增加shared_ptr计数
	size_type curr; // 当前下标
};

shared_ptr<vector<string>> StrBlobPtr::check(size_type i, const string &s) const {
	auto ret = wptr.lock(); // 检查指向对象是否存在，返回shared_ptr指针
	if (!ret) {
		throw runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size()) {
		throw out_of_range(s);
	}
	return ret;
}

string &StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

string &StrBlobPtr::operator*() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr &StrBlobPtr::operator++() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
	--curr;
	check(curr, "decrement past begin of StrBlobPtr"); // 如果curr是0，由于curr是无符号数，递减后是一个无效的非常大的数
	return *this;
}

StrBlobPtr &StrBlobPtr::operator++(int) {
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}

StrBlobPtr &StrBlobPtr::operator--(int) {
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}


// 需要等StrBlobPtr定义后才能定义begin和end，否则StrBlobPtr是不完全类型

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }