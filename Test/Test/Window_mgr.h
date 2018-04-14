#pragma once

#include "Screen.h"
#include "global.h"

class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;

	// 根据下标清空某一Screen的内容
	void clear(ScreenIndex idx);

	// 添加Screen并返回下标
	ScreenIndex addScreen(const Screen &s);

	void display_screens(ostream &os) {
		for (size_t i = 0, length = screens.size(); i < length; i++) {
			os << "Screen " << i << ": " << screens[i].contents << endl;
		}
	}
private:
	vector<Screen> screens{ Screen(2,3,'-') }; // 初始有一个默认大小的Screen
};

void Window_mgr::clear(ScreenIndex idx) {
	Screen &s = screens[idx];
	s.contents = string(s.width*s.height, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) { // 注意返回类型已经不在Window_mgr作用域，需要声明作用域
	screens.push_back(s);
	return screens.size() - 1;
}