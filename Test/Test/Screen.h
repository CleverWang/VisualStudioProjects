#pragma once

#include "global.h"

class Screen {
	friend class Window_mgr; // 友元类，Window_mgr的成员函数可以访问Screen的私有变量
	// friend void Window_mgr::clear(ScreenIndex idx); // 友元成员函数
public:
	// 定义一个类型成员，类外可以使用，例如Screen::pos
	typedef string::size_type pos;
	// using pos = string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}

	char get() const {
		return contents[cursor];
	} // 隐式内联
	inline char get(pos r, pos c) const; // 显式内联
	Screen &move(pos r, pos c); // 之后设置成内联

	Screen &set(char c);
	Screen &set(pos r, pos c, char chr);

	// 基于const的重载
	Screen &display(ostream &os) { // 非const对象调用该版本
		do_display(os);
		return *this;
	}
	const Screen &display(ostream &os) const { // const对象调用该版本
		do_display(os);
		return *this;
	}

	void mutable_test() const;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	mutable size_t access_ctr = 0; // 可变数据成员，永远不会是const

	void do_display(ostream &os) const {
		os << "Screen contents: " << contents << endl;
	}
};

char Screen::get(pos r, pos c) const {
	return contents[width*r + c];
}

inline Screen &Screen::move(pos r, pos c) { // 定义处声明成内联
	cursor = r * width + c;
	return *this;
}

inline void Screen::mutable_test() const {
	++access_ctr;
	cout << "Access " << access_ctr << " times! " << endl;
}

inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos r, pos c, char chr) {
	contents[r*width + c] = chr;
	return *this;
}