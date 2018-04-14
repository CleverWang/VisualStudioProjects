#include "global.h"

/*
1.定义callable函数
2.auto new_callable=bind(callable,arg_list)，arg_list包含若干_n，即占位符，表示new_callable对应位置的参数（_1表示第一个参数）
3.调用new_callable，new_callable的参数将传给callable的_n，然后callable将根据arg_list执行
*/

bool _check_size(const string &s, string::size_type sz);
void _print(ostream &os, const string &s, char delimiter);

// 排序给定的英文单词序列，最后输出长度大于等于给定长度的单词序列（输出流和单词分隔符可自定义）
void biggies_bind(vector<string> &words, vector<string>::size_type sz, ostream &os, char delimiter) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	auto wc = find_if(words.begin(), words.end(), bind(_check_size, _1, sz));
	auto count = words.end() - wc;
	cout << count << " " << ((count > 1) ? "words" : "word") << " of length " << sz << " or longer:" << endl;
	for_each(wc, words.end(), bind(_print, ref(os), _1, delimiter));
	cout << endl;
}

bool _check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

void _print(ostream &os, const string &s, char delimiter) {
	os << s << delimiter;
}