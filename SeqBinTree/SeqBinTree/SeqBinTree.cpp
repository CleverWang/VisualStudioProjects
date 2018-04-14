#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct BinTree //满二叉树
{
	int MAXNUM; //最大节点个数
	int n; //当前节点个数
	int *nodes; //线性存储节点，从上到下从左至右
};
typedef BinTree *PBinTree; //指向满二叉树的指针

PBinTree createTree(int max) //创建满二叉树
{
	PBinTree ptree = new BinTree;
	if (ptree)
	{
		ptree->nodes = new int[max];
		if (ptree->nodes)
		{
			ptree->MAXNUM = max;
			ptree->n = 0;
			return ptree;
		}
		else delete ptree;
	}
	cout << "No space!" << endl;
	return NULL;
}

int leftChild(PBinTree tree, int root) //根据根节点下标求左子节点下标
{
	if (root < 0 || root >= tree->n || 2 * root + 1 >= tree->n)
		return -1;
	return 2 * root + 1;
}

int rightChild(PBinTree tree, int root) //根据根节点下标求右子节点下标
{
	if (root < 0 || root >= tree->n || 2 * root + 2 >= tree->n)
		return -1;
	return 2 * root + 2;
}

void preOrder(PBinTree tree, int t) //先根遍历（递归）
{
	if (t == -1)
		return;
	cout << tree->nodes[t] << " ";
	preOrder(tree, leftChild(tree, t));
	preOrder(tree, rightChild(tree, t));
}

void preOrder_NR(PBinTree tree) //先根遍历（非递归）
{
	int node_idx;
	stack<int> st;
	st.push(0);
	while (!st.empty())
	{
		node_idx = st.top(); //取栈顶
		st.pop(); //弹出栈顶
		if (node_idx != -1)
		{
			cout << tree->nodes[node_idx] << " "; //访问根节点
			st.push(rightChild(tree, node_idx)); //右子节点入栈（因为先入栈的后访问，所以右子节点先入）
			st.push(leftChild(tree, node_idx)); //左子节点入栈
		}
	}
}

void middleOrder(PBinTree tree, int t) //中根遍历（递归）
{
	if (t == -1)
		return;
	middleOrder(tree, leftChild(tree, t));
	cout << tree->nodes[t] << " ";
	middleOrder(tree, rightChild(tree, t));
}

void middleOrder_NR(PBinTree tree) //中根遍历（非递归）
{
	stack<int> st;
	int node_idx = 0;
	do
	{
		while (node_idx != -1) //沿左子树一路向下，到达最左节点，不断进栈
		{
			st.push(node_idx);
			node_idx = leftChild(tree, node_idx);
		}
		node_idx = st.top(); //取栈顶
		st.pop(); //弹出栈顶
		cout << tree->nodes[node_idx] << " "; //访问该节点
		node_idx = rightChild(tree, node_idx); //访问右子树
	} while (!st.empty() || node_idx != -1);
}

void postOrder(PBinTree tree, int t) //后根遍历（递归）
{
	if (t == -1)
		return;
	postOrder(tree, leftChild(tree, t));
	postOrder(tree, rightChild(tree, t));
	cout << tree->nodes[t] << " ";
}

void postOrder_NR(PBinTree tree) //后根遍历（非递归）
{
	stack<int> st;
	int node_idx = 0;
	while (node_idx != -1 || !st.empty())
	{
		while (node_idx != -1) //沿最左路径，到达最左树叶节点，不断进栈
		{
			st.push(node_idx);
			node_idx = (leftChild(tree, node_idx) != -1) ? leftChild(tree, node_idx) : rightChild(tree, node_idx);
		}
		node_idx = st.top(); //取栈顶
		st.pop(); //栈顶出栈
		cout << tree->nodes[node_idx] << " "; //访问该节点
		if (!st.empty() && leftChild(tree, st.top()) == node_idx) //如果是从左子树退回来的，进入右子树
			node_idx = rightChild(tree, st.top());
		else //从右子树退回，返回上一层处理
			node_idx = -1;
	}
}

void levelOrder(PBinTree tree) //广度优先遍历
{
	queue<int> qu;
	int node_idx = 0;
	qu.push(node_idx);
	while (!qu.empty())
	{
		node_idx = qu.front(); //取队首
		qu.pop(); //队首出队
		cout << tree->nodes[node_idx] << " "; //访问队首
		if (leftChild(tree, node_idx) != -1) //左子节点入队
			qu.push(leftChild(tree, node_idx));
		if (rightChild(tree, node_idx) != -1) //右子节点入队
			qu.push(rightChild(tree, node_idx));
	}
}

int aim[20] = { 1,3,6 }; //需要匹配的从根到树叶的一个序列
int aim_n = 3; //序列中元素个数
int buffer[20]; //缓存匹配过程中的序列
int index = 0; //缓存中的可以存放的下一个位置
bool isOk = false; //是否匹配成功

bool isSame() //判断是否已找到匹配序列
{
	for (int i = 0; i < aim_n; i++)
	{
		if (aim[i] != buffer[i])
			return false;
	}
	return true;
}

void dfs(PBinTree tree, int t) //先根遍历（递归）
{
	if (t == -1) //树叶的左右儿子下标是-1，说明已到树叶
	{
		if (isSame()) //判断是否匹配
		{
			isOk = true;
			return;
		}
		return;
	}
	buffer[index] = tree->nodes[t]; //当前根存入缓存
	index++; //指向下一个位置
	dfs(tree, leftChild(tree, t)); //搜索左子树
	if (isOk) //已找到匹配，退出递归
		return;
	if (leftChild(tree, t) != -1) //从左子树退回，且不是树叶，则需要后移一个位置，准备进入右子树
		index--;
	dfs(tree, rightChild(tree, t)); //搜索右子树
	if (isOk)
		return;
	if (rightChild(tree, t) != -1)
		index--;
}

int main()
{
	PBinTree ptree = createTree(20);
	if (ptree)
	{
		int n;
		cin >> n;
		ptree->n = n;
		for (int i = 0; i < n; i++)
		{
			cin >> ptree->nodes[i];
		}
	}
	cout << "Pre-order recursive:\n";
	preOrder(ptree, 0);
	cout << "\nMiddle-order recursive:\n";
	middleOrder(ptree, 0);
	cout << "\nPost-order recursive:\n";
	postOrder(ptree, 0);
	cout << "\n\nPre-order non-recursive:\n";
	preOrder_NR(ptree);
	cout << "\nMiddle-order non-recursive:\n";
	middleOrder_NR(ptree);
	cout << "\nPost-order non-recursive:\n";
	postOrder_NR(ptree);
	cout << "\n\nLevel-order:\n";
	levelOrder(ptree);
	cout << "\n\ndfs:\n";
	dfs(ptree, 0);
	cout << isOk << endl;
	return 0;
}