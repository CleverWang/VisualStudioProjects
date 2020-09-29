#pragma once

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cassert>
#include <ctime>
#include <cstdio>

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
#include <complex>
#include <array>
#include <chrono>
#include <memory_resource>

using namespace std;
using namespace std::chrono;

template <typename ContainerType>
void printContainer(const ContainerType &c) {
    for (const auto &item : c)
        cout << item << " ";
    cout << endl;
}

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

void preOrder(TreeNode *root) {
    if (root == NULL)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

vector<int> preOrderNonRecursive(TreeNode *root) {
    if (root == nullptr)
        return {};

    vector<int> res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *p = st.top();
        st.pop();

        res.push_back(p->val);
        if (p->right != nullptr)
            st.push(p->right);
        if (p->left != nullptr)
            st.push(p->left);
    }

    return res;
}

void middleOrder(TreeNode *root) {
    if (root == NULL)
        return;

    middleOrder(root->left);
    cout << root->val << " ";
    middleOrder(root->right);
}

vector<int> middleOrderNonRecursively(TreeNode *root) {
    if (root == nullptr)
        return {};

    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *p = root;
    while (!st.empty() || p != nullptr) {
        while (p != nullptr) {
            st.push(p);
            p = p->left;
        }

        p = st.top();
        st.pop();
        res.push_back(p->val);
        p = p->right;
    }

    return res;
}

void postOrder(TreeNode *root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

vector<int> postOrderNonRecursive(TreeNode *root) {
    if (root == nullptr)
        return {};

    vector<int> res;
    stack<TreeNode *> path;
    unordered_set<TreeNode *> visited; // 记录已经访问的结点
    path.push(root);

    while (!path.empty()) {
        auto node = path.top();

        bool left_visited = true, right_visited = true;

        // 左右结点判断先后顺序不能互换，因为需要先把右结点放进stack中
        if (node->right && visited.find(node->right) == visited.end()) {
            right_visited = false;
            path.push(node->right);
        }

        if (node->left && visited.find(node->left) == visited.end()) {
            left_visited = false;
            path.push(node->left);
        }

        if (left_visited && right_visited) { // 左右结点已经访问过了，才可以访问当前结点
            res.push_back(node->val);
            visited.insert(node);
            path.pop(); // 访问过了，从path中移除
        }
    }

    return res;
}
vector<int> postOrderNonRecursive1(TreeNode *root) {
    if (root == nullptr)
        return {};

    vector<int> res;
    TreeNode *p = root;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty()) {
        p = st.top();
        st.pop();

        if (p->left != nullptr)
            st.push(p->left);
        if (p->right != nullptr)
            st.push(p->right);
        res.push_back(p->val);
    }

    std::reverse(res.begin(), res.end());

    return res;
}

template <typename T>
class StackBy2Queue {
public:
    void push(T data) {
        if (!queue1.empty()) {
            queue1.push(data);
            return;
        }
        if (!queue2.empty()) {
            queue2.push(data);
            return;
        }
        queue1.push(data);
    }

    T pop() {
        if (!queue1.empty()) {
            T ret;
            while (!queue1.empty()) {
                ret = queue1.front();
                queue1.pop();
                if (queue1.empty())
                    break;
                queue2.push(ret);
            }
            return ret;
        }
        if (!queue2.empty()) {
            T ret;
            while (!queue2.empty()) {
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

        if (min_st.empty()) {
            min_st.push(value);
        } else if (value < min_st.top()) {
            min_st.push(value);
        } else {
            min_st.push(min_st.top());
        }
    }
    void pop() {
        if (!st.empty() && !min_st.empty()) {
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
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {
    }
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; // 父节点指针
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class TreeExample {
public:
    TreeExample() {
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
    TreeExample(std::function<TreeNode *()> buildTreeFunc) {
        this->pRoot = buildTreeFunc();
    }
    TreeExample(TreeNode *p) : pRoot(p) {}

    ~TreeExample() {
        destroyTree(this->pRoot);
    }

    TreeNode *getTree() const { return pRoot; }

private:
    TreeNode *pRoot;

    void destroyTree(TreeNode *pNode) {
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

    void Insert(int num) {
        if ((left_max_heap.size() + right_min_heap.size()) % 2 == 0) {
            if (!right_min_heap.empty() && right_min_heap.top() < num) {
                int t = right_min_heap.top();
                right_min_heap.pop();
                right_min_heap.push(num);
                left_max_heap.push(t);
            } else
                left_max_heap.push(num);
        } else {
            if (!left_max_heap.empty() && left_max_heap.top() > num) {
                int t = left_max_heap.top();
                left_max_heap.pop();
                left_max_heap.push(num);
                right_min_heap.push(t);
            } else
                right_min_heap.push(num);
        }
    }

    double GetMedian() {
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

ListNode *buildList(const vector<int> &vec) {
    if (vec.empty())
        return nullptr;

    ListNode *head = new ListNode(vec[0]), *p = head;
    for (auto citer = vec.cbegin() + 1; citer != vec.cend(); ++citer) {
        p->next = new ListNode(*citer);
        p = p->next;
    }

    return head;
}

void printList(ListNode *head) {
    while (head != nullptr) {
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

class UndirectedGraphNode {
public:
    int val;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode() {}

    UndirectedGraphNode(int _val, vector<UndirectedGraphNode *> _neighbors) {
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
class Trie {
public:
    struct TrieNode {
        bool isWord;
        TrieNode *childNodes[26];

        TrieNode() : isWord(false) {
            for (int i = 0; i < 26; i++)
                childNodes[i] = nullptr;
        }
    };

    /** Initialize your data structure here. */
    Trie() : root_(new TrieNode) {
    }

    ~Trie() {
        this->deleteTrie(this->root_);
    }

    TrieNode *root() const { return this->root_; }

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        if (word.empty())
            return;

        TrieNode *pnode = this->root_;
        for (char c : word) {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr) {
                pnode->childNodes[idx] = new TrieNode();
            }
            pnode = pnode->childNodes[idx];
        }
        pnode->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        if (word.empty())
            return true;

        TrieNode *pnode = this->root_;
        for (char c : word) {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr) {
                return false;
            }
            pnode = pnode->childNodes[idx];
        }
        return pnode->isWord;
    }

    /** Find and return the prefix of the word in the trie. */
    string searchPrefixIn(const string &word) {
        if (word.empty())
            return {};

        string res;
        TrieNode *pnode = this->root_;
        for (char c : word) {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr)
                return {};

            pnode = pnode->childNodes[idx];
            res.push_back(c);
            if (pnode->isWord)
                return res;
        }
        return {};
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        if (prefix.empty())
            return true;

        TrieNode *pnode = this->root_;
        for (char c : prefix) {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr) {
                return false;
            }
            pnode = pnode->childNodes[idx];
        }
        return true;
    }

private:
    TrieNode *root_;

    void deleteTrie(TrieNode *pnode) {
        for (int i = 0; i < 26; i++) {
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
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(const string &word) {
        if (word.empty())
            return;

        TrieNode *pnode = this->root;
        for (char c : word) {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr) {
                pnode->childNodes[idx] = new TrieNode();
            }
            pnode = pnode->childNodes[idx];
        }
        pnode->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string &word) {
        if (word.empty())
            return false;

        bool res = false;
        searchRecursively(word, 0, this->root, res);
        return res;
    }

private:
    static constexpr int kChildNodeNum = 26;
    struct TrieNode {
        bool isWord;
        TrieNode *childNodes[kChildNodeNum];

        TrieNode() : isWord(false) {
            for (int i = 0; i < kChildNodeNum; i++) {
                childNodes[i] = nullptr;
            }
        }
    };
    TrieNode *root;

    void searchRecursively(const string &w, int idx, TrieNode *p, bool &res) {
        if (idx == w.size() && p->isWord == true) {
            res = true;
            return;
        }

        if (idx >= w.size() || res == true)
            return;

        char c = w[idx];
        if (c != '.') {
            int i = c - 'a';
            if (p->childNodes[i] != nullptr) {
                searchRecursively(w, idx + 1, p->childNodes[i], res);
            }
        } else {
            for (int i = 0; res != true && i < kChildNodeNum; ++i) {
                if (p->childNodes[i] != nullptr) {
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
class NumMatrix {
public:
    NumMatrix(const vector<vector<int>> &matrix) : cachedMatrix_(std::move(matrix)) {
        int rows = cachedMatrix_.size();
        if (rows < 1)
            return;
        int cols = cachedMatrix_[0].size();
        if (cols < 1)
            return;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
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

    int sumRegion(int row1, int col1, int row2, int col2) {
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
class NumArray {
public:
    NumArray(const vector<int> &nums) : nums_(nums.size(), 0), treeArray_(nums.size() + 1, 0) {
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - nums_[i];
        nums_[i] = val;
        ++i;
        for (; i < treeArray_.size(); i += lowBit(i)) {
            treeArray_[i] += diff;
        }
    }

    int sumRange(int i, int j) {
        return sum(j) - sum(i - 1);
    }

private:
    vector<int> nums_;
    vector<int> treeArray_;

    int lowBit(int i) {
        return i & -i;
    }

    int sum(int i) {
        int res = 0;
        ++i;
        for (; i > 0; i -= lowBit(i)) {
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
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        std::srand(std::time(nullptr));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (val_idx_map_.count(val) == 1)
            return false;
        else {
            vals_.push_back(val);
            val_idx_map_[val] = vals_.size() - 1;
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val_idx_map_.count(val) == 0)
            return false;
        else {
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
    int getRandom() {
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
class ReservoirSampling {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ReservoirSampling(ListNode *head) : head_(head) {
        std::srand(std::time(nullptr));
    }

    /** Returns a random node's value. */
    int getRandom() {
        int res = head_->val;
        int n = 2;
        ListNode *cur = head_->next;
        while (cur != nullptr) {
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
class Shuffle {
public:
    Shuffle(vector<int> &nums) : origin_(nums) {
        std::srand(std::time(nullptr));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin_;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = origin_;

        // Knuth-Durstenfeld Shuffle
        int length = res.size();
        for (int i = 0; i < length; i++) {
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
class FindTwoNumsMaximumXORInArray {
public:
    FindTwoNumsMaximumXORInArray() {}

    int findMaximumXOR(const vector<int> &nums) {
        vector<TrieNode> nodes;
        nodes.push_back(TrieNode({0, 0}));
        for (auto x : nums) // 遍历建树
        {
            int p = 0;
            for (int i = 30; i >= 0; --i) // 从高位到低位
            {
                int t = (x >> i) & 1;
                if (nodes[p].son[t] == 0) {
                    nodes.push_back(TrieNode({0, 0}));
                    nodes[p].son[t] = nodes.size() - 1;
                }
                p = nodes[p].son[t];
            }
        }

        int res = 0;
        for (auto x : nums) {
            int p = 0, max_xor = 0;
            for (int i = 30; i >= 0; --i) // 从高位到低位
            {
                int t = (x >> i) & 1; // 当前位
                if (nodes[p].son[!t]) // 选择与当前位相反的子节点前进
                {
                    p = nodes[p].son[!t];
                    max_xor += 1 << i;
                } else // 否则只能选择相同的前进
                {
                    p = nodes[p].son[t];
                }
            }
            res = std::max(res, max_xor);
        }

        return res;
    }

    int findMaximumXOR2(const vector<int> &nums) {
        int length = nums.size();
        if (length <= 1)
            return 0;
        if (length == 2)
            return nums[0] ^ nums[1];

        TrieTreeNode *root = new TrieTreeNode{nullptr, nullptr};
        for (int num : nums) {
            TrieTreeNode *p = root;
            for (int i = 30; i >= 0; --i) {
                int digit = (num >> i) & 1;
                if (digit) {
                    if (p->one == nullptr)
                        p->one = new TrieTreeNode{nullptr, nullptr};
                    p = p->one;
                } else {
                    if (p->zero == nullptr)
                        p->zero = new TrieTreeNode{nullptr, nullptr};
                    p = p->zero;
                }
            }
        }

        int res = INT_MIN;
        for (int num : nums) {
            TrieTreeNode *p = root;
            int t = 0;
            for (int i = 30; i >= 0; --i) {
                int digit = (num >> i) & 1;
                if (digit) {
                    if (p->zero != nullptr) {
                        p = p->zero;
                        t |= (1 << i);
                    } else
                        p = p->one;
                } else {
                    if (p->one != nullptr) {
                        p = p->one;
                        t |= (1 << i);
                    } else
                        p = p->zero;
                }
            }
            res = std::max(res, t);
        }

        destoryTrieTree(root);

        return res;
    }

private:
    struct TrieNode {
        int son[2];
    };
    struct TrieTreeNode {
        TrieTreeNode *one;
        TrieTreeNode *zero;
    };

    void destoryTrieTree(TrieTreeNode *root) {
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
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() {}

    Node(int _val, Node *_prev, Node *_next, Node *_child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

/*
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
设计一个算法来序列化和反序列化二叉搜索树。
对序列化/反序列化算法的工作方式没有限制。
您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
编码的字符串应尽可能紧凑。
注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。
*/
class Codec {
public:
    /*
    思路：一般化的二叉树序列化
    1）前序遍历
    2）每个节点用特殊符号隔开，比如","
    3）空节点（叶子节点的两个子节点 以及 只有一个子节点的父节点的另一个空节点）用特殊字符表示，比如"$"
    */
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr)
            return {};

        ostringstream oss;
        serializeRecursively(root, oss);
        return oss.str();
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &data) {
        if (data.empty())
            return nullptr;

        TreeNode *root;
        int idx = 0;
        deserializeRecursively(data, idx, &root);
        return root;
    }

    /*
    思路2：根据二叉搜索树的性质：左子节点的值 <= 父节点值 <= 右子节点值
    序列化：
    1）前序遍历
    2）每个非空节点值用特殊符号隔开，比如"#"
    反序列化：
    1）第一个值是根节点
    2）后面小于当前节点值的是左子树
    3）后面大于当前节点值的是右子树
    4）切分成了两部分，再递归
    */
    // Encodes a tree to a single string.
    string serialize2(TreeNode *root) {
        if (root == nullptr)
            return {};

        ostringstream oss;
        serializeRecursively2(root, oss);
        return oss.str();
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize2(const string &data) {
        if (data.empty())
            return nullptr;

        vector<int> vals;
        int now = 0;
        while (now < data.size()) {
            int val = 0;
            while (data[now] != '#') {
                val = val * 10 + (data[now] - '0');
                ++now;
            }
            ++now;
            vals.push_back(val);
        }

        return deserializeRecursively2(vals, 0, vals.size() - 1);
    }

private:
    void deserializeRecursively(const string &s, int &idx, TreeNode **p) {
        if (idx >= s.size())
            return;

        if (s[idx] == '$') {
            idx += 2;
            return;
        }

        int val = 0;
        while (idx < s.size() && s[idx] != ',') {
            val = val * 10 + (s[idx] - '0');
            ++idx;
        }
        ++idx;

        *p = new TreeNode{val};
        deserializeRecursively(s, idx, &((*p)->left));
        deserializeRecursively(s, idx, &((*p)->right));
    }
    void serializeRecursively(TreeNode *p, ostringstream &oss) {
        if (p == nullptr) {
            oss << "$,";
            return;
        }

        oss << p->val << ",";
        serializeRecursively(p->left, oss);
        serializeRecursively(p->right, oss);
    }

    TreeNode *deserializeRecursively2(const vector<int> &vals, int start, int stop) {
        if (start > stop)
            return nullptr;

        TreeNode *root = new TreeNode{vals[start]};

        int pos = -1;
        for (int i = start + 1; i <= stop; i++) {
            if (vals[i] > (root->val)) {
                pos = i;
                break;
            }
        }

        if (pos != -1) {
            root->left = deserializeRecursively2(vals, start + 1, pos - 1);
            root->right = deserializeRecursively2(vals, pos, stop);
        } else {
            root->left = deserializeRecursively2(vals, start + 1, stop);
        }

        return root;
    }
    void serializeRecursively2(TreeNode *p, ostringstream &oss) {
        if (p == nullptr)
            return;

        oss << p->val << "#";
        serializeRecursively2(p->left, oss);
        serializeRecursively2(p->right, oss);
    }
};

/*
给定圆的半径和圆心的 x、y 坐标，写一个在圆中产生均匀随机点的函数 randPoint 。
说明:
输入值和输出值都将是浮点数。
圆的半径和圆心的 x、y 坐标将作为参数传递给类的构造函数。
圆周上的点也认为是在圆中。
randPoint 返回一个包含随机点的x坐标和y坐标的大小为2的数组。

示例 1：
输入:
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
输出: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]

示例 2：
输入:
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
输出: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]

输入语法说明：
输入是两个列表：调用成员函数名和调用的参数。
Solution 的构造函数有三个参数，圆的半径、圆心的 x 坐标、圆心的 y 坐标。
randPoint 没有参数。输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。

思路：拒绝采样
1）先生成圆的外接正方形内的点
2）然后拒绝采样，在圆内的点接受
*/
class RandomPointInCircle {
public:
    RandomPointInCircle(double radius, double x_center, double y_center) :
        r_{radius},
        x_{x_center},
        y_{y_center},
        e_(random_device{}()),
        urd_x_{x_ - r_, std::nextafter(x_ + r_, std::numeric_limits<double>::max())},
        urd_y_{y_ - r_, std::nextafter(y_ + r_, std::numeric_limits<double>::max())}
    {
    }

    vector<double> randPoint() {
        double x, y;
        do {
            x = urd_x_(e_);
            y = urd_y_(e_);
        } while (((x - x_) * (x - x_) + (y - y_) * (y - y_)) > r_ * r_);
        return {x, y};
    }

private:
    double r_;
    double x_, y_;

    default_random_engine e_;
    uniform_real_distribution<double> urd_x_, urd_y_;
};

/*
给定一个非重叠轴对齐矩形的列表 rects，写一个函数 pick 随机均匀地选取矩形覆盖的空间中的整数点。
提示：
整数点是具有整数坐标的点。
矩形周边上的点包含在矩形覆盖的空间中。
第 i 个矩形 rects [i] = [x1，y1，x2，y2]，其中 [x1，y1] 是左下角的整数坐标，[x2，y2] 是右上角的整数坐标。
每个矩形的长度和宽度不超过 2000。
1 <= rects.length <= 100
pick 以整数坐标数组 [p_x, p_y] 的形式返回一个点。
pick 最多被调用10000次。

示例 1：
输入:
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
输出:
[null,[4,1],[4,1],[3,3]]

示例 2：
输入:
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
输出:
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]

输入语法的说明：
输入是两个列表：调用的子例程及其参数。Solution 的构造函数有一个参数，即矩形数组 rects。pick 没有参数。参数总是用列表包装的，即使没有也是如此。
*/
class PickPointInRectList {
public:
    // 思路：拒绝采样（严重超时）
    // PickPointInRectList(vector<vector<int>> &rects) : rects_(rects),
    //                                                   e_(random_device{}()),
    //                                                   x1(INT_MAX), y1(INT_MAX),
    //                                                   x2(INT_MIN), y2(INT_MIN)
    // {
    //     std::sort(rects_.begin(), rects_.end(), [](const vector<int> &a, const vector<int> &b) {
    //         return a[2] < b[2];
    //     });
    //     for (const auto &rect : rects)
    //     {
    //         x1 = std::min(x1, rect[0]);
    //         y1 = std::min(y1, rect[1]);
    //         x2 = std::max(x2, rect[2]);
    //         y2 = std::max(y2, rect[3]);
    //     }
    // }
    // vector<int> pick()
    // {
    //     uniform_int_distribution<int> dx(x1, x2), dy(y1, y2);
    //     int x, y;
    //     do
    //     {
    //         x = dx(e_);
    //         y = dy(e_);
    //     } while (!inRange(x, y));
    //     return {x, y};
    // }

    /*
    思路2：
    1）直接随机选择矩形，然后在这个矩形中随机选出一个点就是结果，但这种方法是错误的
    2）矩形在二维平面是有面积，我们需要根据面积权重进行选择矩形
        a.|--矩形1面积--|--矩形2面积--|...|--矩形n面积--|，构成一维区间，每个矩形面积占据一段区间
        b.在整个区间上随机选取一个点，然后确定该点落在哪个矩形面积中
        c.最后在该矩形中随机选一点
    3）注意一个点的矩形也需要算面积，可令其面积为1
    */
    PickPointInRectList(vector<vector<int>> &rects) : rects_(rects), e_(random_device{}()) {
        unsigned long long int sum = 0;
        // 构造矩形面积一维区间
        for (const auto &rect : rects_) {
            // 注意一个点的矩形
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            areas_.push_back(sum);
        }
    }

    vector<int> pick() {
        // 在区间中随机选一点
        uniform_int_distribution<unsigned long long int> rand_rect(1, areas_.back());
        // 确定是哪个矩形
        auto it = std::lower_bound(areas_.begin(), areas_.end(), rand_rect(e_));
        int idx = it - areas_.begin();
        // 在该矩形中随机选一点
        uniform_int_distribution<int> rand_x(rects_[idx][0], rects_[idx][2]);
        uniform_int_distribution<int> rand_y(rects_[idx][1], rects_[idx][3]);
        return {rand_x(e_), rand_y(e_)};
    }

private:
    // vector<vector<int>> &rects_;
    // default_random_engine e_;
    // int x1, y1;
    // int x2, y2;
    // bool inRange(int x, int y)
    // {
    //     auto it = std::lower_bound(rects_.begin(), rects_.end(), x, [](const vector<int> &a, int b) {
    //         return a[2] < b;
    //     });
    //     if (it == rects_.end())
    //         return false;
    //     else if ((*it)[0] <= x && (*it)[1] <= y && y <= (*it)[3])
    //         return true;
    //     return false;
    // }
    const vector<vector<int>> &rects_;
    vector<unsigned long long int> areas_;
    default_random_engine e_;
};

/*
题中给出一个二维矩阵 (n_rows,n_cols)，且所有值被初始化为 0。
要求编写一个 flip 函数，均匀随机的将矩阵中的 0 变为 1，并返回该值的位置下标 [row_id,col_id]；
同样编写一个 reset 函数，将所有的值都重新置为 0。
尽量最少调用随机函数 Math.random()，并且优化时间和空间复杂度。

注意:
1.1 <= n_rows, n_cols <= 10000
2. 0 <= row.id < n_rows 并且 0 <= col.id < n_cols
3.当矩阵中没有值为 0 时，不可以调用 flip 函数
4.调用 flip 和 reset 函数的次数加起来不会超过 1000 次

示例 1：
输入:
["Solution","flip","flip","flip","flip"]
[[2,3],[],[],[],[]]
输出: [null,[0,1],[1,2],[1,0],[1,1]]

示例 2：
输入:
["Solution","flip","flip","reset","flip"]
[[1,2],[],[],[],[]]
输出: [null,[0,0],[0,1],null,[0,0]]
输入语法解释：
输入包含两个列表：被调用的子程序和他们的参数。
Solution 的构造函数有两个参数，分别为 n_rows 和 n_cols。
flip 和 reset 没有参数，参数总会以列表形式给出，哪怕该列表为空
*/
class MatrixBitFlip {
    // 思路：将二维坐标一维化，每次从一维坐标中抽一个，然后还原成二维坐标（超时）
    //public:
    //    MatrixBitFlip(int n_rows, int n_cols) :
    //        rows_(n_rows),
    //        cols_(n_cols),
    //        len_(rows_ *cols_),
    //        m_(len_),
    //        end_idx_(len_ - 1),
    //        e_(random_device{}())
    //    {
    //        for (int i = 0; i < len_; i++)
    //        {
    //            m_[i] = i;
    //        }
    //    }
    //
    //    vector<int> flip()
    //    {
    //        uniform_int_distribution<int> randint(0, end_idx_);
    //        std::swap(m_[randint(e_)], m_[end_idx_]);
    //        int res = m_[end_idx_];
    //        --end_idx_;
    //        return {res / cols_, res % cols_};
    //    }
    //
    //    void reset()
    //    {
    //        end_idx_ = len_ - 1;
    //        for (int i = 0; i < len_; i++)
    //        {
    //            m_[i] = i;
    //        }
    //    }
    //private:
    //    int rows_, cols_, len_;
    //    vector<int> m_;
    //    int end_idx_;
    //
    //    default_random_engine e_;

    // 思路2：同样地，将二维坐标一维化，但是不存储一维化的坐标，而是维护一个已反转坐标集
    // 每次从一维坐标抽一个，判断是否已经反转过，如果未反转，换算成二维坐标返回并加入已反转集，否则继续抽
public:
    MatrixBitFlip(int n_rows, int n_cols) :
        rows_(n_rows),
        cols_(n_cols),
        len_(rows_ *cols_),
        visited_(),
        e_(random_device{}()),
        randint_(0, len_ - 1) {
    }

    vector<int> flip() {
        int res;
        do {
            res = randint_(e_);
        } while (visited_.count(res));
        visited_.insert(res);

        return {res / cols_, res % cols_};
    }

    void reset() {
        visited_.clear();
    }
private:
    int rows_, cols_, len_;
    unordered_set<int> visited_;

    default_random_engine e_;
    uniform_int_distribution<int> randint_;
};

/*
给定一个正整数数组 w ，其中 w[i] 代表位置 i 的权重，请写一个函数 pickIndex ，它可以随机地获取位置 i，选取位置 i 的概率与 w[i] 成正比。

说明:
1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex 将被调用不超过 10000 次

示例1:
输入:
["Solution","pickIndex"]
[[[1]],[]]
输出: [null,0]

示例2:
输入:
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
输出: [null,0,1,1,1,0]

输入语法说明：
输入是两个列表：调用成员函数名和调用的参数。
Solution 的构造函数有一个参数，即数组 w。
pickIndex 没有参数。
输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。

思路：轮盘赌算法
*/
class PickByWeight {
public:
    PickByWeight(vector<int> &w) : p_(w), e_{random_device{}()}
    {
        int length = p_.size();
        for (int i = 1; i < length; i++)
            p_[i] += p_[i - 1];
    }

    int pickIndex() {
        uniform_int_distribution<int> randint(1, p_.back());
        int rd = randint(e_);
        return std::lower_bound(p_.begin(), p_.end(), rd) - p_.begin();
    }
private:
    vector<int> &p_;

    default_random_engine e_;
};

/*
622. 设计循环队列
设计你的循环队列实现。
循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。
它也被称为“环形缓冲器”。
循环队列的一个好处是我们可以利用这个队列之前用过的空间。
在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：
MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 
示例：
MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4

提示：
所有的值都在 0 至 1000 的范围内；
操作数将在 1 至 1000 的范围内；
请不要使用内置的队列库。
*/
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : qu_(k), size_(0), front_(0), rear_(0) {

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (!isFull()) {
            qu_[rear_] = value;
            rear_ = (rear_ + 1) % qu_.size();
            ++size_;
            return true;
        }
        return false;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!isEmpty()) {
            front_ = (front_ + 1) % qu_.size();
            --size_;
            return true;
        }
        return false;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (!isEmpty())
            return qu_[front_];
        return -1;
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (!isEmpty())
            return qu_[(rear_ + qu_.size() - 1) % qu_.size()];
        return -1;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size_ == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size_ == qu_.size();
    }

private:
    vector<int> qu_; // 线性空间模拟环形空间
    int size_; // 当前环形空间中元素个数
    int front_, rear_; // 指向头元素的下标，指向尾元素下一个位置的下标
};

/*
641. 设计循环双端队列
设计实现双端队列。
你的实现需要支持以下操作：
MyCircularDeque(k)：构造函数,双端队列的大小为k。
insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
isEmpty()：检查双端队列是否为空。
isFull()：检查双端队列是否满了。

示例：
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4

提示：
所有值的范围为 [1, 1000]
操作次数的范围为 [1, 1000]
请不要使用内置的双端队列库。
*/
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : qu_(k), size_(0), front_(0), rear_(1 % k) {

    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (!isFull()) {
            qu_[front_] = value;
            front_ = (front_ + qu_.size() - 1) % qu_.size();
            ++size_;
            return true;
        }
        return false;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (!isFull()) {
            qu_[rear_] = value;
            rear_ = (rear_ + 1) % qu_.size();
            ++size_;
            return true;
        }
        return false;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (!isEmpty()) {
            front_ = (front_ + 1) % qu_.size();
            --size_;
            return true;
        }
        return false;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (!isEmpty()) {
            rear_ = (rear_ + qu_.size() - 1) % qu_.size();
            --size_;
            return true;
        }
        return false;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (!isEmpty())
            return qu_[(front_ + 1) % qu_.size()];
        return -1;
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (!isEmpty())
            return qu_[(rear_ + qu_.size() - 1) % qu_.size()];
        return -1;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size_ == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size_ == qu_.size();
    }
private:
    vector<int> qu_; // 线性空间模拟环形空间
    int size_; // 当前环形空间中元素个数
    int front_, rear_; // 指向头元素前一个位置的下标，指向尾元素下一个位置的下标
};

/*
676. 实现一个魔法字典
实现一个带有buildDict, 以及 search方法的魔法字典。
对于buildDict方法，你将被给定一串不重复的单词来构建一个字典。
对于search方法，你将被给定一个单词，并且判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。

示例 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False

注意:
你可以假设所有输入都是小写字母 a-z。
为了便于竞赛，测试所用的数据量很小。你可以在竞赛结束后，考虑更高效的算法。
请记住重置MagicDictionary类中声明的类变量，因为静态/类变量会在多个测试用例中保留。 请参阅这里了解更多详情。
*/
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(const vector<string> &dict) {
        if (dict.empty())
            return;

        for (const auto &word : dict)
            trie_.insert(word);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if (word.empty())
            return false;

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            for (int j = 0; j < 26; j++) {
                if (j + 'a' == c)
                    continue;
                word[i] = j + 'a';
                if (trie_.search(word))
                    return true;
            }
            word[i] = c;
        }
        return false;
    }

private:
    Trie trie_;
};

/*
677. 键值映射
实现一个 MapSum 类里的两个方法，insert 和 sum。
对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。
对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。

示例 1:
输入: insert("apple", 3), 输出: Null
输入: sum("ap"), 输出: 3
输入: insert("app", 2), 输出: Null
输入: sum("ap"), 输出: 5
*/
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() : root_(new TrieNode) {}

    ~MapSum() { this->deleteTrie(this->root_); }

    void insert(const string &key, int val) {
        if (key.empty())
            return;

        bool is_inserted = dict_.count(key); // 判断键值是否之前插入过
        TrieNode *pnode = this->root_;
        for (char c : key) {
            // 沿着前缀树根节点向下
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr)
                pnode->childNodes[idx] = new TrieNode();

            if (is_inserted) // 之前插入过，那么沿途的节点需要先减去旧值
                pnode->val -= dict_[key];
            pnode->val += val; // 然后再加上新值

            pnode = pnode->childNodes[idx];
        }
        pnode->isWord = true;
        if (is_inserted)
            pnode->val -= dict_[key];
        pnode->val += val;
        dict_[key] = val; // 更新键值
    }

    int sum(const string &prefix) {
        if (prefix.empty())
            return 0;

        auto pnode = this->root_;
        for (char c : prefix) {
            int idx = c - 'a';
            if (pnode->childNodes[idx] == nullptr)
                return 0;
            pnode = pnode->childNodes[idx];
        }
        return pnode->val;
    }

private:
    struct TrieNode {
        bool isWord; // 是否是单词
        int val; // 所有以该前缀开头的键的值的总和
        TrieNode *childNodes[26]; // 子节点

        TrieNode() : isWord(false), val(0), childNodes{nullptr} {}
    };

    TrieNode *root_; // 前缀树的根节点
    unordered_map<string, int> dict_; // 保存键值映射

    void deleteTrie(TrieNode *pnode) {
        for (int i = 0; i < 26; i++) {
            if (pnode->childNodes[i] != nullptr)
                deleteTrie(pnode->childNodes[i]);
        }
        delete pnode;
    }
};

/*
729. 我的日程安排表 I
实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。
MyCalendar 有一个 book(int start, int end)方法。
它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。
当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。
每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true。
否则，返回 false 并且不要将该日程安排添加到日历中。
请按照以下步骤调用 MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

示例 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
解释:
第一个日程安排可以添加到日历中.  第二个日程安排不能添加到日历中，因为时间 15 已经被第一个日程安排预定了。
第三个日程安排可以添加到日历中，因为第一个日程安排并不包含时间 20 。

说明:
每个测试用例，调用 MyCalendar.book 函数最多不超过 100次。
调用函数 MyCalendar.book(start, end)时， start 和 end 的取值范围为 [0, 10^9]。
*/
class MyCalendar {
public:
    MyCalendar() {}

    bool book(int start, int end) {
        if (calendar_.empty()) {
            calendar_.insert({start, end});
            return true;
        } else {
            ScheduleType schedule = {start, end};
            auto it = calendar_.upper_bound(schedule);
            if (it == calendar_.end()) {
                --it;
                if (it->second <= schedule.first) {
                    calendar_.insert(it, schedule);
                    return true;
                } else
                    return false;
            } else {
                if (it->first >= schedule.second) {
                    if (it == calendar_.begin()) {
                        calendar_.insert(schedule);
                        return true;
                    } else if ((--it)->second <= schedule.first) {
                        calendar_.insert(it, schedule);
                        return true;
                    } else
                        return false;
                } else
                    return false;
            }
        }
    }

private:
    using ScheduleType = std::pair<int, int>;
    struct ScheduleCompare {
        bool operator()(const ScheduleType &a, const ScheduleType &b) const {
            return a.second < b.second;
        }
    };

    set<ScheduleType, ScheduleCompare> calendar_;
};

/*
731. 我的日程安排表 II
实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。
MyCalendar 有一个 book(int start, int end)方法。
它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。
当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生三重预订。
每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 true。
否则，返回 false 并且不要将该日程安排添加到日历中。
请按照以下步骤调用MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

示例：
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
解释：
前两个日程安排可以添加至日历中。 第三个日程安排会导致双重预订，但可以添加至日历中。
第四个日程安排活动（5,15）不能添加至日历中，因为它会导致三重预订。
第五个日程安排（5,10）可以添加至日历中，因为它未使用已经双重预订的时间10。
第六个日程安排（25,55）可以添加至日历中，因为时间 [25,40] 将和第三个日程安排双重预订；
时间 [40,50] 将单独预订，时间 [50,55）将和第二个日程安排双重预订。

提示：
每个测试用例，调用 MyCalendar.book 函数最多不超过 1000次。
调用函数 MyCalendar.book(start, end)时， start 和 end 的取值范围为 [0, 10^9]。

思路：线段树
*/
class MyCalendarTwo {
public:
    MyCalendarTwo() : tree_(nullptr) {}

    bool book(int start, int end) {
        if (!insertable(tree_, start, end))
            return false;

        tree_ = insert(tree_, start, end);
        return true;
    }

private:
    struct BSTreeNode {
        int start, end; // 线段起始，线段终止（不包含）
        bool overlap; // 是否是重叠线段
        BSTreeNode *left, *right; // 左子节点，右子节点

        BSTreeNode()
            : start(0), end(0), overlap(false),
            left(nullptr), right(nullptr) {
        }

        BSTreeNode(int s, int e)
            : start(s), end(e), overlap(false),
            left(nullptr), right(nullptr) {
        }
    };

    BSTreeNode *insert(BSTreeNode *root, int start, int end) {
        if (start >= end) // 无效线段，直接返回
            return root;
        if (root == nullptr) // 空树，直接插入
            return new BSTreeNode(start, end);

        if (root->start >= end) // 待插入的线段 在 当前线段 左侧
        {
            // 插入左侧
            root->left = insert(root->left, start, end);
            return root;
        }

        if (root->end <= start) // 待插入的线段 在 当前线段 右侧
        {
            // 插入右侧
            root->right = insert(root->right, start, end);
            return root;
        }


        // 待插入线段 与 当前线段 重叠
        auto min_s = std::min(root->start, start);
        auto max_s = std::max(root->start, start);
        auto min_e = std::min(root->end, end);
        auto max_e = std::max(root->end, end);

        // 当前线段 变成 重叠线段
        root->start = max_s;
        root->end = min_e;
        root->overlap = true;

        // 左侧 未重叠线段 插入 当前线段 左侧
        root->left = insert(root->left, min_s, max_s);
        // 右侧 未重叠线段 插入 当前线段 右侧
        root->right = insert(root->right, min_e, max_e);

        return root;
    }

    bool insertable(BSTreeNode *root, int start, int end) {
        // 无效线段 或 空树
        if (start >= end || root == nullptr)
            return true;

        // 待插入的线段 在 当前线段 左侧
        if (root->start >= end)
            return insertable(root->left, start, end);

        // 待插入的线段 在 当前线段 右侧
        if (root->end <= start)
            return insertable(root->right, start, end);

        // 待插入线段 与 当前线段 重叠，并且 当前线段 已是 重叠线段
        if (root->overlap)
            return false;

        // 当前线段 不是 重叠线段，并且待插入线段 包含在 当前线段 中
        if (start >= root->start && end <= root->end)
            return true;

        // 待插入线段 与 当前线段 部分重叠，递归判断 未重叠部分 是否与 其他线段 重叠
        return insertable(root->left, start, root->start) && insertable(root->right, root->end, end);
    }

private:
    BSTreeNode *tree_;
};

template<typename K, typename V>
class LRU {
public:
    LRU(int capacity) : capacity_(capacity) {}
    ~LRU() {}

    void put(K key, V value) {
        if (map_.count(key)) {
            list_.splice(list_.begin(), list_, map_[key]);
            map_[key]->second = value;
        } else {
            if (list_.size() == capacity_) {
                map_.erase(list_.back().first);
                list_.pop_back();
            }

            list_.push_front({key, value});
            map_[key] = list_.begin();
        }
    }

    V get(K key) {
        if (map_.count(key)) {
            list_.splice(list_.begin(), list_, map_[key]);
            return map_[key]->second;
        }
        throw runtime_error("key not found!");
    }

    V get(K key, V default_value) {
        if (map_.count(key)) {
            list_.splice(list_.begin(), list_, map_[key]);
            return map_[key]->second;
        }
        return default_value;
    }

#ifdef _DEBUG
    void print() const {
        for (auto p : list_) {
            cout << p.first << ":" << p.second << " ";
        }
        cout << endl;
    }
#endif // _DEBUG

private:
    unordered_map<K, typename list<pair<K, V>>::iterator> map_;
    list<pair<K, V>> list_;
    int capacity_;
};


template<typename Int = int>
class RandInt {
public:
    RandInt(Int left = 0, Int right = std::numeric_limits<Int>::max()) :
        e_(random_device{}()),
        dis_(left, right) {
    }

    ~RandInt() {}

    Int operator()() {
        return dis_(e_);
    }

private:
    default_random_engine e_;
    uniform_int_distribution<Int> dis_;
};

template<typename Real = double>
class RandReal {
public:
    RandReal(Real left = Real{0}, Real right = Real{1}) :
        e_(random_device{}()),
        dis_(left, right) {
    }

    ~RandReal() {}

    Real operator()() {
        return dis_(e_);
    }

private:
    default_random_engine e_;
    uniform_real_distribution<Real> dis_;
};
