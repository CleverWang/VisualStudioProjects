#include<iostream>
#include<cfloat>
#include<string>
using namespace std;

int VN; //ʵ�ʶ�����
int start; //��ʼ�����±�
const int MAX_VN = 100; //��󶥵����
const double INF = DBL_MAX; //�����
double arcs[MAX_VN][MAX_VN]; //���Լ����ϵ�Ȩ��
struct path { //�ӳ�ʼ�㵽����������·��
	double length; //���·��
	int prevex; //ǰ������
};
path dist[MAX_VN]; //����ӳ�ʼ�㵽����������·��������
void init();
void dijkstra();
void print_path();

int main() {
	cout << "�����붥�������";
	cin >> VN;
	int arc_num;
	cout << "�����������";
	cin >> arc_num;
	for (int i = 0; i < arc_num; i++)
		for (int j = 0;j < arc_num;j++) {
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
	}
	cout << "�������ʼ���㣺";
	cin >> start;
	dijkstra();
	print_path();
	return 0;
}

void init() {
	dist[start].length = 0;
	dist[start].prevex = start;
	arcs[start][start] = 1; //��־Ϊ�Ѽ������
	for (int i = 0; i < VN; i++)
	{
		if (i != start) {
			dist[i].length = arcs[start][i];
			if (dist[i].length != INF)
				dist[i].prevex = start;
			else
				dist[i].prevex = -1; //���ɴ���ǰ������Ϊ-1
		}
	}
}

void dijkstra() {
	init();
	int min_v; //��ǰ������С�Ķ�����±�
	double min_w; //��ǰ������С�Ķ����Ȩ��
	for (int i = 0; i < VN; i++)
	{
		if (i != start)
		{
			min_w = INF;
			min_v = start;
			for (int j = 0; j < VN; j++) //Ѱ�ҵ�ǰ������С�Ķ���
			{
				if (arcs[j][j] == 0 && dist[j].length < min_w) {
					min_w = dist[j].length;
					min_v = j;
				}
			}
			if (min_v == start) //δ�ҵ������ʾ���ɴ����
				break;
			arcs[min_v][min_v] = 1; //��־Ϊ�Ѽ������
			for (int j = 0; j < VN; j++) { //��������
				if (arcs[j][j] == 0 && dist[j].length > dist[min_v].length + arcs[min_v][j]) {
					dist[j].length = dist[min_v].length + arcs[min_v][j];
					dist[j].prevex = min_v;
				}
			}
		}
	}
}

void print_path() {
	cout << "dist���飺" << endl;
	for (int i = 0; i < VN; i++)
	{
		cout << "(" << dist[i].length << "," << dist[i].prevex << ") ";
	}
	cout << endl << "���㵽��ʼ������·����" << endl;
	for (int i = 0; i < VN; i++)
	{
		string path;
		if (dist[i].prevex != -1) {
			int t = i;
			while (t != start) {
				path = (char)(t + '0') + path;
				path = ' ' + path;
				t = dist[t].prevex;
			}
			path = (char)(start + '0') + path;
		}
		else
			path = "���ɴ";
		cout << start << "->" << i << ":" << path << endl;
	}
}