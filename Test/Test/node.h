/*
#ifndef�ķ�ʽ�����ں����ֲ��ܳ�ͻ���ⲻ����Ա�֤ͬһ���ļ����ᱻ������Σ�
Ҳ�ܱ�֤������ȫ��ͬ�������ļ����ᱻ��С��ͬʱ������
��Ȼ��ȱ����������ͬͷ�ļ��ĺ�����С�ġ�ײ���������ܾͻᵼ��ͷ�ļ��������ڣ�
������ȴӲ˵�Ҳ���������״���������������ʱ�ǳ�����ץ��
*/

#ifndef NODE_H // ���û�ж���Ԥ�������NODE_H��Ϊ�˷�ֹͷ�ļ�������ظ�������
#define NODE_H // ����Ԥ�������NODE_H

struct node;
//typedef node *next_node;
using next_node = node * ;
struct node // C++11�������ڳ�ʼֵ
{
	double value = 0;
	next_node next = nullptr;
};

#endif // !NODE_H