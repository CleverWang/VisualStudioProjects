#pragma once

#include "global.h"

// ���࣬��ʾ���������������final������ֹ�̳У�class Quote final��
class Quote {
private:
	string bookNo; // ��ı��
protected: // ������Է��ʸ������ܱ����ĳ�Ա
	double price = 0.0; // �ۼ�
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {}

	string isbn() const { return bookNo; }

	// �麯����������Ը��ǣ�ʵ�ֲ�ͬ���ۿ��㷨����const�������final������ֹ���ǣ�
	virtual double net_price(size_t n) const { return n * price; }

	// ��������������̬��ʱ����ʵ�ʶ��������Ӧ����������
	virtual ~Quote() = default;

	// �������캯��
	Quote(const Quote&) = default;

	// �ƶ����캯��
	Quote(Quote&&) = default;

	// ������ֵ�����
	Quote &operator=(const Quote&) = default;

	// �ƶ���ֵ�����
	Quote &operator=(Quote&&) = default;

	// ��¡������һ�ݣ���ֵ�棩
	virtual Quote *clone() const & { return new Quote(*this); }

	// ��¡������һ�ݣ���ֵ�棩
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
	// ��Ҫ���ø��๹�캯����ʼ����������ݳ�Ա��Ȼ���ٳ�ʼ����������ݳ�Ա
	Bulk_quote(string &b, double p, size_t qty, double disc) :Quote(b, p), min_qty(qty), discount(disc) {}

	double net_price(size_t cnt) const override;
};

// ���������������ָ�������麯���İ汾������Quote::net_price(size_t)��ͨ����������ʹ�ã��ȵ��ø������һЩ������Ȼ����ִ����������
double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= min_qty) {
		return cnt * (1 - discount)*price;
	}
	else {
		return cnt * price;
	}
}*/

// ������࣬���幫�������ݺͲ���
class Disc_quote :public Quote { // public��ʾ��Quote�̳����ĳ�Ա������ԭ���ķ����ԣ������private��ʾ�̳����Ķ������private��protectedͬ�����˴��ķ��ʷ����Ƶ����û��ķ���Ȩ�ޣ�������Ը����Ա�ķ�����ֻ�ܸ�����ʷ��Ŀ��ƣ�
// ����ͨ��using�ı�Ӹ���̳����Ŀɷ��ʳ�Ա�ķ����ԣ�����Quote��private�̳У���price�����private����protected��ʹ��using Quote::price��price�����protected
protected:
	size_t quantity = 0;
	double discount = 0.0;
public:
	Disc_quote() = default;
	Disc_quote(const string &b, double p, size_t qty, double disc) :Quote(b, p), quantity(qty), discount(disc) {}

	// ���麯��
	double net_price(size_t cnt) const = 0;

	// ������������ֻ�����ͷ��Լ��������Դ�������������������Զ����ã������ż̳нṹ�ӵ��������ε�����������
	~Disc_quote() {}

	// ��Ҫ���ø���Ŀ������캯������ɸ��ಿ�ֵĿ�����ʼ��
	Disc_quote(const Disc_quote &d) :Quote(d), quantity(d.quantity), discount(d.discount) {}

	// ��Ҫ���ø�����ƶ����캯������ɸ��ಿ�ֵ��ƶ�
	Disc_quote(Disc_quote &&d) :Quote(std::move(d)), quantity(d.quantity), discount(d.discount) {}

	// ��Ҫ���ø���Ŀ�����ֵ���������ɸ��ಿ�ֵĿ�����ֵ
	Disc_quote &operator=(const Disc_quote &d) { Quote::operator=(d); quantity = d.quantity; discount = d.discount; return *this; }

	// ��Ҫ���ø�����ƶ���ֵ���������ɸ��ಿ�ֵ��ƶ���ֵ
	Disc_quote &operator=(Disc_quote &&d) { if (this != &d) { Quote::operator=(std::move(d)); quantity = d.quantity; discount = d.discount; } return *this; }
};

// �̳��Գ������Disc_quote
class Bulk_quote :public Disc_quote {
public:
	Bulk_quote() = default;
	// ����ʹ��using�̳и��๹�캯�������������Զ��ϳ��������µĹ��캯����derived(params):base(args){}
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