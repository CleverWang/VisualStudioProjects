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
// }; // sizeof(B) = A拷贝(4) + B成员(4) + 虚基类指针(4) = 12

// class C : virtual public B
// {
// }; //  siezof(C) = B拷贝(12) + 虚基类指针(4) = 16

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
// }; // sizeof(D) = 8 + 8 - 4 = 12，D中只有一份A

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
// }; // sizeof(A) = 1，A为空类，需要一个字节用于区分

// class B
// {
//   char ch;
//   virtual void func0() {}
// }; // sizeof(B) = 1 + 3(填充) + 4(虚表指针) = 8

// class C
// {
//   char ch1;
//   char ch2;
//   virtual void func() {}
//   virtual void func1() {}
// }; // sizeof(C) = 1 + 1 + 2(填充) + 4(虚表指针) = 8

// class D : public A, public C
// {
//   int d;
//   virtual void func() {}
//   virtual void func1() {}
// }; // sizeof(D) = 8(C的拷贝) + 4(D成员) = 12，A是空基类，被优化了

// class E : public B, public C
// {
//   int e;
//   virtual void func0() {}
//   virtual void func1() {}
// }; // sizeof(E) = 8(B的拷贝) + 8(C的拷贝) + 4(E成员) = 20

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
// }; // 4副本 + 4虚表指针 + 4自身 + 4虚基类指针 = 16

// class Base2 : virtual public CommonBase
// {
// public:
//   virtual void dump1() {}
//   virtual void dump2() {}

// private:
//   int b2;
// }; // 同理16

// class Derived : public Base1, public Base2
// {
// public:
//   void print2() {}
//   void dump2() {}

// private:
//   int d;
// }; // 16副本 + 16副本 - 4虚基类只有一份 + 4自身 = 32

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
// }; // 1 + 3（对齐） + 4 = 8

// class B : virtual public A
// {
// public:
//   virtual void bb() {}
//   virtual void bb2() {}
// }; // 8（副本） + 4(虚基类指针） + 4（虚表指针） = 16

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
// }; // 4自身 + 4虚表指针 = 8

// class B : public A
// {
//   int b;
//   virtual void aa() {}
//   virtual void bb() {}
// }; // 8拷贝 + 4自身 = 12

// class C : public B
// {
//   int c;
//   virtual void aa() {}
//   virtual void bb() {}
//   virtual void cc() {}
// }; // 12拷贝 + 4自身 = 16

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
// }; // 4自身 = 4

// class B : public A
// {
//   int b;
//   void aa() {}
//   void bb() {}
// }; // 4拷贝 + 4自身 = 8

// class C : public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 8拷贝 + 4自身 = 12

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
// }; // 4自身 = 4

// class B : public A
// {
//   int b;
//   virtual void aa() {}
//   void bb() {}
// }; // 4拷贝 + 4自身 = 8

// class C : public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 8拷贝 + 4自身 = 12

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
// }; // 4自身 = 4

// class B : public A
// {
//   int b;
//   void aa() {}
//   virtual void bb() {}
// }; // 4拷贝 + 4自身+ 4虚表指针 = 12

// class C : public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 12拷贝 + 4自身 = 16

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
// }; // 4自身 = 4

// class B : virtual public A
// {
//   int b;
//   void aa() {}
//   void bb() {}
// }; // 4拷贝 + 4自身+ 4虚基类指针 = 12

// class C : virtual public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 12拷贝 + 4自身 + 4虚基类指针 = 20

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
// }; // 4自身 = 4

// class B : virtual public A
// {
//   int b;
//   virtual void aa() {}
//   virtual void bb() {}
// }; // 4拷贝 + 4自身+ 4虚基类指针 + 4虚表指针 = 16

// class C : virtual public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 16拷贝 + 4自身 + 4虚基类指针 = 24

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
// }; // 4自身 = 4

// class B
// {
//   int b;
//   void bb() {}
// }; // 4自身 = 4

// class C : public A, public B
// {
//   int c;
//   void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 4拷贝 + 4拷贝 + 4自身 = 12

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
// }; // 4自身 = 4

// class B
// {
//   int b;
//   void bb() {}
// }; // 4自身 + 4虚表指针 = 8

// class C : public A, public B
// {
//   int c;
//   virtual void aa() {}
//   void bb() {}
//   void cc() {}
// }; // 4拷贝 + 8拷贝 + 4自身 = 16

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
// }; // 4自身 = 4

// class B : virtual public A
// {
//   int b;
//   void aa() {}
//   void bb() {}
// }; // 4拷贝 + 4自身 + 4虚基类指针 = 12

// class C : virtual public A
// {
//   int c;
//   void aa() {}
//   void cc() {}
// }; // 4拷贝 + 4自身 + 4虚基类指针 = 12

// class D : public B, public C
// {
//   int d;
//   void aa() {}
//   void bb() {}
//   void cc() {}
//   void dd() {}
// }; // 12拷贝 + 12拷贝 - 4虚基类大小 + 4自身 = 24

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
// }; // 4自身 = 4

// class B : virtual public A
// {
//   int b;
//   virtual void aa() {}
//   void bb() {}
// }; // 4拷贝 + 4自身 + 4虚基类指针 + 4虚表指针 = 16

// class C : virtual public A
// {
//   int c;
//   void aa() {}
//   void cc() {}
// }; // 4拷贝 + 4自身 + 4虚基类指针 = 12

// class D : public B, public C
// {
//   int d;
//   void aa() {}
//   void bb() {}
//   void cc() {}
//   void dd() {}
// }; // 16拷贝 + 12拷贝 - 4虚基类大小 + 4自身 = 28

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
}; // 4自身 + 4虚表指针 = 8

class B : virtual public A
{
	int b;
	void aa() {}
	void bb() {}
}; // 8拷贝 + 4自身 + 4虚基类指针 = 16

class C : virtual public A
{
	int c;
	void aa() {}
	void cc() {}
}; // 8拷贝 + 4自身 + 4虚基类指针 = 16

class D : public B, public C
{
	int d;
	void aa() {}
	void bb() {}
	void cc() {}
	void dd() {}
}; // 16拷贝 + 16拷贝 - 8虚基类大小 + 4自身 = 28

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;

	return 0;
}

/*
总结：
1.空类的sizeof为1，为了区分不同类
2.单一类（无继承），数据成员大小
3.单一类（无继承，有虚函数），数据成员大小 + 虚表指针大小
4.普通继承（单继承，父子无虚函数），父类拷贝大小 + 子类数据成员大小
5.普通继承（单继承，父有虚函数），父类拷贝大小 + 子类数据成员大小
6.普通继承（单继承，子有父无虚函数），父类拷贝大小 + 子类数据成员大小 + 虚表指针大小
7.虚继承（单继承，父子无虚函数），父类拷贝大小 + 子类数据成员大小 + 虚基类指针大小
8.虚继承（单继承，父有虚函数），父类拷贝大小 + 子类数据成员大小 + 虚基类指针大小
9.虚继承（单继承，子有父无虚函数），父类拷贝大小 + 子类数据成员大小 + 虚基类指针大小 + 虚表指针大小
10.多重继承（非虚继承，父子无虚函数），多个父类拷贝大小 + 子类数据成员大小
11.多重继承（非虚继承，父有虚函数），多个父类拷贝大小 + 子类数据成员大小
12.多重继承（非虚继承，子有父无虚函数），多个父类拷贝大小 + 子类数据成员大小 + 虚表指针大小
13.菱形继承（二三层无虚函数），二层父类拷贝大小 - 一层虚基类大小 + 三层数据成员大小
14.菱形继承（二层有虚函数），二层父类拷贝大小 - 一层虚基类大小 + 三层数据成员大小
15.菱形继承（三层有一二层无虚函数），二层父类拷贝大小 - 一层虚基类大小 + 三层数据成员大小 + 虚表指针大小
*/