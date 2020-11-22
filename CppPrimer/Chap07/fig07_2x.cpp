#include <iostream>
#include "WindowMgr.h"
#include "Screen.h"
#include <string>

using namespace std;

struct Nodefault {
    Nodefault(const string &) {}
};

struct A {
    Nodefault nodefault;
};

class Test {
public:
    Test(int var = 9, const string &str = "Hello World") {
        cout << "Construct Test Object" << endl;
    }
};

void foo(const Test &test) {
    cout << "This is the foo method for testing foo" << endl;
}

int main(int args, char *argv[]) {
//	Screen screen(24, 80);
//	screen.move(1, 1);

	WindowMgr windowMgr;
	Screen &screen = windowMgr.getScreen(0);
	screen.display(std::cout);
	cout << endl;
	windowMgr.clear(0);
	screen.set('M');
	screen.display(std::cout);
//	windowMgr.test();

//	screen.some_member();
//	screen.get(1,1);
//	screen.set(4, 0, '#');
//	cout << "(4, 0) " << screen.get(4, 0) << endl;
//	cout << "Screen Contents" << endl;
//	screen.display(cout);
	std::cout << "Hello World" << std::endl;
//	A a;

    Test test;
    foo(999);
	return 0;
}
