#include<iostream>
#include<list>
using namespace std;

struct node // 路径点
{
	int i, j;
};

const int MAX = 100;
int m, n; // 迷宫大小
int maze[MAX][MAX]; // 迷宫，1表示墙，0表示路
int directions[4][2] = { {0,-1},{1,0},{0,1},{-1,0} }; // 四个方向，左下右上
int start_i, start_j, end_i, end_j; // 起始点和终止点
int escaped = false; // 是否走出迷宫
list<node> path; // 存储路径

void dfs(int i, int j) // 深度搜索路径
{
	if (i == end_i&&j == end_j) { // 到达终点，走出迷宫
		escaped = true;
		return;
	}
	for (int k = 0; k < 4; k++) // 对当前点的4个方向进行搜索
	{
		int ti = i + directions[k][0];
		int tj = j + directions[k][1];
		if (maze[ti][tj] == 0) { // 是路，可以走
			maze[ti][tj] = 2; // 2表示试探
			/*cout << ti << " " << tj << endl;*/
			node t;t.i = ti;t.j = tj;
			path.push_back(t); // 将试探点加入路径
			dfs(ti, tj); // 对试探点进行深度搜索
			if (escaped) // 试探路径逃离成功，可以不用继续试探
				return;
			maze[ti][tj] = 0; //试探路径失败，将该点恢复成路
			path.pop_back(); // 路径弹出该失败试探点
		}
	}
}

void print_path() // 打印路径
{
	if (escaped)
	{
		cout << "(" << start_i << "," << start_j << ")" << endl;
		node t;
		while (path.size() != 0) {
			t = path.front(); // 由于路径点的加入是开始点到终止点，所以需要从头输出
			cout << "(" << t.i << "," << t.j << ")" << endl;
			path.pop_front();
		}
		/*cout << "(" << end_i << "," << end_j << ")" << endl;*/
	}
}

int main()
{
	cin >> m >> n >> start_i >> start_j >> end_i >> end_j;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
	}
	maze[start_i][start_j] = 2;
	dfs(start_i, start_j);
	if (escaped)
		cout << "Escaped!" << endl;
	else
		cout << "Dead!" << endl;
	print_path();
	return 0;
}