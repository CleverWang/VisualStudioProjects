#include<iostream>
#include<stdio.h>
#include<queue>
#include<stdlib.h>
using namespace std;

/*状态loc用4位表示，0表示在起始岸，1表示在终点岸，从左到右分别表示农夫、狼、白菜和羊的位置，
  比如1001，表示农夫和羊在终点岸，狼和白菜在起始岸*/

int farmer(int loc) // 判断农夫的位置，在终点岸返回true
{
	return (0 != (loc & 0x08));
}
int wolf(int loc) // 判断狼的位置，在终点岸返回true
{
	return (0 != (loc & 0x04));
}
int cabbage(int loc) // 判断白菜的位置，在终点岸返回true
{
	return (0 != (loc & 0x02));
}
int goat(int loc) // 判断羊的位置，在终点岸返回true
{
	return (0 != (loc & 0x01));
}

int issafe(int loc) // 判断状态是否安全
{
	if ((goat(loc) == cabbage(loc)) && (goat(loc) != farmer(loc))) // 农夫不和羊在一起，而羊却和白菜在一起，羊吃白菜，不安全
		return 0;
	if ((wolf(loc) == goat(loc)) && (goat(loc) != farmer(loc))) // 农夫不和羊在一起，而羊却和狼在一起，狼吃羊，不安全
		return 0;
	return 1;
}

void cross()
{
	int movers, loc, newloc;
	int route[16]; // 下标表示一个状态loc，里面存的是上一个状态loc
	for (int i = 0; i < 16; i++)
	{
		route[i] = -1;
	}
	route[0] = 0;
	queue<int> moves;
	moves.push(0x00); // 初始值入队列
	while (!moves.empty() && route[15] == -1)
	{
		loc = moves.front(); // 当前状态loc
		moves.pop();
		for (movers = 1;movers <= 8;movers <<= 1) // 考虑4个物体的移动
		{
			if ((0 != (loc & 0x08)) == (0 != (loc & movers))) // 农夫和移动的物品在同一岸
			{
				newloc = loc ^ (0x08 | movers); // 或表示农夫带上物品过河，异或表示过河后的一个新状态
				if (issafe(newloc) && route[newloc] == -1) // 新状态是安全的且未被记录
				{
					route[newloc] = loc; // 记录前驱状态
					moves.push(newloc);
				}
			}
		}
	}
	if (route[15] != -1)
	{
		char out[10];
		cout << "The reversed path is:\n";
		for (loc = 15;loc >= 0;loc = route[loc])
		{
			_itoa_s(loc, out, 2);
			cout << "The location is: ";
			printf("%04s\n", out);
			//cout << "The location is: " << loc << endl;
			if (loc == 0)
				exit(0);
		}
	}
	else
		cout << "No solution!" << endl;
}

int main()
{
	cross();
	/*queue<int> qu;
	qu.push(1);
	qu.push(2);
	cout << qu.front() << endl;
	qu.pop();
	cout << qu.front() << endl;
	cout << qu.empty() << endl;*/
	return 0;
}