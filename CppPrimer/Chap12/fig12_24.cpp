// fig12_24.cpp

#include <memory>
#include <new>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
using namespace std;

// 采取抛出异常方式处理保存空间不够
const int SIZE = 15;

int main(int argc,char **argv) {
    char *str = new char[SIZE];
    char c;
    size_t count = 0;
    // 错误，单独用cin读取char，空白字符会被乎略（空格 换行 制表）
    // 应当使用cin.get()
    while (cin.get(c)) {
        if (count >= SIZE - 1)
            throw std::runtime_error("保存空间不够");
        *(str + count) = c;
        count++;
    }
    *(str + count) = '\0';
    std::cout << str << std::endl;
    std::cout << strlen(str) << std::endl;
    delete [] str;
    return 0;
}

// 可以接着写一个利用截断方式处理保存空间不够的情况
// 每次保存之前判断长度，如果到达最大值，直接break即可