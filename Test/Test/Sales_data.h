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
	string bookNo; // 书的ISBN编号
	unsigned units_sold = 0; // 书的销量
	double revenue = 0.0; // 书的总销售额

	//书的平均价格
	double avg_price() const {
		return (units_sold) ? (revenue / units_sold) : 0;
	}
public:
	Sales_data() = default; // 默认构造函数
	// bookNo使用初始化参数，其他的使用默认初始化值
	Sales_data(const string &s) :bookNo(s) {}; // 接受一个实参的构造函数定义了一条隐式类型转换规则（此处将string转换成Sales_data)
	// Sales_data(string s = "") :bookNo(s) {}; // 将上面两个构造函数合二为一（如果一个构造函数为所有的形参提供默认值，则该构造函数其实就是默认构造函数）
	Sales_data(istream &); // 隐式类型转换规则（istream转换成Sales_data）
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {};

	// explicit关键字可以阻止隐式类型转换，即该构造函数是显式构造函数，但是可以使用static_cast进行强制类型转换
	// explicit Sales_data(const string &s) :bookNo(s) {};
	// explicit Sales_data(istream &);

	// 委托构造函数（构造函数可以把自己的职责委托给其他构造函数）
	/*Sales_data() :Sales_data("", 0, 0);
	Sales_data(const string &s) :Sales_data(s, 0, 0) {};
	Sales_data(istream &is) :Sales_data() {
		read(is, *this);
	}*/

	// 返回ISBN编号
	string isbn() const { return bookNo; }

	// 将一个Sales_data对象加到另一个Sales_data对象上
	Sales_data& combine(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);

	// 拷贝构造函数（当用一个对象初始化另一个同类型的对象时，将调用拷贝构造函数）
	Sales_data(const Sales_data &orig) :bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) {}

	// 拷贝赋值运算符（当用一个对象赋值另一个同类型的对象时，将调用拷贝赋值运算符）
	Sales_data &operator=(const Sales_data&rhs) {
		bookNo = rhs.bookNo;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}

	// 析构函数（先执行函数体，再按成员初始化时的顺序逆序销毁成员）
	~Sales_data() {}
};

namespace std { // 打开std命名空间，添加自定义的东西
	template<>
	class hash<Sales_data> { // 特例化std::hash<class T>（类模板特例化，也可以部分特例化，也可以只特例化类模板的成员）
	public:
		// 散列一个无序容器类型需要定义以下类型
		typedef size_t result_type; // 调用运算返回的结果类型
		typedef Sales_data argument_type; // 调用运算的参数类型
		size_t operator()(const Sales_data &s) const { // 重载调用运算符
			return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
		}
		// 使用默认的构造函数和合成的拷贝赋值运算符
	};
} // 关闭std命名空间

// 需要在类外声明友元函数，在类内的声明只是指定了访问权限

// 执行两个Sales_data对象的相加
Sales_data add(const Sales_data&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);


// 从istream输入数据到Sales_data对象
istream &read(istream&, Sales_data&);
istream &operator>>(istream&, Sales_data&);


// 将Sales_data对象的值输出到ostream流
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
