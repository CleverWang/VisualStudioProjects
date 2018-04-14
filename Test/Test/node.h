/*
#ifndef的方式依赖于宏名字不能冲突，这不光可以保证同一个文件不会被包含多次，
也能保证内容完全相同的两个文件不会被不小心同时包含。
当然，缺点就是如果不同头文件的宏名不小心“撞车”，可能就会导致头文件明明存在，
编译器却硬说找不到声明的状况——这种情况有时非常让人抓狂。
*/

#ifndef NODE_H // 如果没有定义预处理变量NODE_H（为了防止头文件被多次重复包含）
#define NODE_H // 定义预处理变量NODE_H

struct node;
//typedef node *next_node;
using next_node = node * ;
struct node // C++11允许类内初始值
{
	double value = 0;
	next_node next = nullptr;
};

#endif // !NODE_H