#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void foo(const T &val) {
    if (is_pointer<T>::value) {
        cout << "foo() called for a pointer" << endl;
    } else {
        cout << "foo() called for a value" << endl;
    }
}

int main(void) {
    int val = 55;
    foo(make_unique<int> (5));
    foo(&val);
    foo(0);
    return 0;
}