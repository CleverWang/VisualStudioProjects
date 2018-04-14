#pragma once

#include "global.h"

struct Sales_data_struct
{
	string bookNo; // ���ISBN���
	unsigned units_sold = 0; // �������
	double revenue = 0.0; // ��������۶�

	Sales_data_struct() = default; // Ĭ�Ϲ��캯��
	Sales_data_struct(const string &s) :bookNo(s) {}; // bookNoʹ�ó�ʼ��������������ʹ��Ĭ�ϳ�ʼ��ֵ
	Sales_data_struct(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {};
	Sales_data_struct(istream &);

	// ����ISBN��ţ������ڲ����壬Ĭ��inline��
	string isbn() const { return bookNo; }

	// ��һ��Sales_data_struct����ӵ���һ��Sales_data_struct������
	Sales_data_struct& combine(const Sales_data_struct&);

	// ���ƽ���۸�
	double avg_price() const;
};

// ִ������Sales_data_struct��������
Sales_data_struct add(const Sales_data_struct&, const Sales_data_struct&);

// ��istream�������ݵ�Sales_data_struct����
istream &read(istream&, Sales_data_struct&);

// ��Sales_data_struct�����ֵ�����ostream��
ostream &print(ostream&, const Sales_data_struct&);

Sales_data_struct::Sales_data_struct(istream &is)
{
	read(is, *this);
}

Sales_data_struct& Sales_data_struct::combine(const Sales_data_struct &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data_struct::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data_struct add(const Sales_data_struct &lhs, const Sales_data_struct &rhs)
{
	Sales_data_struct sum = lhs;
	sum.combine(rhs);
	return sum;
}

istream &read(istream &is, Sales_data_struct &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data_struct &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}