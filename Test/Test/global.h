/*
#pragma once则由编译器提供保证：同一个文件不会被包含多次。
注意这里所说的“同一个文件”是指物理上的一个文件，而不是指内容相同的两个文件。
带来的好处是，你不必再费劲想个宏名了，当然也就不会出现宏名碰撞引发的奇怪问题。
对应的缺点就是如果某个头文件有多份拷贝，本方法不能保证他们不被重复包含。
当然，相比宏名碰撞引发的“找不到声明”的问题，重复包含更容易被发现并修正。
*/

#pragma once

#define NDEBUG // 定义该预处理变量可以屏蔽掉assert的行为

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

// 返回指向数组的指针的函数
int(*odd_eve_1(int i))[5];
auto odd_even_2(int i) -> int(*)[5];
extern int odd[5];
decltype(odd) *odd_even_3(int i);

const string &shorter_string(const string &s1, const string &s2);
string &shorter_string(string &s1, string &s2);

// 声明中为函数指定了默认参数
void print_info(string title, unsigned width = 100, unsigned height = 200);

// constexpr函数（默认是inline），要求形参和返回值类型都是字面值类型，并且有且只有一条return语句
// inline和constexpr函数通常定义在头文件中
constexpr double pi_value()
{
	return 3.141592653;
}
constexpr double x_pi_value(int x, double pi)
{
	return x * pi;
}

// 函数作为形参
string func_as_param(const string& s1, const string& s2, const string& f_as_p(const string&, const string&));

// 返回函数指针
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