//#include<iostream>
//using namespace std;
#include<stdio.h>
#define MAX 100

int maxsum(int a[], int count);

int main() {
	int count;
	//cout << "请输入数组元素个数：\n";
	//cin >> count;
	printf("请输入数组元素个数：\n");
	scanf("%d", &count);
	int a[MAX];
	//cout << "请输入各元素：\n";
	printf("请输入各元素：\n");
	for (int i = 0; i < count; i++)
	{
		//cin >> a[i];
		scanf("%d", &a[i]);
	}
	//cout << "最大子段和为：\n" << maxsum(a, count);
	printf("最大子段和为：\n%d", maxsum(a, count));
}

int maxsum(int a[], int count) {
	int sum = 0, temp = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp > 0)
			temp += a[i];
		else
			temp = a[i];
		if (temp > sum)
			sum = temp;
	}
	return sum;
}