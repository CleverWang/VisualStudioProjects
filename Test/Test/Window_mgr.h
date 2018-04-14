#pragma once

#include "Screen.h"
#include "global.h"

class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;

	// �����±����ĳһScreen������
	void clear(ScreenIndex idx);

	// ���Screen�������±�
	ScreenIndex addScreen(const Screen &s);

	void display_screens(ostream &os) {
		for (size_t i = 0, length = screens.size(); i < length; i++) {
			os << "Screen " << i << ": " << screens[i].contents << endl;
		}
	}
private:
	vector<Screen> screens{ Screen(2,3,'-') }; // ��ʼ��һ��Ĭ�ϴ�С��Screen
};

void Window_mgr::clear(ScreenIndex idx) {
	Screen &s = screens[idx];
	s.contents = string(s.width*s.height, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) { // ע�ⷵ�������Ѿ�����Window_mgr��������Ҫ����������
	screens.push_back(s);
	return screens.size() - 1;
}