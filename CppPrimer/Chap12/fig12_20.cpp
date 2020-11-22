// g++ -std=c++11 -o main fig12_20.cpp StrBlob/StrBlob.o StrBlobPtr/StrBlobPtr.o

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "StrBlobPtr/StrBlobPtr.h"
#include "StrBlob/StrBlob.h"
using namespace std;

int main(int argc, char **argv) {
    string line;
    ifstream input(argv[1]);
    if (argc != 2) {
        cout << "输入参数有误" << endl;
        return -1;
    }
    if (!input) {
        cout << "打开文件失败" << endl;
        return -1;
    }
    StrBlob b;
    while (getline(input, line)) 
        b.push_back(line);
    for (auto it = b.begin(); !eq(it, b.end()); it.incr())
        cout << it.deref() << endl;
    return 0;
}