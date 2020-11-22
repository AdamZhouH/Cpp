#include "WindowMgr.h"
#include <iostream>

void WindowMgr::clear(ScreenIndex i) {
    Screen &screen = screens[i];
    screen.contents = std::string(screen.height * screen.width, ' ');
}

WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen &screen) {
    screens.push_back(screen);
    return screens.size() - 1;
}

Screen &WindowMgr::getScreen(ScreenIndex index) {
    return screens[index];
}