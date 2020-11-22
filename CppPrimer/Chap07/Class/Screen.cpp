#include <string>
#include <iostream>
#include "Screen.h"

Screen::Screen(Pos ht, Pos wd) :
	height(ht), width(wd), contents(ht * wd, ' ') { }

void Screen::some_member() const {
	++access_ctr;
	std::cout << "In some_member method and access_ctr is " << access_ctr << std::endl;
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(Pos ht, Pos wd, char c) {
    contents[ht * width + wd] = c;
    return *this;
}

Screen &Screen::display(std::ostream &os) {
    do_display(os);
    return *this;
}

const Screen &Screen::display(std::ostream &os) const {
    do_display(os);
    return *this;
}

