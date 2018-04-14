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
void prim();
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
	prim();
	print_mst();
	return 0;
}

void prim() {
	int min, vx, vy; //��ǰ��СȨ�صıߣ���ǰ��СȨ�صıߵ���ֹ�˵㣬�뵱ǰ��СȨ�صıߵ���ֹ�˵���������һ���˵�
	double temp_weight; //��ǰ��СȨ��
	edge temp_edge; //���ڱ߽������м����
	for (int i = 0; i < VN - 1; i++) //��ʼ��
	{
		mst[i].start_v = 0;
		mst[i].stop_v = i + 1;
		mst[i].weight = arcs[0][i + 1];
	}
	for (int i = 0;i < VN - 1;i++) { //��Ҫ����VN-1����
		temp_weight = INF;
		min = i;
		for (int j = i;j < VN - 1;j++) { //Ѱ��Ȩ����С�ı�
			if (mst[j].weight < temp_weight) {
				temp_weight = mst[j].weight;
				min = j;
			}
		}
		//���ҵ�����С�ı߽��������鿪ͷ
		temp_edge = mst[min];
		mst[min] = mst[i];
		mst[i] = temp_edge;
		vx = mst[i].stop_v;
		for (int j = i + 1;j < VN - 1;j++) { //����ʣ��ıߵ�Ȩ��
			vy = mst[j].stop_v;
			if (mst[j].weight > arcs[vx][vy]) {
				mst[j].weight = arcs[vx][vy];
				mst[j].start_v = vx;
			}
		}
	}
}

void print_mst() {
	cout << "��С�������������£�" << endl;
	for (int i = 0; i < VN - 1; i++)
	{
		cout << "(" << mst[i].start_v << "," << mst[i].stop_v << "," << mst[i].weight << ")" << endl;
	}
}