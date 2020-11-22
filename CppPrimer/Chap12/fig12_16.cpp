// fig12_16.cpp

#include <iostream>
#include <string>
#include <memory>
#include <new>
using namespace std;

int main(void) {
    unique_ptr<string> ups(new string("Hello World"));
    unique_ptr<string> ups2(ups);
    return 0;
}

// 编译报错
/**
 fig12_16.cpp:11:32: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]’
     unique_ptr<string> ups2(ups);
*/
// 通过编译器报错可知，这个拷贝构造函数是删除的(delete)状态