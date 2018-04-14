#pragma once

#include "global.h"	

class QueryResult;
class TextQuery {
public:
	using line_no = vector<string>::size_type; // �к�
	TextQuery(ifstream &);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file; // ָ�������ļ���vector��shared_ptr
	map <string, shared_ptr<set<line_no>>> wm; // ���ʵ��к�set��ӳ��
};

TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) { // ��ȡһ��
		file->push_back(text); // ����vector��
		line_no n = file->size() - 1; // �к�
		istringstream line(text);
		string word;
		while (line >> word) { // ��ȡһ������
			//auto loc = wm.find(word);
			//if (loc == wm.end()) { // �õ��ʵ�һ�γ���
			//	wm.insert({ word,shared_ptr<set<line_no>>(new set<line_no>{n}) }); // �½��к�set������
			//}
			//else {
			auto &lines = wm[word]; // ��ȡ�������к�set��shared_ptr
			if (!lines) { // �õ��ʵ�һ�γ���
				lines.reset(new set<line_no>); // �½��к�set������
			}
			lines->insert(n); // ����õ��������к�
		//	wm[word]->insert(n); // ����õ��������к�
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
	string sought; // ��Ҫ���ҵĵ���
	shared_ptr<set<line_no>> lines; // ָ���к�set��shared_ptr
	shared_ptr<vector<string>> file; // ָ�������ļ���vector��shared_ptr
};

QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>); // ��̬�ֲ���������ʾδ�ҵ�
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
// �����ѯ���࣬��װ��������
class Query_base {
	friend class Query; // Query��Ҫ����Query_base���麯��
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0; // ��ȡ��ѯ�������
	virtual string rep() const = 0; // ��ȡ��ǰ��ѯ����
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
	QueryResult eval(const TextQuery &t) const { return q->eval(t); } // ʵ�ʵ���Query_base��eval�鷽��
	string rep() const { return q->rep(); } // ʵ�ʵ���Query_base��rep�鷽��
};

ostream &operator<<(ostream &os, const Query &query) {
	return os << query.rep();
}

// ������ĵ��ʲ�ѯ�࣬���ݵ���ֱ�ӽ��в�ѯ
class WordQuery :public Query_base {
	friend class Query; // Query��Ҫ����WordQuery�Ĺ��캯��
private:
	string query_word; // ��Ҫ��ѯ�ĵ���
	WordQuery(const string &s) :query_word(s) {}
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); } // ������Ҫ��ѯ�ĵ��ʽ��в�ѯ�����ؽ��
	string rep() const { return query_word; }
};

// �ȴ�WordQuery��������ܶ���ù��캯��������WordQuery�ǲ���ȫ����
inline Query::Query(const string &s) :q(new WordQuery(s)) {}

// ���ǡ���ѯ���Բ�ѯ���ȡ��
class NotQuery :public Query_base {
	friend Query operator~(const Query&);
private:
	Query query;
	NotQuery(const Query &q) :query(q) {}
	QueryResult eval(const TextQuery&) const;
	string rep() const { return "~(" + query.rep() + ")"; }
};

inline Query operator~(const Query &operand) {
	// ��ʽ������Query��Query(shared_ptr<Query_base>)���캯��
	return shared_ptr<Query_base>(new NotQuery(operand));
}

// ��Ԫ�����Ļ���
class BinaryQuery :public Query_base {
protected:
	Query lhs, rhs; // ���Ҳ�ѯ����
	string opSym; // ��Ԫ������
	BinaryQuery(const Query &l, const Query &r, string s) :lhs(l), rhs(r), opSym(s) {}
	string rep() const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
};

// ���롱��ѯ�����ؽ���Ľ���
class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

// ���򡱲�ѯ�����ؽ���Ĳ���
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
