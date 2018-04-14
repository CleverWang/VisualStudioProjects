#include "global.h"

const string &shorter_string(const string &s1, const string &s2)
{
	return (s1.size() > s2.size()) ? s2 : s1;
}

string &shorter_string(string &s1, string &s2)
{
	auto &s = shorter_string(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(s);
}