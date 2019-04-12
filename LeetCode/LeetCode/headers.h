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

void MiddleOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	MiddleOrder(root->left);
	cout << root->val << " ";
	MiddleOrder(root->right);
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