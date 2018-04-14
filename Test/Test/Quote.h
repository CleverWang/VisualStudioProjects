#pragma once

#include "global.h"

// 基类，表示不打折情况（加上final可以阻止继承：class Quote final）
class Quote {
private:
	string bookNo; // 书的编号
protected: // 子类可以访问父类中受保护的成员
	double price = 0.0; // 售价
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {}

	string isbn() const { return bookNo; }

	// 虚函数，子类可以覆盖，实现不同的折扣算法（在const后面加上final可以阻止覆盖）
	virtual double net_price(size_t n) const { return n * price; }

	// 虚析构函数，动态绑定时根据实际对象调用相应的析构函数
	virtual ~Quote() = default;

	// 拷贝构造函数
	Quote(const Quote&) = default;

	// 移动构造函数
	Quote(Quote&&) = default;

	// 拷贝赋值运算符
	Quote &operator=(const Quote&) = default;

	// 移动赋值运算符
	Quote &operator=(Quote&&) = default;

	// 克隆本对象一份（左值版）
	virtual Quote *clone() const & { return new Quote(*this); }

	// 克隆本对象一份（右值版）
	virtual Quote *clone() && {return new Quote(std::move(*this)); }
};

double print_total(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

/*class Bulk_quote :public Quote {
private:
	size_t min_qty = 0;
	double discount = 0.0;
public:
	Bulk_quote() = default;
	// 需要调用父类构造函数初始化父类的数据成员，然后再初始化子类的数据成员
	Bulk_quote(string &b, double p, size_t qty, double disc) :Quote(b, p), min_qty(qty), discount(disc) {}

	double net_price(size_t cnt) const override;
};

// 加上域运算符可以指定调用虚函数的版本，比如Quote::net_price(size_t)，通常在子类中使用，先调用父类完成一些操作，然后再执行其他操作
double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= min_qty) {
		return cnt * (1 - discount)*price;
	}
	else {
		return cnt * price;
	}
}*/

// 抽象基类，定义公共的数据和操作
class Disc_quote :public Quote { // public表示从Quote继承来的成员将保持原来的访问性，如果是private表示继承来的都将变成private，protected同理（即此处的访问符控制的是用户的访问权限，而子类对父类成员的访问性只受父类访问符的控制）
// 可以通过using改变从父类继承来的可访问成员的访问性，假如Quote是private继承，则price将变成private，在protected下使用using Quote::price，price将变成protected
protected:
	size_t quantity = 0;
	double discount = 0.0;
public:
	Disc_quote() = default;
	Disc_quote(const string &b, double p, size_t qty, double disc) :Quote(b, p), quantity(qty), discount(disc) {}

	// 纯虚函数
	double net_price(size_t cnt) const = 0;

	// 子类析构函数只负责释放自己分配的资源，父类析构函数将被自动调用，即沿着继承结构从底向上依次调用析构函数
	~Disc_quote() {}

	// 需要调用父类的拷贝构造函数，完成父类部分的拷贝初始化
	Disc_quote(const Disc_quote &d) :Quote(d), quantity(d.quantity), discount(d.discount) {}

	// 需要调用父类的移动构造函数，完成父类部分的移动
	Disc_quote(Disc_quote &&d) :Quote(std::move(d)), quantity(d.quantity), discount(d.discount) {}

	// 需要调用父类的拷贝赋值运算符，完成父类部分的拷贝赋值
	Disc_quote &operator=(const Disc_quote &d) { Quote::operator=(d); quantity = d.quantity; discount = d.discount; return *this; }

	// 需要调用父类的移动赋值运算符，完成父类部分的移动赋值
	Disc_quote &operator=(Disc_quote &&d) { if (this != &d) { Quote::operator=(std::move(d)); quantity = d.quantity; discount = d.discount; } return *this; }
};

// 继承自抽象基类Disc_quote
class Bulk_quote :public Disc_quote {
public:
	Bulk_quote() = default;
	// 可以使用using继承父类构造函数，编译器将自动合成形如以下的构造函数：derived(params):base(args){}
	// using Disc_quote::Disc_quote;
	Bulk_quote(const string &b, double p, size_t qty, double disc) :Disc_quote(b, p, qty, disc) {}

	double net_price(size_t cnt) const override;

	~Bulk_quote() {}
	Bulk_quote(const Bulk_quote &b) :Disc_quote(b) {}
	Bulk_quote(Bulk_quote &&b) :Disc_quote(std::move(b)) {}
	Bulk_quote &operator=(const Bulk_quote &b) { Disc_quote::operator=(b); return *this; }
	Bulk_quote &operator=(Bulk_quote &&b) { if (this != &b) { Disc_quote::operator=(std::move(b)); } return *this; }
	Bulk_quote *clone() const & { return new Bulk_quote(*this); }
	Bulk_quote *clone() && {return new Bulk_quote(std::move(*this)); }
};

double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= quantity) {
		return cnt * (1 - discount)*price;
	}
	else {
		return cnt * price;
	}
}

class Basket {
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
public:
	void add_item(const shared_ptr<Quote> &sale) { items.insert(sale); }
	void add_item(const Quote &q) { items.insert(shared_ptr<Quote>(q.clone())); }
	void add_item(Quote &&q) { items.insert(shared_ptr<Quote>(std::move(q).clone())); }
	double total_receipt(ostream &os) const;
};

double Basket::total_receipt(ostream &os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}