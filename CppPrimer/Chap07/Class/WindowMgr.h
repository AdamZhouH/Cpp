#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <vector>
#include "Screen.h"

class WindowMgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
public:
	WindowMgr() : screens({Screen(24, 80, 'X')}) { }
    void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen &);
	Screen &getScreen(ScreenIndex);
private:
    std::vector<Screen> screens;
};

#endif // WINDOS_MGR_H
