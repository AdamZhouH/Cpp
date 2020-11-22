// fig12_23.cpp

#include <iostream>
#include <string>
#include <cstring>

const char *s1 = "Hello";
const char *s2 = "World";

void
strJoin(const char *s1, const char *s2) {
// 拼接字面值常量
    auto len1 = strlen(s1);
    auto len2 = strlen(s2);
    auto totalSize = len1 + len2 + 1;   // for '\0'
    auto ret = new char[totalSize];
    strcpy(ret,s1);
    strcat(ret,s2);
    std::cout << ret << std::endl; 
// 拼接string对象
    std::string s3 = "Hello";
    std::string s4 = "World";
    strcpy(ret,(s3 + s4).c_str());
    std::cout << ret << std::endl;
// 释放内存
    delete [] ret;
}

int main(void) {
    strJoin(s1, s2);
    return 0;
}