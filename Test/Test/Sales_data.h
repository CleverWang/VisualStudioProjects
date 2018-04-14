#pragma once

#include "global.h"

template <typename T> class std::hash;

class Sales_data{
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);

	friend istream &read(istream&, Sales_data&);
	friend istream &operator>>(istream&, Sales_data&);

	friend ostream &print(ostream&, const Sales_data&);
	friend ostream &operator<<(ostream&, const Sales_data&);

	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);

	friend class std::hash<Sales_data>;
private:
	string bookNo; // ���ISBN���
	unsigned units_sold = 0; // �������
	double revenue = 0.0; // ��������۶�

	//���ƽ���۸�
	double avg_price() const {
		return (units_sold) ? (revenue / units_sold) : 0;
	}
public:
	Sales_data() = default; // Ĭ�Ϲ��캯��
	// bookNoʹ�ó�ʼ��������������ʹ��Ĭ�ϳ�ʼ��ֵ
	Sales_data(const string &s) :bookNo(s) {}; // ����һ��ʵ�εĹ��캯��������һ����ʽ����ת�����򣨴˴���stringת����Sales_data)
	// Sales_data(string s = "") :bookNo(s) {}; // �������������캯���϶�Ϊһ�����һ�����캯��Ϊ���е��β��ṩĬ��ֵ����ù��캯����ʵ����Ĭ�Ϲ��캯����
	Sales_data(istream &); // ��ʽ����ת������istreamת����Sales_data��
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {};

	// explicit�ؼ��ֿ�����ֹ��ʽ����ת�������ù��캯������ʽ���캯�������ǿ���ʹ��static_cast����ǿ������ת��
	// explicit Sales_data(const string &s) :bookNo(s) {};
	// explicit Sales_data(istream &);

	// ί�й��캯�������캯�����԰��Լ���ְ��ί�и��������캯����
	/*Sales_data() :Sales_data("", 0, 0);
	Sales_data(const string &s) :Sales_data(s, 0, 0) {};
	Sales_data(istream &is) :Sales_data() {
		read(is, *this);
	}*/

	// ����ISBN���
	string isbn() const { return bookNo; }

	// ��һ��Sales_data����ӵ���һ��Sales_data������
	Sales_data& combine(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);

	// �������캯��������һ�������ʼ����һ��ͬ���͵Ķ���ʱ�������ÿ������캯����
	Sales_data(const Sales_data &orig) :bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) {}

	// ������ֵ�����������һ������ֵ��һ��ͬ���͵Ķ���ʱ�������ÿ�����ֵ�������
	Sales_data &operator=(const Sales_data&rhs) {
		bookNo = rhs.bookNo;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}

	// ������������ִ�к����壬�ٰ���Ա��ʼ��ʱ��˳���������ٳ�Ա��
	~Sales_data() {}
};

namespace std { // ��std�����ռ䣬����Զ���Ķ���
	template<>
	class hash<Sales_data> { // ������std::hash<class T>����ģ����������Ҳ���Բ�����������Ҳ����ֻ��������ģ��ĳ�Ա��
	public:
		// ɢ��һ����������������Ҫ������������
		typedef size_t result_type; // �������㷵�صĽ������
		typedef Sales_data argument_type; // ��������Ĳ�������
		size_t operator()(const Sales_data &s) const { // ���ص��������
			return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
		}
		// ʹ��Ĭ�ϵĹ��캯���ͺϳɵĿ�����ֵ�����
	};
} // �ر�std�����ռ�

// ��Ҫ������������Ԫ�����������ڵ�����ֻ��ָ���˷���Ȩ��

// ִ������Sales_data��������
Sales_data add(const Sales_data&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);


// ��istream�������ݵ�Sales_data����
istream &read(istream&, Sales_data&);
istream &operator>>(istream&, Sales_data&);


// ��Sales_data�����ֵ�����ostream��
ostream &print(ostream&, const Sales_data&);
ostream &operator<<(ostream&, const Sales_data&);

bool operator==(const Sales_data&, const Sales_data&);
bool operator!=(const Sales_data&, const Sales_data&);

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.bookNo == rhs.bookNo&&lhs.revenue == rhs.revenue&&lhs.units_sold == rhs.units_sold;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
	return !(lhs == rhs);
}

Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	// sum += rhs;
	return sum;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	// sum.combine(rhs);
	sum += rhs;
	return sum;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

istream &operator>>(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is) {
		item.revenue = price * item.units_sold;
	}
	else {
		item = Sales_data();
	}
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

ostream &operator<<(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
