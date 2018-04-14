#include<iostream>
#include<stdlib.h>
#include<string>
#define INF INT_MAX
using namespace std;

struct node
{
	int ww; //�ڵ�Ȩ��
	int parent, llink, rlink; //���׽ڵ��±ꡢ������±ꡢ�Ҷ����±�
};

struct tree
{
	int m; //�ⲿ�ڵ����
	int root; //���ڵ��±�
	node *ht; //������������2*m-1��С������洢
};

tree *huffmantree(int m, int *w) {
	tree *ptree = (tree *)malloc(sizeof(tree));
	ptree->ht = (node *)malloc(sizeof(node)*(2 * m - 1));
	ptree->m = m;
	for (int i = 0; i < 2 * m - 1; i++)
	{ //��ʼ������������
		ptree->ht[i].llink = ptree->ht[i].rlink = ptree->ht[i].parent = -1;
		if (i < m)
			ptree->ht[i].ww = w[i];
		else
			ptree->ht[i].ww = -1;
	}
	int i, j, x1, x2, min1, min2;
	for (i = 0;i < m - 1;i++) { //����m-1���ڲ��ڵ�
		min1 = min2 = INF;
		x1 = x2 = -1;
		for (j = 0;j < m + i;j++) {
			if (ptree->ht[j].ww < min1 && ptree->ht[j].parent == -1) { //Ѱ����СȨ�صĽڵ�
				min2 = min1;
				x2 = x1;
				min1 = ptree->ht[j].ww;
				x1 = j;
			}
			else if (ptree->ht[j].ww < min2 && ptree->ht[j].parent == -1) { //Ѱ�Ҵ�СȨ�صĽڵ�
				min2 = ptree->ht[j].ww;
				x2 = j;
			}
		}
		ptree->ht[x1].parent = ptree->ht[x2].parent = m + i;
		//�����ڲ��ڵ�
		ptree->ht[m + i].ww = min1 + min2;
		ptree->ht[m + i].llink = x1;
		ptree->ht[m + i].rlink = x2;
	}
	ptree->root = 2 * m - 2;
	return ptree;
}

void print_tree(tree *ptree) {
	for (int i = 0; i < ptree->m * 2 - 1; i++)
	{
		cout << ptree->ht[i].ww << "\t" << ptree->ht[i].parent << "\t" << ptree->ht[i].llink << "\t" << ptree->ht[i].rlink << "\n";
	}
}

void huffman_code(tree *ptree) {
	for (int i = 0; i < ptree->m; i++)
	{
		string code = "";
		int child_idx = i;
		int parent_idx = ptree->ht[i].parent;
		while (parent_idx != -1) {
			if (ptree->ht[parent_idx].llink == child_idx)
				code = '0' + code;
			else
				code = '1' + code;
			child_idx = parent_idx;
			parent_idx = ptree->ht[parent_idx].parent;
		}
		cout << (ptree->ht[i].ww) << ":" << code << endl;
	}
}

int main() {
	int m;
	cout << "�������ⲿ�ڵ������\n";
	cin >> m;
	int *w = (int *)malloc(sizeof(int)*m);
	cout << "����������ⲿ�ڵ�Ȩ�أ�\n";
	for (int i = 0; i < m; i++)
	{
		cin >> w[i];
	}
	tree *ptree = huffmantree(m, w);
	cout << "�����������£�\n";
	print_tree(ptree);
	cout << "��Ȩ�ع������������£�\n";
	huffman_code(ptree);
	return 0;
}