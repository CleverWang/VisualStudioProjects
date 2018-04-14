#pragma once

#include "global.h"

struct Sales_data_struct
{
	string bookNo; // 书的ISBN编号
	unsigned units_sold = 0; // 书的销量
	double revenue = 0.0; // 书的总销售额

	Sales_data_struct() = default; // 默认构造函数
	Sales_data_struct(const string &s) :bookNo(s) {}; // bookNo使用初始化参数，其他的使用默认初始化值
	Sales_data_struct(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {};
	Sales_data_struct(istream &);

	// 返回ISBN编号（在类内部定义，默认inline）
	string isbn() const { return bookNo; }

	// 将一个Sales_data_struct对象加到另一个Sales_data_struct对象上
	Sales_data_struct& combine(const Sales_data_struct&);

	// 书的平均价格
	double avg_price() const;
};

// 执行两个Sales_data_struct对象的相加
Sales_data_struct add(const Sales_data_struct&, const Sales_data_struct&);

// 从istream输入数据到Sales_data_struct对象
istream &read(istream&, Sales_data_struct&);

// 将Sales_data_struct对象的值输出到ostream流
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