#include "global.h"

// 排序给定的英文单词序列，最后输出长度大于等于给定长度的单词序列
/*void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	auto wc = find_if(words.begin(), words.end(), [sz](const string &s) {return s.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << ((count > 1) ? "words" : "word") << " of length " << sz << " or longer:" << endl;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}*/

// 排序给定的英文单词序列，最后输出长度大于等于给定长度的单词序列（输出流和单词分隔符可自定义）
void biggies_lambda(vector<string> &words, vector<string>::size_type sz, ostream &os, char delimiter) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	auto wc = find_if(words.begin(), words.end(), [sz](const string &s) {return s.size() >= sz; });
	// 隐式捕获（值捕获）
	// auto wc = find_if(words.begin(), words.end(), [=](const string &s) {return s.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << ((count > 1) ? "words" : "word") << " of length " << sz << " or longer:" << endl;
	for_each(wc, words.end(), [&os, delimiter](const string &s) {os << s << delimiter; });
	// delimiter显示值捕获，其余隐式引用捕获
	// for_each(wc, words.end(), [&, delimiter](const string &s) {os << s << delimiter; });
	// os显示引用捕获，其余隐式值捕获
	// for_each(wc, words.end(), [=, &os](const string &s) {os << s << delimiter; });
	cout << endl;
}