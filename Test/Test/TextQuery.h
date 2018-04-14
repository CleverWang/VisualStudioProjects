#pragma once

#include "global.h"	

class QueryResult;
class TextQuery {
public:
	using line_no = vector<string>::size_type; // 行号
	TextQuery(ifstream &);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file; // 指向输入文件的vector的shared_ptr
	map <string, shared_ptr<set<line_no>>> wm; // 单词到行号set的映射
};

TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) { // 读取一行
		file->push_back(text); // 插入vector中
		line_no n = file->size() - 1; // 行号
		istringstream line(text);
		string word;
		while (line >> word) { // 读取一个单词
			//auto loc = wm.find(word);
			//if (loc == wm.end()) { // 该单词第一次出现
			//	wm.insert({ word,shared_ptr<set<line_no>>(new set<line_no>{n}) }); // 新建行号set并关联
			//}
			//else {
			auto &lines = wm[word]; // 获取关联的行号set的shared_ptr
			if (!lines) { // 该单词第一次出现
				lines.reset(new set<line_no>); // 新建行号set并关联
			}
			lines->insert(n); // 插入该单词所在行号
		//	wm[word]->insert(n); // 插入该单词所在行号
		//}
		}
	}
}

class QueryResult {
	friend ostream& print(ostream &, const QueryResult &);
public:
	using line_no = TextQuery::line_no;
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {}
	set<line_no>::iterator begin() const { return lines->begin(); }
	set<line_no>::iterator end() const { return lines->end(); }
	shared_ptr<vector<string>> get_file() const { return file; }
private:
	string sought; // 需要查找的单词
	shared_ptr<set<line_no>> lines; // 指向行号set的shared_ptr
	shared_ptr<vector<string>> file; // 指向输入文件的vector的shared_ptr
};

QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>); // 静态局部变量，表示未找到
	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		return QueryResult(sought, nodata, file);
	}
	else {
		return QueryResult(sought, loc->second, file);
	}
}

ostream& print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " " << ((qr.lines->size() > 1) ? "times" : "time") << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	}
	return os;
}


class Query;
// 抽象查询基类，封装基本操作
class Query_base {
	friend class Query; // Query需要调用Query_base的虚函数
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0; // 获取查询结果对象
	virtual string rep() const = 0; // 获取当前查询条件
};

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
private:
	Query(shared_ptr<Query_base> query) :q(query) {}
	shared_ptr<Query_base> q;
public:
	Query(const string&);
	QueryResult eval(const TextQuery &t) const { return q->eval(t); } // 实际调用Query_base的eval虚方法
	string rep() const { return q->rep(); } // 实际调用Query_base的rep虚方法
};

ostream &operator<<(ostream &os, const Query &query) {
	return os << query.rep();
}

// 最基础的单词查询类，根据单词直接进行查询
class WordQuery :public Query_base {
	friend class Query; // Query需要访问WordQuery的构造函数
private:
	string query_word; // 需要查询的单词
	WordQuery(const string &s) :query_word(s) {}
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); } // 根据需要查询的单词进行查询，返回结果
	string rep() const { return query_word; }
};

// 等待WordQuery定义完才能定义该构造函数，否则WordQuery是不完全类型
inline Query::Query(const string &s) :q(new WordQuery(s)) {}

// “非”查询，对查询结果取反
class NotQuery :public Query_base {
	friend Query operator~(const Query&);
private:
	Query query;
	NotQuery(const Query &q) :query(q) {}
	QueryResult eval(const TextQuery&) const;
	string rep() const { return "~(" + query.rep() + ")"; }
};

inline Query operator~(const Query &operand) {
	// 隐式调用了Query的Query(shared_ptr<Query_base>)构造函数
	return shared_ptr<Query_base>(new NotQuery(operand));
}

// 二元操作的基类
class BinaryQuery :public Query_base {
protected:
	Query lhs, rhs; // 左、右查询对象
	string opSym; // 二元操作符
	BinaryQuery(const Query &l, const Query &r, string s) :lhs(l), rhs(r), opSym(s) {}
	string rep() const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
};

// “与”查询，返回结果的交集
class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

// “或”查询，返回结果的并集
class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
private:
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const {
	auto result = query.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n) {
			ret_lines->insert(n);
		}
		else if (beg != end) {
			++beg;
		}
	}
	return QueryResult(rep(), ret_lines, result.get_file()); 
}
