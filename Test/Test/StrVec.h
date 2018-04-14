#pragma once

#include "global.h"

// ���װ�vector
class StrVec {
private:
	allocator<string> alloc; // ��̬�ڴ������
	// ����Ƿ���Ҫ���·����ڴ�
	void chk_n_alloc() { if (size() == capacity()) { reallocate(); } }
	// ���ߺ���������ָ����Χ�����ڴ棬Ȼ����ָ����Χ��Ԫ�ؿ�����ʼ�����ѷ�����ڴ�
	pair<string*, string*> alloc_n_copy(const string *, const string*);
	// ����Ԫ�ز��ͷſռ�
	void free();
	// ��ø����ڴ�ռ䲢����Ԫ��
	void reallocate();

	string *elements; // ָ����Ԫ��
	string *first_free; // ָ���һ������Ԫ��
	string *cap; // ָ���ܵĿ��ÿռ��β��λ��
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}

	// ������ֵ���ƶ���ֵ����������˿�����û�ж����ƶ�����������������ϳ��ƶ������ÿ��������ƶ�����ʹ������std::moveҲ����ˣ�

	StrVec(const StrVec&); // �������캯��
	StrVec(StrVec &&) noexcept; // �ƶ����캯��
	StrVec &operator=(const StrVec&); // ������ֵ�����
	StrVec &operator=(StrVec &&) noexcept; // �ƶ���ֵ�����
	StrVec &operator=(initializer_list<string>);
	~StrVec(); // ��������

	void push_back(const string&); // ������
	void push_back(string &&); // �ƶ���
	template<typename ...Args> void emplace_back(Args&& ...);

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }

	string *begin() const { return elements; }
	string *end() const { return first_free; }

	// �����±���������ǳ����汾�ͳ����汾

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
	alloc.construct(first_free++, std::forward<Args>(args)...); // ��ÿ��������������Ϣͨ��ת����������
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

StrVec::StrVec(StrVec &&s) noexcept:elements(s.elements), first_free(s.first_free), cap(s.cap) { // ��Ա��ʼ�����ӹ���Դ
	s.elements = s.first_free = s.cap = nullptr; // ����ֵ���ý���������״̬����������������ǰ�ȫ��
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
	if (this != &rhs) { // ֱ���ж��Ը�ֵ���
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
		alloc.construct(dest++, std::move(*elem++)); // std::move��һ����ֵת����һ����ֵ���ã����ƶ���Ķ����ǰ�ȫ��
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
