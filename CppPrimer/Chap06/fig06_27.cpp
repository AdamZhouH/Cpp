#include <initializer_list>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdarg>

using namespace std;

void Test() {
    initializer_list<string> lst1{"Hello", "word"};         // 调用了拷贝构造函数
    initializer_list<string> lst2({"How", "are", "you"});   // 实际上是调用了拷贝构造函数
    initializer_list<string> lst3(lst1);                    // 调用了拷贝构造函数

    for_each(lst1.begin(), lst1.end(), [] (const string &s) { cout << s << '\t'; });
    cout << endl;

    for_each(lst2.begin(), lst2.end(), [] (const string &s) { cout << s << '\t'; });
    cout << endl;

    for_each(lst3.begin(), lst3.end(), [] (const string &s) { cout << s << '\t'; });
    cout << endl;
}

template <typename T>
T Sum(const initializer_list<T> &li) {
    T value = 0;
    for (auto it = li.begin(); it != li.end(); it++)
        value += *it;
    return value;
}

// 利用可变参数宏实现接受可变参数的函数
// 利用相关的宏处理va_list变量
// 形参个数实际上是无法保证的，不够安全
void foo(int a, char c, ...) {
    va_list ap;     // 创建一个va_list变量
    va_start(ap, c);  // 第二个参数为最后一个确定的形参，初始化ap

    int sum = 0;

    sum += va_arg(ap, int);
    sum += va_arg(ap, int);

    va_end(ap);

    cout << a << ' ' << c << ' ' << sum << endl;
}

int main(int argc, char *argv[]) {
//  Test();
    foo(15, 'x', 3, 5);
//  cout << Sum({1, 2, 3, 4, 9}) << endl;
//  cout << Sum({1.44, 2.09, 3.9, 1.92}) << endl;
    return 0;
}
