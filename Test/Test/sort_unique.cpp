#include "global.h"

void _print(vector<string> &words);

void elimDups(vector<string> &words) {
	cout << "Original input: " << endl;
	_print(words);
	sort(words.begin(), words.end());
	cout << "After sorting: " << endl;
	_print(words);
	auto end_unique = unique(words.begin(), words.end());
	cout << "After uniquing: " << endl;
	_print(words);
	words.erase(end_unique, words.end());
	cout << "After erasing: " << endl;
	_print(words);
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void _print(vector<string> &words) {
	for (const auto &item:words) {
		cout << item << " ";
	}
	cout << endl;
}