#include<iostream>
#include<list>
using namespace std;

struct node // ·����
{
	int i, j;
};

const int MAX = 100;
int m, n; // �Թ���С
int maze[MAX][MAX]; // �Թ���1��ʾǽ��0��ʾ·
int directions[4][2] = { {0,-1},{1,0},{0,1},{-1,0} }; // �ĸ�������������
int start_i, start_j, end_i, end_j; // ��ʼ�����ֹ��
int escaped = false; // �Ƿ��߳��Թ�
list<node> path; // �洢·��

void dfs(int i, int j) // �������·��
{
	if (i == end_i&&j == end_j) { // �����յ㣬�߳��Թ�
		escaped = true;
		return;
	}
	for (int k = 0; k < 4; k++) // �Ե�ǰ���4�������������
	{
		int ti = i + directions[k][0];
		int tj = j + directions[k][1];
		if (maze[ti][tj] == 0) { // ��·��������
			maze[ti][tj] = 2; // 2��ʾ��̽
			/*cout << ti << " " << tj << endl;*/
			node t;t.i = ti;t.j = tj;
			path.push_back(t); // ����̽�����·��
			dfs(ti, tj); // ����̽������������
			if (escaped) // ��̽·������ɹ������Բ��ü�����̽
				return;
			maze[ti][tj] = 0; //��̽·��ʧ�ܣ����õ�ָ���·
			path.pop_back(); // ·��������ʧ����̽��
		}
	}
}

void print_path() // ��ӡ·��
{
	if (escaped)
	{
		cout << "(" << start_i << "," << start_j << ")" << endl;
		node t;
		while (path.size() != 0) {
			t = path.front(); // ����·����ļ����ǿ�ʼ�㵽��ֹ�㣬������Ҫ��ͷ���
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