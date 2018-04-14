#pragma once

#include "global.h"

// 简易版vector
class StrVec {
private:
	allocator<string> alloc; // 动态内存分配器
	// 检查是否需要重新分配内存
	void chk_n_alloc() { if (size() == capacity()) { reallocate(); } }
	// 工具函数，根据指定范围分配内存，然后用指定范围的元素拷贝初始化到已分配的内存
	pair<string*, string*> alloc_n_copy(const string *, const string*);
	// 销毁元素并释放空间
	void free();
	// 获得更多内存空间并拷贝元素
	void reallocate();

	string *elements; // 指向首元素
	string *first_free; // 指向第一个空闲元素
	string *cap; // 指向总的可用空间的尾后位置
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}

	// 拷贝左值，移动右值（如果定义了拷贝但没有定义移动操作，编译器不会合成移动，会用拷贝代替移动，即使调用了std::move也是如此）

	StrVec(const StrVec&); // 拷贝构造函数
	StrVec(StrVec &&) noexcept; // 移动构造函数
	StrVec &operator=(const StrVec&); // 拷贝赋值运算符
	StrVec &operator=(StrVec &&) noexcept; // 移动赋值运算符
	StrVec &operator=(initializer_list<string>);
	~StrVec(); // 析构函数

	void push_back(const string&); // 拷贝版
	void push_back(string &&); // 移动版
	template<typename ...Args> void emplace_back(Args&& ...);

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }

	string *begin() const { return elements; }
	string *end() const { return first_free; }

	// 重载下标运算符，非常量版本和常量版本

	string &operator[](size_t i) { return elements[i]; }
	const string &operator[](size_t i) const { return elements[i]; }
};

void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

template<typename ...Args> inline void StrVec::emplace_back(Args&& ...args) {
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...); // 把每个参数的类型信息通过转发保留下来
}


pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);
	auto start_data = data;
	while (b != e) {
		alloc.construct(data++, *b++);
	}
	//return { data,uninitialized_copy(b,e,data) };
	return { start_data,data };
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept:elements(s.elements), first_free(s.first_free), cap(s.cap) { // 成员初始化器接管资源
	s.elements = s.first_free = s.cap = nullptr; // 另右值引用进入这样的状态——对其进行析构是安全的
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs) { // 直接判断自赋值情况
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}


StrVec &StrVec::operator=(initializer_list<string> il) {
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}


void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata, elem = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++)); // std::move将一个左值转换成一个右值引用，且移动后的对象是安全的
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
