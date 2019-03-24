#include <iostream>
using namespace std;

/*
Visual Studio 2017 Community x86
sizeof(int) = 4
sizeof(pointer) = 4
*/

// class A
// {
// public:
//   int a;
// }; // sizeof(A) = 4

// class B : virtual public A
// {
// public:
//   int b;
// }; // sizeof(B) = A����(4) + B��Ա(4) + �����ָ��(4) = 12

// class C : virtual public B
// {
// }; //  siezof(C) = B����(12) + �����ָ��(4) = 16

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
// public:
//   int a;
// }; // sizeof(A) = 4

// class B : virtual public A
// {
// }; // sizeof(B) = 4 + 4 = 8

// class C : virtual public A
// {
// }; // sizeof(C) = 4 + 4 = 8

// class D : public B, public C
// {
// }; // sizeof(D) = 8 + 8 - 4 = 12��D��ֻ��һ��A

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;
//   cout << sizeof(D) << endl;

//   return 0;
// }

// class A
// {
// }; // sizeof(A) = 1��AΪ���࣬��Ҫһ���ֽ���������

// class B
// {
//   char ch;
//   virtual void func0() {}
// }; // sizeof(B) = 1 + 3(���) + 4(���ָ��) = 8

// class C
// {
//   char ch1;
//   char ch2;
//   virtual void func() {}
//   virtual void func1() {}
// }; // sizeof(C) = 1 + 1 + 2(���) + 4(���ָ��) = 8

// class D : public A, public C
// {
//   int d;
//   virtual void func() {}
//   virtual void func1() {}
// }; // sizeof(D) = 8(C�Ŀ���) + 4(D��Ա) = 12��A�ǿջ��࣬���Ż���

// class E : public B, public C
// {
//   int e;
//   virtual void func0() {}
//   virtual void func1() {}
// }; // sizeof(E) = 8(B�Ŀ���) + 8(C�Ŀ���) + 4(E��Ա) = 20

// int main(void)
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;
//   cout << sizeof(D) << endl;
//   cout << sizeof(E) << endl;

//   return 0;
// }

// class CommonBase
// {
//   int co;
// }; // size = 4

// class Base1 : virtual public CommonBase
// {
// public:
//   virtual void print1() {}
//   virtual void print2() {}

// private:
//   int b1;
// }; // 4���� + 4���ָ�� + 4���� + 4�����ָ�� = 16

// class Base2 : virtual public CommonBase
// {
// public:
//   virtual void dump1() {}
//   virtual void dump2() {}

// private:
//   int b2;
// }; // ͬ��16

// class Derived : public Base1, public Base2
// {
// public:
//   void print2() {}
//   void dump2() {}

// private:
//   int d;
// }; // 16���� + 16���� - 4�����ֻ��һ�� + 4���� = 32

// int main()
// {
//   cout << sizeof(CommonBase) << endl;
//   cout << sizeof(Base1) << endl;
//   cout << sizeof(Base2) << endl;
//   cout << sizeof(Derived) << endl;

//   return 0;
// }

// class A
// {
// public:
//   virtual void aa() {}
//   virtual void aa2() {}

// private:
//   char ch[3];
// }; // 1 + 3�����룩 + 4 = 8

// class B : virtual public A
// {
// public:
//   virtual void bb() {}
//   virtual void bb2() {}
// }; // 8�������� + 4(�����ָ�룩 + 4�����ָ�룩 = 16

// int main(void)
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   virtual void aa() {}
// }; // 4���� + 4���ָ�� = 8

// class B : public A
// {
//   int b;
//   virtual void aa() {}
//   virtual void bb() {}
// }; // 8���� + 4���� = 12

// class C : public B
// {
//   int c;
//   virtual void aa() {}
//   virtual void bb() {}
//   virtual void cc() {}
// }; // 12���� + 4���� = 16

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   void aa() {}
// }; // 4���� = 4

// class B : public A
// {
//   int b;
//   void aa() {}
//   void bb() {}
// }; // 4���� + 4���� = 8

// class C : public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 8���� + 4���� = 12

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   virtual void aa() {}
// }; // 4���� = 4

// class B : public A
// {
//   int b;
//   virtual void aa() {}
//   void bb() {}
// }; // 4���� + 4���� = 8

// class C : public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 8���� + 4���� = 12

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   void aa() {}
// }; // 4���� = 4

// class B : public A
// {
//   int b;
//   void aa() {}
//   virtual void bb() {}
// }; // 4���� + 4����+ 4���ָ�� = 12

// class C : public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 12���� + 4���� = 16

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   void aa() {}
// }; // 4���� = 4

// class B : virtual public A
// {
//   int b;
//   void aa() {}
//   void bb() {}
// }; // 4���� + 4����+ 4�����ָ�� = 12

// class C : virtual public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 12���� + 4���� + 4�����ָ�� = 20

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   void aa() {}
// }; // 4���� = 4

// class B : virtual public A
// {
//   int b;
//   virtual void aa() {}
//   virtual void bb() {}
// }; // 4���� + 4����+ 4�����ָ�� + 4���ָ�� = 16

// class C : virtual public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 16���� + 4���� + 4�����ָ�� = 24

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   void aa() {}
// }; // 4���� = 4

// class B
// {
//   int b;
//   void bb() {}
// }; // 4���� = 4

// class C : public A, public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 4���� + 4���� + 4���� = 12

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   void aa() {}
// }; // 4���� = 4

// class B
// {
//   int b;
//   void bb() {}
// }; // 4���� + 4���ָ�� = 8

// class C : public A, public B
// {
//   int c;
//   virtual void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 4���� + 8���� + 4���� = 16

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   void aa() {}
// }; // 4���� = 4

// class B : virtual public A
// {
//   int b;
//   void aa() {}
//   void bb() {}
// }; // 4���� + 4���� + 4�����ָ�� = 12

// class C : virtual public A
// {
//   int c;
//   void aa() {}
//   void cc() {}
// }; // 4���� + 4���� + 4�����ָ�� = 12

// class D : public B, public C
// {
//   int d;
//   void aa() {}
//   void bb() {}
//   void cc() {}
//   void dd() {}
// }; // 12���� + 12���� - 4������С + 4���� = 24

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;
//   cout << sizeof(D) << endl;

//   return 0;
// }

// class A
// {
//   int a;
//   void aa() {}
// }; // 4���� = 4

// class B : virtual public A
// {
//   int b;
//   virtual void aa() {}
//   void bb() {}
// }; // 4���� + 4���� + 4�����ָ�� + 4���ָ�� = 16

// class C : virtual public A
// {
//   int c;
//   void aa() {}
//   void cc() {}
// }; // 4���� + 4���� + 4�����ָ�� = 12

// class D : public B, public C
// {
//   int d;
//   void aa() {}
//   void bb() {}
//   void cc() {}
//   void dd() {}
// }; // 16���� + 12���� - 4������С + 4���� = 28

// int main()
// {
//   cout << sizeof(A) << endl;
//   cout << sizeof(B) << endl;
//   cout << sizeof(C) << endl;
//   cout << sizeof(D) << endl;

//   return 0;
// }

class A
{
	int a;
	virtual void aa() {}
}; // 4���� + 4���ָ�� = 8

class B : virtual public A
{
	int b;
	void aa() {}
	void bb() {}
}; // 8���� + 4���� + 4�����ָ�� = 16

class C : virtual public A
{
	int c;
	void aa() {}
	void cc() {}
}; // 8���� + 4���� + 4�����ָ�� = 16

class D : public B, public C
{
	int d;
	void aa() {}
	void bb() {}
	void cc() {}
	void dd() {}
}; // 16���� + 16���� - 8������С + 4���� = 28

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;

	return 0;
}

/*
�ܽ᣺
1.�����sizeofΪ1��Ϊ�����ֲ�ͬ��
2.��һ�ࣨ�޼̳У������ݳ�Ա��С
3.��һ�ࣨ�޼̳У����麯���������ݳ�Ա��С + ���ָ���С
4.��ͨ�̳У����̳У��������麯���������࿽����С + �������ݳ�Ա��С
5.��ͨ�̳У����̳У������麯���������࿽����С + �������ݳ�Ա��С
6.��ͨ�̳У����̳У����и����麯���������࿽����С + �������ݳ�Ա��С + ���ָ���С
7.��̳У����̳У��������麯���������࿽����С + �������ݳ�Ա��С + �����ָ���С
8.��̳У����̳У������麯���������࿽����С + �������ݳ�Ա��С + �����ָ���С
9.��̳У����̳У����и����麯���������࿽����С + �������ݳ�Ա��С + �����ָ���С + ���ָ���С
10.���ؼ̳У�����̳У��������麯������������࿽����С + �������ݳ�Ա��С
11.���ؼ̳У�����̳У������麯������������࿽����С + �������ݳ�Ա��С
12.���ؼ̳У�����̳У����и����麯������������࿽����С + �������ݳ�Ա��С + ���ָ���С
13.���μ̳У����������麯���������㸸�࿽����С - һ��������С + �������ݳ�Ա��С
14.���μ̳У��������麯���������㸸�࿽����С - һ��������С + �������ݳ�Ա��С
15.���μ̳У�������һ�������麯���������㸸�࿽����С - һ��������С + �������ݳ�Ա��С + ���ָ���С
*/