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
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO(1)����
˼·��˫ջ����һ���������ݣ���һ��������Сֵ��ѹ������ʱ���Ƚϵ�ǰ������Сջ��ջ��������С��ѹ����Сջ
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
	struct TreeLinkNode *next; // ���ڵ�ָ��
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
��εõ�һ���������е���λ����
������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����
˼·��
1�����������ֳ����������֣��󲿷����е������������Ҳ��֣��������Ҳ��ֵĳ��Ȳ����1����ô��λ�����󲿷����ֵ���Ҳ�����Сֵ����
2����̬ά���������ȶ���
	a.�󲿷���һ������ѣ��Ҳ�����һ��С����
	b.�������������ʱ�������󲿷֣���������Ҳ���
	c.����ʱ����Ҫ������С���ѵĸ��ڵ㣬��֤�󲿷����е������������Ҳ���
		1.�������ʱ������µ������ұ���С����Ҫ�󣬰��½ڵ�����ұߣ������ұ���С�����������
		1.�����ұ�ʱ������µ��������������ҪС�����½ڵ������ߣ�������������������ұ�
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
	priority_queue<int> left_max_heap; // �󲿷ִ����
	priority_queue<int, vector<int>, greater<int>> right_min_heap; // �Ҳ���С����
};