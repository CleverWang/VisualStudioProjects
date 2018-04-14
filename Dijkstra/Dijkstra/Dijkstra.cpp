#include<iostream>
#include<cfloat>
#include<string>
using namespace std;

int VN; //实际顶点数
int start; //起始顶点下标
const int MAX_VN = 100; //最大顶点个数
const double INF = DBL_MAX; //无穷大
double arcs[MAX_VN][MAX_VN]; //边以及边上的权重
struct path { //从初始点到其他点的最短路径
	double length; //最短路径
	int prevex; //前驱顶点
};
path dist[MAX_VN]; //保存从初始点到其他点的最短路径的数组
void init();
void dijkstra();
void print_path();

int main() {
	cout << "请输入顶点个数：";
	cin >> VN;
	int arc_num;
	cout << "请输入边数：";
	cin >> arc_num;
	for (int i = 0; i < arc_num; i++)
		for (int j = 0;j < arc_num;j++) {
			if (i == j)
				arcs[i][j] = 0; //自身到自身距离为0
			else
				arcs[i][j] = INF; //不可达设置为无穷大
		}
	int i, j, w;
	cout << "请输入各边及其权重：" << endl;
	for (int t = 0; t < arc_num; t++) {
		cin >> i >> j >> w;
		arcs[i][j] = w;
	}
	cout << "请输入初始顶点：";
	cin >> start;
	dijkstra();
	print_path();
	return 0;
}

void init() {
	dist[start].length = 0;
	dist[start].prevex = start;
	arcs[start][start] = 1; //标志为已计算完成
	for (int i = 0; i < VN; i++)
	{
		if (i != start) {
			dist[i].length = arcs[start][i];
			if (dist[i].length != INF)
				dist[i].prevex = start;
			else
				dist[i].prevex = -1; //不可达则前驱顶点为-1
		}
	}
}

void dijkstra() {
	init();
	int min_v; //当前距离最小的顶点的下标
	double min_w; //当前距离最小的顶点的权重
	for (int i = 0; i < VN; i++)
	{
		if (i != start)
		{
			min_w = INF;
			min_v = start;
			for (int j = 0; j < VN; j++) //寻找当前距离最小的顶点
			{
				if (arcs[j][j] == 0 && dist[j].length < min_w) {
					min_w = dist[j].length;
					min_v = j;
				}
			}
			if (min_v == start) //未找到，则表示不可达，结束
				break;
			arcs[min_v][min_v] = 1; //标志为已计算完成
			for (int j = 0; j < VN; j++) { //调整距离
				if (arcs[j][j] == 0 && dist[j].length > dist[min_v].length + arcs[min_v][j]) {
					dist[j].length = dist[min_v].length + arcs[min_v][j];
					dist[j].prevex = min_v;
				}
			}
		}
	}
}

void print_path() {
	cout << "dist数组：" << endl;
	for (int i = 0; i < VN; i++)
	{
		cout << "(" << dist[i].length << "," << dist[i].prevex << ") ";
	}
	cout << endl << "各点到初始点的最短路径：" << endl;
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
			path = "不可达！";
		cout << start << "->" << i << ":" << path << endl;
	}
}