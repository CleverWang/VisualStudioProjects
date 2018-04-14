#include "global.h"

// ���������Ӣ�ĵ������У����������ȴ��ڵ��ڸ������ȵĵ�������
/*void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	auto wc = find_if(words.begin(), words.end(), [sz](const string &s) {return s.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << ((count > 1) ? "words" : "word") << " of length " << sz << " or longer:" << endl;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}*/

// ���������Ӣ�ĵ������У����������ȴ��ڵ��ڸ������ȵĵ������У�������͵��ʷָ������Զ��壩
void biggies_lambda(vector<string> &words, vector<string>::size_type sz, ostream &os, char delimiter) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	auto wc = find_if(words.begin(), words.end(), [sz](const string &s) {return s.size() >= sz; });
	// ��ʽ����ֵ����
	// auto wc = find_if(words.begin(), words.end(), [=](const string &s) {return s.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << ((count > 1) ? "words" : "word") << " of length " << sz << " or longer:" << endl;
	for_each(wc, words.end(), [&os, delimiter](const string &s) {os << s << delimiter; });
	// delimiter��ʾֵ����������ʽ���ò���
	// for_each(wc, words.end(), [&, delimiter](const string &s) {os << s << delimiter; });
	// os��ʾ���ò���������ʽֵ����
	// for_each(wc, words.end(), [=, &os](const string &s) {os << s << delimiter; });
	cout << endl;
}