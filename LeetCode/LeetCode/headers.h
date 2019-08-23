#ifndef HEADERS_H
#define HEADERS_H

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cctype>

#include <iostream>
#include <fstream>
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
#include <bitset>
#include <list>

using namespace std;

template <typename ContainerType>
void printContainer(const ContainerType &c)
{
    for (const auto &item : c)
        cout << item << " ";
    cout << endl;
}

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for binary tree
struct TreeNode
{
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
class StackWithMin
{
public:
    void push(T value)
    {
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
    void pop()
    {
        if (!st.empty() && !min_st.empty())
        {
            st.pop();
            min_st.pop();
        }
    }
    T top()
    {
        return st.top();
    }
    T min()
    {
        return min_st.top();
    }

private:
    stack<T> st;
    stack<T> min_st;
};

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; // 父节点指针
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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
    TreeExample(std::function<TreeNode *()> buildTreeFunc)
    {
        this->pRoot = buildTreeFunc();
    }
    TreeExample(TreeNode *p) : pRoot(p) {}

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
class MedianInStream
{
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
    priority_queue<int> left_max_heap;                             // 左部分大根堆
    priority_queue<int, vector<int>, greater<int>> right_min_heap; // 右部分小根堆
};

ListNode *buildList(const vector<int> &vec)
{
    if (vec.empty())
        return nullptr;

    ListNode *head = new ListNode(vec[0]), *p = head;
    for (auto citer = vec.cbegin() + 1; citer != vec.cend(); ++citer)
    {
        p->next = new ListNode(*citer);
        p = p->next;
    }

    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

// // Definition for a Node.
// class Node
// {
// public:
//     int val;
//     Node *left;
//     Node *right;
//     Node *next;

//     Node() {}

//     Node(int _val, Node *_left, Node *_right, Node *_next)
//     {
//         val = _val;
//         left = _left;
//         right = _right;
//         next = _next;
//     }
// };

class UndirectedGraphNode
{
public:
    int val;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode() {}

    UndirectedGraphNode(int _val, vector<UndirectedGraphNode *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true

说明:
你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
*/
class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        this->root = new TrieNode();
    }

    ~Trie()
    {
        this->deleteTrie(this->root);
    }

    /** Inserts a word into the trie. */
    void insert(const string &word)
    {
        if (word.empty())
            return;

        TrieNode *pnode = this->root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr)
            {
                pnode->childNodes[idx] = new TrieNode();
            }
            pnode = pnode->childNodes[idx];
        }
        pnode->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word)
    {
        if (word.empty())
            return true;

        TrieNode *pnode = this->root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr)
            {
                return false;
            }
            pnode = pnode->childNodes[idx];
        }
        return pnode->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix)
    {
        if (prefix.empty())
            return true;

        TrieNode *pnode = this->root;
        for (char c : prefix)
        {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr)
            {
                return false;
            }
            pnode = pnode->childNodes[idx];
        }
        return true;
    }

private:
    static constexpr int kChildNodeNum = 26;
    struct TrieNode
    {
        bool isWord;
        TrieNode *childNodes[kChildNodeNum];

        TrieNode() : isWord(false)
        {
            for (int i = 0; i < kChildNodeNum; i++)
            {
                childNodes[i] = nullptr;
            }
        }
    };
    TrieNode *root;

    void deleteTrie(TrieNode *pnode)
    {
        for (int i = 0; i < kChildNodeNum; i++)
        {
            if (pnode->childNodes[i] != nullptr)
                deleteTrie(pnode->childNodes[i]);
        }
        delete pnode;
    }
};

/*
设计一个支持以下两种操作的数据结构：
void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

说明:
你可以假设所有单词都是由小写字母 a-z 组成的
*/
class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        this->root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(const string &word)
    {
        if (word.empty())
            return;

        TrieNode *pnode = this->root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr)
            {
                pnode->childNodes[idx] = new TrieNode();
            }
            pnode = pnode->childNodes[idx];
        }
        pnode->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string &word)
    {
        if (word.empty())
            return false;

        bool res = false;
        searchRecursively(word, 0, this->root, res);
        return res;
    }

private:
    static constexpr int kChildNodeNum = 26;
    struct TrieNode
    {
        bool isWord;
        TrieNode *childNodes[kChildNodeNum];

        TrieNode() : isWord(false)
        {
            for (int i = 0; i < kChildNodeNum; i++)
            {
                childNodes[i] = nullptr;
            }
        }
    };
    TrieNode *root;

    void searchRecursively(const string &w, int idx, TrieNode *p, bool &res)
    {
        if (idx == w.size() && p->isWord == true)
        {
            res = true;
            return;
        }

        if (idx >= w.size() || res == true)
            return;

        char c = w[idx];
        if (c != '.')
        {
            int i = c - 'a';
            if (p->childNodes[i] != nullptr)
            {
                searchRecursively(w, idx + 1, p->childNodes[i], res);
            }
        }
        else
        {
            for (int i = 0; res != true && i < kChildNodeNum; ++i)
            {
                if (p->childNodes[i] != nullptr)
                {
                    searchRecursively(w, idx + 1, p->childNodes[i], res);
                }
            }
        }
    }
};

/*
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。

示例:
给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

说明:
你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。
*/
class NumMatrix
{
public:
    NumMatrix(const vector<vector<int>> &matrix) : cachedMatrix_(std::move(matrix))
    {
        int rows = cachedMatrix_.size();
        if (rows < 1)
            return;
        int cols = cachedMatrix_[0].size();
        if (cols < 1)
            return;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (row == 0 && col == 0)
                    continue;
                else if (row == 0)
                    cachedMatrix_[row][col] += cachedMatrix_[row][col - 1];
                else if (col == 0)
                    cachedMatrix_[row][col] += cachedMatrix_[row - 1][col];
                else
                    cachedMatrix_[row][col] += cachedMatrix_[row - 1][col] - cachedMatrix_[row - 1][col - 1] + cachedMatrix_[row][col - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 > 0 && col1 == 0)
            return cachedMatrix_[row2][col2] - cachedMatrix_[row1 - 1][col2];
        else if (row1 == 0 && col1 > 0)
            return cachedMatrix_[row2][col2] - cachedMatrix_[row2][col1 - 1];
        else if (row1 == 0 && col1 == 0)
            return cachedMatrix_[row2][col2];
        else
            return cachedMatrix_[row2][col2] - cachedMatrix_[row1 - 1][col2] - cachedMatrix_[row2][col1 - 1] + cachedMatrix_[row1 - 1][col1 - 1];
    }

private:
    vector<vector<int>> cachedMatrix_;
};

/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

示例:
Given nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

说明:
数组仅可以在 update 函数下进行修改。
你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。

思路：树状数组
*/
class NumArray
{
public:
    NumArray(const vector<int> &nums) : nums_(nums.size(), 0), treeArray_(nums.size() + 1, 0)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            update(i, nums[i]);
        }
    }

    void update(int i, int val)
    {
        int diff = val - nums_[i];
        nums_[i] = val;
        ++i;
        for (; i < treeArray_.size(); i += lowBit(i))
        {
            treeArray_[i] += diff;
        }
    }

    int sumRange(int i, int j)
    {
        return sum(j) - sum(i - 1);
    }

private:
    vector<int> nums_;
    vector<int> treeArray_;

    int lowBit(int i)
    {
        return i & -i;
    }

    int sum(int i)
    {
        int res = 0;
        ++i;
        for (; i > 0; i -= lowBit(i))
        {
            res += treeArray_[i];
        }
        return res;
    }
};

/*
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。
insert(val)：当元素 val 不存在时，向集合中插入该项。
remove(val)：元素 val 存在时，从集合中移除该项。
getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。

思路：
1）O(1)的复杂度，那么要用到哈希表，但是要随机等概率返回，需要用到随机迭代器，考虑再加上vector
2）vector存储元素，哈希表存储元素到下标的映射
3）删除时，先找到下标，并和最后一个元素交换，然后删除即可
 */
class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        std::srand(std::time(nullptr));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (val_idx_map_.count(val) == 1)
            return false;
        else
        {
            vals_.push_back(val);
            val_idx_map_[val] = vals_.size() - 1;
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (val_idx_map_.count(val) == 0)
            return false;
        else
        {
            int idx = val_idx_map_[val];
            using std::swap;
            swap(vals_[idx], vals_.back());
            val_idx_map_[vals_[idx]] = idx;
            val_idx_map_.erase(vals_.back());
            vals_.pop_back();
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return vals_[std::rand() % vals_.size()];
    }

private:
    vector<int> vals_;
    unordered_map<int, int> val_idx_map_;
};

/*
给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。

进阶:
如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？

思路：蓄水池算法抽样(https://www.cnblogs.com/snowInPluto/p/5996269.html)
 */
class ReservoirSampling
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ReservoirSampling(ListNode *head) : head_(head)
    {
        std::srand(std::time(nullptr));
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int res = head_->val;
        int n = 2;
        ListNode *cur = head_->next;
        while (cur != nullptr)
        {
            if (std::rand() % n == 0)
                res = cur->val;
            ++n;
            cur = cur->next;
        }
        return res;
    }

private:
    ListNode *head_;
};

/*
打乱一个没有重复元素的数组。

思路：洗牌算法（https://blog.csdn.net/qq_26399665/article/details/79831490）
 */
class Shuffle
{
public:
    Shuffle(vector<int> &nums) : origin_(nums)
    {
        std::srand(std::time(nullptr));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return origin_;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> res = origin_;

        // Knuth-Durstenfeld Shuffle
        int length = res.size();
        for (int i = 0; i < length; i++)
        {
            int idx = i + std::rand() % (length - i);
            using std::swap;
            swap(res[i], res[idx]);
        }

        // stl库函数
        // std::random_shuffle(res.begin(), res.end());

        return res;
    }

private:
    vector<int> origin_;
};

// // This is the interface that allows for creating nested lists.
// // You should not implement it, or speculate about its implementation
// class NestedInteger
// {
// public:
//     // Constructor initializes an empty nested list.
//     NestedInteger();
//     // Constructor initializes a single integer.
//     NestedInteger(int value);
//     // Return true if this NestedInteger holds a single integer, rather than a nested list.
//     bool isInteger() const;
//     // Return the single integer that this NestedInteger holds, if it holds a single integer
//     // The result is undefined if this NestedInteger holds a nested list
//     int getInteger() const;
//     // Set this NestedInteger to hold a single integer.
//     void setInteger(int value);
//     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
//     void add(const NestedInteger &ni);
//     // Return the nested list that this NestedInteger holds, if it holds a nested list
//     // The result is undefined if this NestedInteger holds a single integer
//     const vector<NestedInteger> &getList() const;
// };

/*
给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。
找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。
你能在O(n)的时间解决这个问题吗？

示例:
输入: [3, 10, 5, 25, 2, 8]
输出: 28
解释: 最大的结果是 5 ^ 25 = 28.

思路：前缀树+贪心
1）遍历，将每个数字按二进制位从高位到低位建立前缀树
2）要求最大异或结果，希望1出现在高位
3）再遍历，将当前数的二进制位与前缀树进行比较
    a.当前是1，选择前缀是0的子节点
    b.当前是0，选择前缀是1的子节点
    c.通过上面操作，这样最高位尽可能是1
*/
class FindTwoNumsMaximumXORInArray
{
public:
    FindTwoNumsMaximumXORInArray() {}

    int findMaximumXOR(const vector<int> &nums)
    {
        vector<TrieNode> nodes;
        nodes.push_back(TrieNode({0, 0}));
        for (auto x : nums) // 遍历建树
        {
            int p = 0;
            for (int i = 30; i >= 0; --i) // 从高位到低位
            {
                int t = (x >> i) & 1;
                if (nodes[p].son[t] == 0)
                {
                    nodes.push_back(TrieNode({0, 0}));
                    nodes[p].son[t] = nodes.size() - 1;
                }
                p = nodes[p].son[t];
            }
        }

        int res = 0;
        for (auto x : nums)
        {
            int p = 0, max_xor = 0;
            for (int i = 30; i >= 0; --i) // 从高位到低位
            {
                int t = (x >> i) & 1; // 当前位
                if (nodes[p].son[!t]) // 选择与当前位相反的子节点前进
                {
                    p = nodes[p].son[!t];
                    max_xor += 1 << i;
                }
                else // 否则只能选择相同的前进
                {
                    p = nodes[p].son[t];
                }
            }
            res = std::max(res, max_xor);
        }

        return res;
    }

    int findMaximumXOR2(const vector<int> &nums)
    {
        int length = nums.size();
        if (length <= 1)
            return 0;
        if (length == 2)
            return nums[0] ^ nums[1];

        TrieTreeNode *root = new TrieTreeNode{nullptr, nullptr};
        for (int num : nums)
        {
            TrieTreeNode *p = root;
            for (int i = 30; i >= 0; --i)
            {
                int digit = (num >> i) & 1;
                if (digit)
                {
                    if (p->one == nullptr)
                        p->one = new TrieTreeNode{nullptr, nullptr};
                    p = p->one;
                }
                else
                {
                    if (p->zero == nullptr)
                        p->zero = new TrieTreeNode{nullptr, nullptr};
                    p = p->zero;
                }
            }
        }

        int res = INT_MIN;
        for (int num : nums)
        {
            TrieTreeNode *p = root;
            int t = 0;
            for (int i = 30; i >= 0; --i)
            {
                int digit = (num >> i) & 1;
                if (digit)
                {
                    if (p->zero != nullptr)
                    {
                        p = p->zero;
                        t |= (1 << i);
                    }
                    else
                        p = p->one;
                }
                else
                {
                    if (p->one != nullptr)
                    {
                        p = p->one;
                        t |= (1 << i);
                    }
                    else
                        p = p->zero;
                }
            }
            res = std::max(res, t);
        }

        destoryTrieTree(root);

        return res;
    }

private:
    struct TrieNode
    {
        int son[2];
    };
    struct TrieTreeNode
    {
        TrieTreeNode *one;
        TrieTreeNode *zero;
    };

    void destoryTrieTree(TrieTreeNode *root)
    {
        if (root == nullptr)
            return;

        destoryTrieTree(root->one);
        destoryTrieTree(root->zero);

        delete root;
    }
};

// // Definition for a QuadTree node.
// class Node
// {
// public:
//     bool val;
//     bool isLeaf;
//     Node *topLeft;
//     Node *topRight;
//     Node *bottomLeft;
//     Node *bottomRight;

//     Node() {}

//     Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
//     {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = _topLeft;
//         topRight = _topRight;
//         bottomLeft = _bottomLeft;
//         bottomRight = _bottomRight;
//     }
// };

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() {}

    Node(int _val, Node *_prev, Node *_next, Node *_child)
    {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

#endif