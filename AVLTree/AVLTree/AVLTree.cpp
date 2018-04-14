#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

struct AVLNode; //AVL���ڵ�
typedef AVLNode *PAVLNode; //ָ��AVL���ڵ��ָ��
typedef int KeyType; //AVL���ڵ�ļ�ֵ����
struct AVLNode
{
	KeyType key; //��ֵ
	int bf; //ƽ�����ӣ��������߶ȼ��������߶ȣ�
	PAVLNode llink, rlink; //ָ������������������ָ��
};
typedef AVLNode *AVLTree; //AVL��
typedef AVLTree *PAVLTree; //ָ��AVL����ָ��

PAVLNode createNode(KeyType key) //����key�����µ����ڵ�
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

PAVLNode LL(PAVLNode a, PAVLNode b) //LL�͵������½ڵ������С��ƽ�������ĸ��ڵ������Ů���������У�
{
	a->bf = b->bf = 0;
	a->llink = b->rlink;
	b->rlink = a;
	return b;
}

PAVLNode RR(PAVLNode a, PAVLNode b) //RR�͵������½ڵ������С��ƽ�������ĸ��ڵ������Ů���������У�
{
	a->bf = b->bf = 0;
	a->rlink = b->llink;
	b->llink = a;
	return b;
}

PAVLNode LR(PAVLNode a, PAVLNode b) //LR�͵������½ڵ������С��ƽ�������ĸ��ڵ������Ů���������У�
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

PAVLNode RL(PAVLNode a, PAVLNode b) //RL�͵������½ڵ������С��ƽ�������ĸ��ڵ������Ů���������У�
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

int AVLInsert(PAVLTree ptree, KeyType key) //��AVL���а���keyֵ�����½ڵ�
{
	PAVLNode node_a, node_b, parent_a, p, q, node;
	//ָ����С��ƽ�������ĸ��ڵ㣬�½ڵ������*node_a�������ĸ��ڵ㣬��С��ƽ�������ĸ��ڵ�ĸ��ڵ㣬��ǰ����Ľڵ㣬��ǰ����Ľڵ�ĸ��ڵ㣬�²���Ľڵ�
	int d; //��ǰ����ڵ��ƽ������
	if (*ptree == NULL) //����
	{
		*ptree = createNode(key);
		if (*ptree == NULL)
			return 0;
		return 1;
	}
	node_a = p = *ptree;
	parent_a = q = NULL;
	while (p != NULL) //������Ѱ�Ҳ�����Լ���С��ƽ������
	{
		if (key == p->key) //��ǰ��ֵ�Ѵ���
			return 1;
		if (p->bf != 0) //ƽ�����Ӳ�Ϊ0��ʾ�ҵ���С��ƽ������
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
	if (key < q->key) //�����½ڵ�
		q->llink = node;
	else
		q->rlink = node;
	//�鿴�½ڵ�����λ��
	if (key < node_a->key) //��������
	{
		p = node_b = node_a->llink;
		d = -1;
	}
	else //��������
	{
		p = node_b = node_a->rlink;
		d = 1;
	}
	//��*node_b��ʼ���²���ڵ��·���ϵĽڵ��ƽ�����ӽ��и���
	while (p != NULL)
	{
		if (key < p->key) //*p����������
		{
			p->bf = -1;
			p = p->llink;
		}
		else //*p����������
		{
			p->bf = 1;
			p = p->rlink;
		}
	}
	if (node_a->bf == 0) //ԭbfΪ0������󲻻�ʧ��
	{
		node_a->bf = d;
		return 1;
	}
	if (node_a->bf = -d) //�½ڵ�����ڽϵ������ϣ�Ҳ����ʧ��
	{
		node_a->bf = 0;
		return 1;
	}
	//�½ڵ�����ڽϸ������ϣ�ʧ��
	if (d == -1) //������*node_a����������
	{
		if (node_b->bf == -1) //�����������
			node_b = LL(node_a, node_b);
		else //���������ұ�
			node_b = LR(node_a, node_b);
	}
	else //������*node_a����������
	{
		if (node->bf == 1) //���������ұ�
			node_b = RR(node_a, node_b);
		else //�����������
			node_b = RL(node_a, node_b);
	}
	if (parent_a = NULL) //ԭ����*node_aΪ����
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

void middleOrder(PAVLNode pnode) //�������AVL����������
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
	int node_nums = 10; //����10���ڵ�
	PAVLTree ptree = (PAVLTree)malloc(sizeof(AVLTree));
	*ptree = NULL; //����һ�ÿ���
	int key;
	for (int i = 0;i < node_nums;i++)
	{
		key = rand(); //������ɼ�ֵ���в���
		cout << "add key: " << key << endl;
		if (!AVLInsert(ptree, key)) //����ʧ�ܵĴ���
		{
			cout << "Failed!" << endl;
			*ptree = NULL;
			break;
		}
	}

	if (*ptree != NULL) //����ɹ���������
	{
		cout << endl << "Sorted via ALV tree:" << endl;
		middleOrder(*ptree);
		cout << endl;
	}
	return 0;
}