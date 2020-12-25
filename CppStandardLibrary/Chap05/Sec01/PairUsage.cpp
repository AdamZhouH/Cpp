#include <utility>
#include <iostream>
#include <string>
using namespace std;

//#define INPLEMENT_INTERNAL
/**
 * pair<T1, T2> p;
 * pair<T1, T2> p(val1, val2);
 * pair<T1, T2> p(rv1, rv2);
 * 
*/

template <typename T1, typename T2>
ostream &operator << (ostream &stream, const pair<T1, T2> &p) {
    return stream << '(' << p.first << ", " << p.second << ')';
}

// 友元函数可以实现在内部，或者实现在外部
class Test {
public:
#ifndef INPLEMENT_INTERNAL
    friend ostream &operator << (ostream &stream, const Test &obj);
#else
    friend ostream &operator << (ostream &stream, const Test &obj) {
        return stream << obj.age << " in friend function";
    }
#endif
public:
    Test(int val) { age = val; };
private:
    int age;
};

#ifndef INPLEMENT_INTERNAL
ostream &operator << (ostream &stream, const Test &obj) {
    return stream << obj.age << " in friend function";
}
#endif

int main(void) {
    auto p1 = make_pair(55, "Hello World");
    auto p2 = make_pair("Fuck", "You");
    auto p3 = make_pair("Any", Test(45));
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    return 0;
}