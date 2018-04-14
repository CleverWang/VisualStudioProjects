#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

struct AVLNode; //AVL树节点
typedef AVLNode *PAVLNode; //指向AVL树节点的指针
typedef int KeyType; //AVL树节点的键值类型
struct AVLNode
{
	KeyType key; //键值
	int bf; //平衡因子（右子树高度减左子树高度）
	PAVLNode llink, rlink; //指向左子树，右子树的指针
};
typedef AVLNode *AVLTree; //AVL树
typedef AVLTree *PAVLTree; //指向AVL树的指针

PAVLNode createNode(KeyType key) //根据key创建新的树节点
{
	PAVLNode node = (PAVLNode)malloc(sizeof(AVLNode));
	if (node != NULL)
	{
		node->bf = 0;
		node->key = key;
		node->llink = node->rlink = NULL;
	}
	return node;
}

PAVLNode LL(PAVLNode a, PAVLNode b) //LL型调整（新节点插在最小不平衡子树的根节点的左子女的左子树中）
{
	a->bf = b->bf = 0;
	a->llink = b->rlink;
	b->rlink = a;
	return b;
}

PAVLNode RR(PAVLNode a, PAVLNode b) //RR型调整（新节点插在最小不平衡子树的根节点的右子女的右子树中）
{
	a->bf = b->bf = 0;
	a->rlink = b->llink;
	b->llink = a;
	return b;
}

PAVLNode LR(PAVLNode a, PAVLNode b) //LR型调整（新节点插在最小不平衡子树的根节点的左子女的右子树中）
{
	PAVLNode c = b->rlink;
	a->llink = c->rlink;
	b->rlink = c->llink;
	c->llink = b;
	c->rlink = a;
	switch (c->bf)
	{
	case 0:a->bf = b->bf = 0;break;
	case -1:a->bf = 1;b->bf = 0;break;
	case 1:a->bf = 0;b->bf = -1;break;
	}
	c->bf = 0;
	return c;
}

PAVLNode RL(PAVLNode a, PAVLNode b) //RL型调整（新节点插在最小不平衡子树的根节点的右子女的左子树中）
{
	PAVLNode c = b->llink;
	a->rlink = c->llink;
	b->llink = c->rlink;
	c->rlink = b;
	c->llink = a;
	switch (c->bf)
	{
	case 0:a->bf = b->bf = 0;break;
	case -1:a->bf = 0;b->bf = 1;break;
	case 1:a->bf = -1;b->bf = 0;break;
	}
	c->bf = 0;
	return c;
}

int AVLInsert(PAVLTree ptree, KeyType key) //向AVL树中按照key值插入新节点
{
	PAVLNode node_a, node_b, parent_a, p, q, node;
	//指向最小不平衡子树的根节点，新节点插入在*node_a的子树的根节点，最小不平衡子树的根节点的父节点，当前处理的节点，当前处理的节点的父节点，新插入的节点
	int d; //当前处理节点的平衡因子
	if (*ptree == NULL) //空树
	{
		*ptree = createNode(key);
		if (*ptree == NULL)
			return 0;
		return 1;
	}
	node_a = p = *ptree;
	parent_a = q = NULL;
	while (p != NULL) //在树中寻找插入点以及最小不平衡子树
	{
		if (key == p->key) //当前键值已存在
			return 1;
		if (p->bf != 0) //平衡因子不为0表示找到最小不平衡子树
		{
			parent_a = q;
			node_a = p;
		}
		q = p;
		if (key < p->key)
			p = p->llink;
		else
			p = p->rlink;
	}
	node = createNode(key);
	if (node == NULL)
		return 0;
	if (key < q->key) //插入新节点
		q->llink = node;
	else
		q->rlink = node;
	//查看新节点插入的位置
	if (key < node_a->key) //在左子树
	{
		p = node_b = node_a->llink;
		d = -1;
	}
	else //在右子树
	{
		p = node_b = node_a->rlink;
		d = 1;
	}
	//对*node_b开始向新插入节点的路径上的节点的平衡因子进行更新
	while (p != NULL)
	{
		if (key < p->key) //*p左子树增高
		{
			p->bf = -1;
			p = p->llink;
		}
		else //*p右子树增高
		{
			p->bf = 1;
			p = p->rlink;
		}
	}
	if (node_a->bf == 0) //原bf为0，插入后不会失衡
	{
		node_a->bf = d;
		return 1;
	}
	if (node_a->bf = -d) //新节点插入在较低子树上，也不会失衡
	{
		node_a->bf = 0;
		return 1;
	}
	//新节点插入在较高子树上，失衡
	if (d == -1) //插入在*node_a的左子树上
	{
		if (node_b->bf == -1) //左子树的左边
			node_b = LL(node_a, node_b);
		else //左子树的右边
			node_b = LR(node_a, node_b);
	}
	else //插入在*node_a的右子树上
	{
		if (node->bf == 1) //右子树的右边
			node_b = RR(node_a, node_b);
		else //右子树的左边
			node_b = RL(node_a, node_b);
	}
	if (parent_a = NULL) //原来的*node_a为树根
		*ptree = node_b;
	else
	{
		if (parent_a->llink == node_a)
			parent_a->llink = node_b;
		else
			parent_a->rlink = node_b;
	}
	return 1;
}

void middleOrder(PAVLNode pnode) //中序遍历AVL树，输出结果
{
	if (pnode == NULL)
		return;
	middleOrder(pnode->llink);
	cout << pnode->key << " ";
	middleOrder(pnode->rlink);
}

int main()
{
	srand((unsigned int)(time(NULL)));
	int node_nums = 10; //插入10个节点
	PAVLTree ptree = (PAVLTree)malloc(sizeof(AVLTree));
	*ptree = NULL; //创建一棵空树
	int key;
	for (int i = 0;i < node_nums;i++)
	{
		key = rand(); //随机生成键值进行插入
		cout << "add key: " << key << endl;
		if (!AVLInsert(ptree, key)) //插入失败的处理
		{
			cout << "Failed!" << endl;
			*ptree = NULL;
			break;
		}
	}

	if (*ptree != NULL) //插入成功，输出结果
	{
		cout << endl << "Sorted via ALV tree:" << endl;
		middleOrder(*ptree);
		cout << endl;
	}
	return 0;
}