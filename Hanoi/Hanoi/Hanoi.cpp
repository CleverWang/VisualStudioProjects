#include<stdio.h>
#pragma warning(disable : 4996)

int i = 1;//记录步数  

void move(int n, char from, char to) //将编号为n的盘子由from移动到to  
{
	printf("第%d步:将%d号盘子%c---->%c\n", i++, n, from, to);
}

//第一个塔为初始塔，中间的塔为借用塔，最后一个塔为目标塔  
void hanoi(int n, char from, char denpend_on, char to) //将n个盘子由初始塔移动到目标塔(利用借用塔)  
{
	if (n == 1)
		move(1, from, to); //只有一个盘子是直接将初塔上的盘子移动到目的地  
	else
	{
		hanoi(n - 1, from, to, denpend_on); //先将初始塔的前n-1个盘子借助目的塔移动到借用塔上  
		move(n, from, to); //将剩下的一个盘子移动到目的塔上  
		hanoi(n - 1, denpend_on, from, to); //最后将借用塔上的n-1个盘子移动到目的塔上  
	}
}

void main()
{
	printf("请输入盘子的个数:\n");
	int n;
	scanf("%d", &n);
	char x = 'A', y = 'B', z = 'C';
	printf("盘子移动情况如下:\n");
	hanoi(n, x, y, z);
}