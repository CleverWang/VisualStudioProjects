#pragma once

#include "global.h"

/*
�����Ա�����á�const��ĳ��δ�ṩĬ�Ϲ��캯���������ͣ�����ͨ�����캯����ʼֵ�б��ʼ����Щ��Ա
*/
class ConstRef {
private:
	int var;
	const int var_const;
	int &var_ref;
public:
	ConstRef(int val) :var(val), var_const(val), var_ref(var) {};
	void print() const {
		cout << "var: " << var << "\nvar_const: " << var_const << "\nvar_ref: " << var_ref << endl;
	}
};

// ����Ĺ��캯��������ͨ����ֵ���г�ʼ��
//ConstRef::ConstRef(int val) {
//	var = val;
//	var_const = val; // ���󣺳���var_constδ����ʼ��
//	var_ref = var;
//}