/*
#pragma once���ɱ������ṩ��֤��ͬһ���ļ����ᱻ������Ρ�
ע��������˵�ġ�ͬһ���ļ�����ָ�����ϵ�һ���ļ���������ָ������ͬ�������ļ���
�����ĺô��ǣ��㲻���ٷѾ���������ˣ���ȻҲ�Ͳ�����ֺ�����ײ������������⡣
��Ӧ��ȱ��������ĳ��ͷ�ļ��ж�ݿ��������������ܱ�֤���ǲ����ظ�������
��Ȼ����Ⱥ�����ײ�����ġ��Ҳ��������������⣬�ظ����������ױ����ֲ�������
*/

#pragma once

#define NDEBUG // �����Ԥ��������������ε�assert����Ϊ

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <initializer_list>
#include <string>
#include <cassert>
#include <fstream>
#include <sstream>
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <stack>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <regex>
#include <random>
#include <csignal>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>
#include <exception>
#include <condition_variable>
#include <atomic>
//using std::cin;
//using std::cout;
//using std::cerr;
//using std::endl;
//using std::setprecision;
//using std::string;
//using std::vector;
//using std::begin;
//using std::end;
//using std::runtime_error;
//using std::initializer_list;
//using std::istream;
//using std::ostream;
using namespace std;
using namespace std::placeholders;

extern const double pi;
extern double sqrt_2;

size_t func_call_times();
void err_msg(initializer_list<string> il);

// ����ָ�������ָ��ĺ���
int(*odd_eve_1(int i))[5];
auto odd_even_2(int i) -> int(*)[5];
extern int odd[5];
decltype(odd) *odd_even_3(int i);

const string &shorter_string(const string &s1, const string &s2);
string &shorter_string(string &s1, string &s2);

// ������Ϊ����ָ����Ĭ�ϲ���
void print_info(string title, unsigned width = 100, unsigned height = 200);

// constexpr������Ĭ����inline����Ҫ���βκͷ���ֵ���Ͷ�������ֵ���ͣ���������ֻ��һ��return���
// inline��constexpr����ͨ��������ͷ�ļ���
constexpr double pi_value()
{
	return 3.141592653;
}
constexpr double x_pi_value(int x, double pi)
{
	return x * pi;
}

// ������Ϊ�β�
string func_as_param(const string& s1, const string& s2, const string& f_as_p(const string&, const string&));

// ���غ���ָ��
int(*func_ptr_1())(int);
auto func_ptr_2() -> int(*)(int);
using f = int(int);
f *func_ptr_3();
using fp = int(*)(int);
fp func_ptr_4();

void elimDups(vector<string> &words);

bool isShorter(const string &s1, const string &s2);

// void biggies(vector<string> &words, vector<string>::size_type sz);
void biggies_lambda(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char delimiter = ' ');
void biggies_bind(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char delimiter = ' ');

void word_transform(ifstream &map_file, ifstream &input);