#pragma once

#include "global.h"

class Screen {
	friend class Window_mgr; // ��Ԫ�࣬Window_mgr�ĳ�Ա�������Է���Screen��˽�б���
	// friend void Window_mgr::clear(ScreenIndex idx); // ��Ԫ��Ա����
public:
	// ����һ�����ͳ�Ա���������ʹ�ã�����Screen::pos
	typedef string::size_type pos;
	// using pos = string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}

	char get() const {
		return contents[cursor];
	} // ��ʽ����
	inline char get(pos r, pos c) const; // ��ʽ����
	Screen &move(pos r, pos c); // ֮�����ó�����

	Screen &set(char c);
	Screen &set(pos r, pos c, char chr);

	// ����const������
	Screen &display(ostream &os) { // ��const������øð汾
		do_display(os);
		return *this;
	}
	const Screen &display(ostream &os) const { // const������øð汾
		do_display(os);
		return *this;
	}

	void mutable_test() const;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	mutable size_t access_ctr = 0; // �ɱ����ݳ�Ա����Զ������const

	void do_display(ostream &os) const {
		os << "Screen contents: " << contents << endl;
	}
};

char Screen::get(pos r, pos c) const {
	return contents[width*r + c];
}

inline Screen &Screen::move(pos r, pos c) { // ���崦����������
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