#pragma once

#include "global.h"

class StrBlobPtr;

// ���ж�����һ���ڴ���
class StrBlob {
	// ��Ԫ��
	friend class StrBlobPtr;
public:
	using size_type = vector<string>::size_type;

	// ���캯��
	StrBlob();
	StrBlob(initializer_list<string> il);

	// ���ص�ǰ������ָvector�Ĵ�С
	size_type size() const { return data->size(); }
	// �ж��Ƿ�Ϊ��
	bool empty() const { return data->empty(); }

	// ���Ԫ��
	void push_back(const string &s) { data->push_back(s); }
	// ɾ��Ԫ��
	void pop_back();

	// ��ȡvector��Ԫ��
	string &front() { return do_front(); }
	// ��ȡvectorβԪ��
	string &back() { return do_back(); }
	// const���ذ�front
	const string &front() const { return do_front(); }
	// const���ذ�back
	const string &back() const { return do_back(); }

	// ��ȡָ����Ԫ�ص�ָ�������
	StrBlobPtr begin();
	// ��ȡָ��βԪ��֮���ָ�������
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data; // ʹ������ָ��shared_ptr�����ڴ����
	void check(size_type i, const string &msg) const; // ����Ƿ�Խ��

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

// ʹ��weak_ptr��StrBlob������
class StrBlobPtr {
public:
	using size_type = vector<string>::size_type;

	// ���캯��
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &sb, size_type sz = 0) :wptr(sb.data), curr(sz) {}

	// ������
	string &deref() const;
	string &operator*() const;
	string *operator->() const { return &(this->operator*()); } // ����*������ָ�룬ָ�뽫����->


	// ����ָ�루ǰ�ã�
	StrBlobPtr &incr();
	StrBlobPtr &operator++();

	// �ݼ�ָ�루ǰ�ã�
	StrBlobPtr &operator--();

	// ����ָ�루���ã�
	StrBlobPtr &operator++(int); // intֻ��Ϊ������ǰ����

	// �ݼ�ָ�루���ã�
	StrBlobPtr &operator--(int);

	// ָ������ж�
	bool equal(const StrBlobPtr &sbp) const { return this->curr == sbp.curr && (this->wptr).lock().get() == (sbp.wptr).lock().get(); }
	bool operator==(const StrBlobPtr &sbp) const { return this->curr == sbp.curr && (this->wptr).lock().get() == (sbp.wptr).lock().get(); }
	bool operator!=(const StrBlobPtr &sbp) const { return !(*this == sbp); }
private:
	shared_ptr<vector<string>> check(size_type i, const string &s) const;
	weak_ptr<vector<string>> wptr; // �����ã���������shared_ptr����
	size_type curr; // ��ǰ�±�
};

shared_ptr<vector<string>> StrBlobPtr::check(size_type i, const string &s) const {
	auto ret = wptr.lock(); // ���ָ������Ƿ���ڣ�����shared_ptrָ��
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
	check(curr, "decrement past begin of StrBlobPtr"); // ���curr��0������curr���޷��������ݼ�����һ����Ч�ķǳ������
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


// ��Ҫ��StrBlobPtr�������ܶ���begin��end������StrBlobPtr�ǲ���ȫ����

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }