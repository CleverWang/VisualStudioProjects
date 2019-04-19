#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <functional>
#include <random>
#include <sstream>
#include <regex>
#include <numeric>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void middleOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	middleOrder(root->left);
	cout << root->val << " ";
	middleOrder(root->right);
}

void postOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

template <typename T>
class StackBy2Queue
{
public:
	void push(T data)
	{
		if (!queue1.empty())
		{
			queue1.push(data);
			return;
		}
		if (!queue2.empty())
		{
			queue2.push(data);
			return;
		}
		queue1.push(data);
	}

	T pop()
	{
		if (!queue1.empty())
		{
			T ret;
			while (!queue1.empty())
			{
				ret = queue1.front();
				queue1.pop();
				if (queue1.empty())
					break;
				queue2.push(ret);
			}
			return ret;
		}
		if (!queue2.empty())
		{
			T ret;
			while (!queue2.empty())
			{
				ret = queue2.front();
				queue2.pop();
				if (queue2.empty())
					break;
				queue1.push(ret);
			}
			return ret;
		}
		throw runtime_error("empty stack");
	}

private:
	queue<T> queue1;
	queue<T> queue2;
};

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O(1)）。
思路：双栈法，一个保存数据，另一个保存最小值，压入数据时，比较当前数与最小栈的栈顶，将较小的压入最小栈
*/
template <typename T>
class StackWithMin {
public:
	void push(T value) {
		st.push(value);

		if (min_st.empty())
		{
			min_st.push(value);
		}
		else if (value < min_st.top())
		{
			min_st.push(value);
		}
		else
		{
			min_st.push(min_st.top());
		}
	}
	void pop() {
		if (!st.empty() && !min_st.empty())
		{
			st.pop();
			min_st.pop();
		}
	}
	T top() {
		return st.top();
	}
	T min() {
		return min_st.top();
	}

private:
	stack<T> st;
	stack<T> min_st;
};

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next; // 父节点指针
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class TreeExample
{
public:
	TreeExample()
	{
		TreeNode *node1 = new TreeNode(1);
		TreeNode *node2 = new TreeNode(2);
		TreeNode *node3 = new TreeNode(3);
		TreeNode *node4 = new TreeNode(4);
		TreeNode *node5 = new TreeNode(5);
		TreeNode *node6 = new TreeNode(6);

		node1->left = node2;
		node1->right = node3;
		node2->left = node4;
		node3->left = node5;
		node3->right = node6;

		this->pRoot = node1;
	}
	~TreeExample()
	{
		destroyTree(this->pRoot);
	}

	TreeNode *getTree() const { return pRoot; }

private:
	TreeNode *pRoot;

	void destroyTree(TreeNode *pNode)
	{
		if (pNode == nullptr)
			return;
		destroyTree(pNode->left);
		destroyTree(pNode->right);
		delete pNode;
	}
};

/*
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
思路：
1）把数据流分成左右两部分，左部分所有的数都不大于右部分，并且左右部分的长度差不超过1，那么中位数由左部分最大值和右部分最小值决定
2）动态维护两个优先队列
	a.左部分是一个大根堆，右部分是一个小根堆
	b.读入第奇数个数时，插入左部分，否则插入右部分
	c.插入时，需要修正大小根堆的根节点，保证左部分所有的数都不大于右部分
		1.插入左边时，如果新的数比右边最小的数要大，把新节点插入右边，并把右边最小的数插入左边
		1.插入右边时，如果新的数比左边最大的数要小，把新节点插入左边，并把左边最大的数插入右边
*/
class MedianInStream {
public:
	MedianInStream() : right_min_heap(greater<int>()) {}

	void Insert(int num)
	{
		if ((left_max_heap.size() + right_min_heap.size()) % 2 == 0)
		{
			if (!right_min_heap.empty() && right_min_heap.top() < num)
			{
				int t = right_min_heap.top();
				right_min_heap.pop();
				right_min_heap.push(num);
				left_max_heap.push(t);
			}
			else
				left_max_heap.push(num);
		}
		else
		{
			if (!left_max_heap.empty() && left_max_heap.top() > num)
			{
				int t = left_max_heap.top();
				left_max_heap.pop();
				left_max_heap.push(num);
				right_min_heap.push(t);
			}
			else
				right_min_heap.push(num);
		}
	}

	double GetMedian()
	{
		if ((left_max_heap.size() + right_min_heap.size()) == 0)
			throw runtime_error("Empty stream!");

		if ((left_max_heap.size() + right_min_heap.size()) % 2 == 1)
			return left_max_heap.top();
		else
			return (right_min_heap.top() + left_max_heap.top()) / 2.0;
	}

private:
	priority_queue<int> left_max_heap; // 左部分大根堆
	priority_queue<int, vector<int>, greater<int>> right_min_heap; // 右部分小根堆
};