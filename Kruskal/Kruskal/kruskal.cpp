#include<iostream>
#include<cfloat>
using namespace std;

int VN; //ʵ�ʶ�����
const int MAX_VN = 100; //��󶥵����
const double INF = DBL_MAX; //�����
double arcs[MAX_VN][MAX_VN]; //���Լ����ϵ�Ȩ��
struct edge
{
	int start_v, stop_v; //��С�������ıߵ������˵�
	double weight; //�ߵ�Ȩ��
};
edge mst[MAX_VN]; //��С������
int kruskal();
void print_mst();

int main() {
	cout << "�����붥�������";
	cin >> VN;
	int arc_num;
	cout << "�����������";
	cin >> arc_num;
	for (int i = 0; i < VN; i++)
		for (int j = 0;j < VN;j++) {
			if (i == j)
				arcs[i][j] = 0; //�����������Ϊ0
			else
				arcs[i][j] = INF; //���ɴ�����Ϊ�����
		}
	int i, j, w;
	cout << "��������߼���Ȩ�أ�" << endl;
	for (int t = 0; t < arc_num; t++) {
		cin >> i >> j >> w;
		arcs[i][j] = w;
		arcs[j][i] = w;
	}
	if (kruskal())
		print_mst();
	return 0;
}

int kruskal() {
	int status[MAX_VN];
	for (int i = 0; i < VN; i++)
	{
		status[i] = i;
	}
	int num = 0;
	while (num < VN - 1)
	{
		double min = INF;
		int start, stop;
		for (int i = 0; i < VN - 1; i++)
		{
			for (int j = i + 1; j < VN; j++)
			{
				if (arcs[i][j] < min)
				{
					min = arcs[i][j];
					start = i;
					stop = j;
				}
			}
		}
		if (min == INF)
			return 0;
		if (status[start] != status[stop])
		{
			mst[num].start_v = start;
			mst[num].stop_v = stop;
			mst[num].weight = arcs[start][stop];
			num++;
			for (int i = 0, j = status[stop]; i < VN; i++)
			{
				if (status[i] == j)
					status[i] = status[start];
			}
		}
		arcs[start][stop] = INF;
	}
	return 1;
}

void print_mst() {
	cout << "��С�������������£�" << endl;
	for (int i = 0; i < VN - 1; i++)
	{
		cout << "(" << mst[i].start_v << "," << mst[i].stop_v << "," << mst[i].weight << ")" << endl;
	}
}