#include "global.h"

/*
1.����callable����
2.auto new_callable=bind(callable,arg_list)��arg_list��������_n����ռλ������ʾnew_callable��Ӧλ�õĲ�����_1��ʾ��һ��������
3.����new_callable��new_callable�Ĳ���������callable��_n��Ȼ��callable������arg_listִ��
*/

bool _check_size(const string &s, string::size_type sz);
void _print(ostream &os, const string &s, char delimiter);

// ���������Ӣ�ĵ������У����������ȴ��ڵ��ڸ������ȵĵ������У�������͵��ʷָ������Զ��壩
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