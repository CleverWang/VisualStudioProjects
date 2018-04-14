#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct BinTree //��������
{
	int MAXNUM; //���ڵ����
	int n; //��ǰ�ڵ����
	int *nodes; //���Դ洢�ڵ㣬���ϵ��´�������
};
typedef BinTree *PBinTree; //ָ������������ָ��

PBinTree createTree(int max) //������������
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

int leftChild(PBinTree tree, int root) //���ݸ��ڵ��±������ӽڵ��±�
{
	if (root < 0 || root >= tree->n || 2 * root + 1 >= tree->n)
		return -1;
	return 2 * root + 1;
}

int rightChild(PBinTree tree, int root) //���ݸ��ڵ��±������ӽڵ��±�
{
	if (root < 0 || root >= tree->n || 2 * root + 2 >= tree->n)
		return -1;
	return 2 * root + 2;
}

void preOrder(PBinTree tree, int t) //�ȸ��������ݹ飩
{
	if (t == -1)
		return;
	cout << tree->nodes[t] << " ";
	preOrder(tree, leftChild(tree, t));
	preOrder(tree, rightChild(tree, t));
}

void preOrder_NR(PBinTree tree) //�ȸ��������ǵݹ飩
{
	int node_idx;
	stack<int> st;
	st.push(0);
	while (!st.empty())
	{
		node_idx = st.top(); //ȡջ��
		st.pop(); //����ջ��
		if (node_idx != -1)
		{
			cout << tree->nodes[node_idx] << " "; //���ʸ��ڵ�
			st.push(rightChild(tree, node_idx)); //���ӽڵ���ջ����Ϊ����ջ�ĺ���ʣ��������ӽڵ����룩
			st.push(leftChild(tree, node_idx)); //���ӽڵ���ջ
		}
	}
}

void middleOrder(PBinTree tree, int t) //�и��������ݹ飩
{
	if (t == -1)
		return;
	middleOrder(tree, leftChild(tree, t));
	cout << tree->nodes[t] << " ";
	middleOrder(tree, rightChild(tree, t));
}

void middleOrder_NR(PBinTree tree) //�и��������ǵݹ飩
{
	stack<int> st;
	int node_idx = 0;
	do
	{
		while (node_idx != -1) //��������һ·���£���������ڵ㣬���Ͻ�ջ
		{
			st.push(node_idx);
			node_idx = leftChild(tree, node_idx);
		}
		node_idx = st.top(); //ȡջ��
		st.pop(); //����ջ��
		cout << tree->nodes[node_idx] << " "; //���ʸýڵ�
		node_idx = rightChild(tree, node_idx); //����������
	} while (!st.empty() || node_idx != -1);
}

void postOrder(PBinTree tree, int t) //����������ݹ飩
{
	if (t == -1)
		return;
	postOrder(tree, leftChild(tree, t));
	postOrder(tree, rightChild(tree, t));
	cout << tree->nodes[t] << " ";
}

void postOrder_NR(PBinTree tree) //����������ǵݹ飩
{
	stack<int> st;
	int node_idx = 0;
	while (node_idx != -1 || !st.empty())
	{
		while (node_idx != -1) //������·��������������Ҷ�ڵ㣬���Ͻ�ջ
		{
			st.push(node_idx);
			node_idx = (leftChild(tree, node_idx) != -1) ? leftChild(tree, node_idx) : rightChild(tree, node_idx);
		}
		node_idx = st.top(); //ȡջ��
		st.pop(); //ջ����ջ
		cout << tree->nodes[node_idx] << " "; //���ʸýڵ�
		if (!st.empty() && leftChild(tree, st.top()) == node_idx) //����Ǵ��������˻����ģ�����������
			node_idx = rightChild(tree, st.top());
		else //���������˻أ�������һ�㴦��
			node_idx = -1;
	}
}

void levelOrder(PBinTree tree) //������ȱ���
{
	queue<int> qu;
	int node_idx = 0;
	qu.push(node_idx);
	while (!qu.empty())
	{
		node_idx = qu.front(); //ȡ����
		qu.pop(); //���׳���
		cout << tree->nodes[node_idx] << " "; //���ʶ���
		if (leftChild(tree, node_idx) != -1) //���ӽڵ����
			qu.push(leftChild(tree, node_idx));
		if (rightChild(tree, node_idx) != -1) //���ӽڵ����
			qu.push(rightChild(tree, node_idx));
	}
}

int aim[20] = { 1,3,6 }; //��Ҫƥ��ĴӸ�����Ҷ��һ������
int aim_n = 3; //������Ԫ�ظ���
int buffer[20]; //����ƥ������е�����
int index = 0; //�����еĿ��Դ�ŵ���һ��λ��
bool isOk = false; //�Ƿ�ƥ��ɹ�

bool isSame() //�ж��Ƿ����ҵ�ƥ������
{
	for (int i = 0; i < aim_n; i++)
	{
		if (aim[i] != buffer[i])
			return false;
	}
	return true;
}

void dfs(PBinTree tree, int t) //�ȸ��������ݹ飩
{
	if (t == -1) //��Ҷ�����Ҷ����±���-1��˵���ѵ���Ҷ
	{
		if (isSame()) //�ж��Ƿ�ƥ��
		{
			isOk = true;
			return;
		}
		return;
	}
	buffer[index] = tree->nodes[t]; //��ǰ�����뻺��
	index++; //ָ����һ��λ��
	dfs(tree, leftChild(tree, t)); //����������
	if (isOk) //���ҵ�ƥ�䣬�˳��ݹ�
		return;
	if (leftChild(tree, t) != -1) //���������˻أ��Ҳ�����Ҷ������Ҫ����һ��λ�ã�׼������������
		index--;
	dfs(tree, rightChild(tree, t)); //����������
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