#include <iostream>
#include <string>
using namespace std;

// 递归处理参数包（参数包中的参数个数不定，可以使用sizeof...操作确定）---常用手法
// 递归的函数版本，包括递归处理的函数版本和递归的基准情况的函数版本

// 基准函数，不用递归调用的版本
template <typename T>
ostream &print(ostream &os, const T &t) {
    os << t ;
    return os;
}
// 递归情况处理
template <typename T, typename ...Args>
ostream &print(ostream &os, const T &t, const Args & ...args) {
    os << t << ' ';
    return print(os, args...);   // 递归调用相当于第一个参数被移除
}

int main(void) {
    print(cout, "hello world\n", "ZackQ", 123, string("this is the end"));
    return 0;
}
