//#include<iostream>
//using namespace std;
#include<stdio.h>
#define MAX 100

int maxsum(int a[], int count);

int main() {
	int count;
	//cout << "����������Ԫ�ظ�����\n";
	//cin >> count;
	printf("����������Ԫ�ظ�����\n");
	scanf("%d", &count);
	int a[MAX];
	//cout << "�������Ԫ�أ�\n";
	printf("�������Ԫ�أ�\n");
	for (int i = 0; i < count; i++)
	{
		//cin >> a[i];
		scanf("%d", &a[i]);
	}
	//cout << "����Ӷκ�Ϊ��\n" << maxsum(a, count);
	printf("����Ӷκ�Ϊ��\n%d", maxsum(a, count));
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