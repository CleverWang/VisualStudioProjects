#include<iostream>
#include<stdio.h>
#include<queue>
#include<stdlib.h>
using namespace std;

/*״̬loc��4λ��ʾ��0��ʾ����ʼ����1��ʾ���յ㰶�������ҷֱ��ʾũ���ǡ��ײ˺����λ�ã�
  ����1001����ʾũ��������յ㰶���ǺͰײ�����ʼ��*/

int farmer(int loc) // �ж�ũ���λ�ã����յ㰶����true
{
	return (0 != (loc & 0x08));
}
int wolf(int loc) // �ж��ǵ�λ�ã����յ㰶����true
{
	return (0 != (loc & 0x04));
}
int cabbage(int loc) // �жϰײ˵�λ�ã����յ㰶����true
{
	return (0 != (loc & 0x02));
}
int goat(int loc) // �ж����λ�ã����յ㰶����true
{
	return (0 != (loc & 0x01));
}

int issafe(int loc) // �ж�״̬�Ƿ�ȫ
{
	if ((goat(loc) == cabbage(loc)) && (goat(loc) != farmer(loc))) // ũ�򲻺�����һ�𣬶���ȴ�Ͱײ���һ����԰ײˣ�����ȫ
		return 0;
	if ((wolf(loc) == goat(loc)) && (goat(loc) != farmer(loc))) // ũ�򲻺�����һ�𣬶���ȴ������һ���ǳ��򣬲���ȫ
		return 0;
	return 1;
}

void cross()
{
	int movers, loc, newloc;
	int route[16]; // �±��ʾһ��״̬loc������������һ��״̬loc
	for (int i = 0; i < 16; i++)
	{
		route[i] = -1;
	}
	route[0] = 0;
	queue<int> moves;
	moves.push(0x00); // ��ʼֵ�����
	while (!moves.empty() && route[15] == -1)
	{
		loc = moves.front(); // ��ǰ״̬loc
		moves.pop();
		for (movers = 1;movers <= 8;movers <<= 1) // ����4��������ƶ�
		{
			if ((0 != (loc & 0x08)) == (0 != (loc & movers))) // ũ����ƶ�����Ʒ��ͬһ��
			{
				newloc = loc ^ (0x08 | movers); // ���ʾũ�������Ʒ���ӣ�����ʾ���Ӻ��һ����״̬
				if (issafe(newloc) && route[newloc] == -1) // ��״̬�ǰ�ȫ����δ����¼
				{
					route[newloc] = loc; // ��¼ǰ��״̬
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