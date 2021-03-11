#include <functional>
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <future>
using namespace std;

void func(int x, int y) {
    cout << "call func(int x, int y)" << endl;
}

auto l = [] (int x, int y) {
    cout << "call lambda" << endl;
};

class C {
public:
    void operator ()(int x, int y) const {
        cout << "call Callable Class C" << endl;
    }

    void memfunc(int x, int y) const {
        cout << "call member function" << endl;
    }
};

int main(int argc, char *argv[]) {
    C c;
    std::shared_ptr<C> sp(new C);
    // use bind
    bind(func, 77, 33)();
    bind(l, 77, 33)();
    bind(C(), 77, 33)();
    bind(&C::memfunc, c, 77, 33)();
    bind(&C::memfunc, sp, 77, 33)();
    // use async() (async start the background tasks)
    async(func, 43, 77);
    async(l, 42, 77);
    async(c, 42, 77);
    async(&C::memfunc, &c, 42, 77);
    async(&C::memfunc, sp, 42, 77);

    return 0;
}

