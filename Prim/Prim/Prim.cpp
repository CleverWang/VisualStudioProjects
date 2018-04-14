#include<iostream>
#include<cfloat>
using namespace std;

int VN; //实际顶点数
const int MAX_VN = 100; //最大顶点个数
const double INF = DBL_MAX; //无穷大
double arcs[MAX_VN][MAX_VN]; //边以及边上的权重
struct edge
{
	int start_v, stop_v; //最小生成树的边的两个端点
	double weight; //边的权重
};
edge mst[MAX_VN]; //最小生成树
void prim();
void print_mst();

int main() {
	cout << "请输入顶点个数：";
	cin >> VN;
	int arc_num;
	cout << "请输入边数：";
	cin >> arc_num;
	for (int i = 0; i < VN; i++)
		for (int j = 0;j < VN;j++) {
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
		arcs[j][i] = w;
	}
	prim();
	print_mst();
	return 0;
}

void prim() {
	int min, vx, vy; //当前最小权重的边，当前最小权重的边的终止端点，与当前最小权重的边的终止端点相连的另一个端点
	double temp_weight; //当前最小权重
	edge temp_edge; //用于边交换的中间变量
	for (int i = 0; i < VN - 1; i++) //初始化
	{
		mst[i].start_v = 0;
		mst[i].stop_v = i + 1;
		mst[i].weight = arcs[0][i + 1];
	}
	for (int i = 0;i < VN - 1;i++) { //需要生成VN-1条边
		temp_weight = INF;
		min = i;
		for (int j = i;j < VN - 1;j++) { //寻找权重最小的边
			if (mst[j].weight < temp_weight) {
				temp_weight = mst[j].weight;
				min = j;
			}
		}
		//将找到的最小的边交换到数组开头
		temp_edge = mst[min];
		mst[min] = mst[i];
		mst[i] = temp_edge;
		vx = mst[i].stop_v;
		for (int j = i + 1;j < VN - 1;j++) { //更新剩余的边的权重
			vy = mst[j].stop_v;
			if (mst[j].weight > arcs[vx][vy]) {
				mst[j].weight = arcs[vx][vy];
				mst[j].start_v = vx;
			}
		}
	}
}

void print_mst() {
	cout << "最小生成树各边如下：" << endl;
	for (int i = 0; i < VN - 1; i++)
	{
		cout << "(" << mst[i].start_v << "," << mst[i].stop_v << "," << mst[i].weight << ")" << endl;
	}
}