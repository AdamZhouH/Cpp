#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <memory>  // for shared_ptr
#include <fstream> // for ofstream 
#include <cstdio>  // for remove()
using namespace std;

class FileDeleter {
private:
    string fileName;
public:
    FileDeleter(const string &fn)
        : fileName(fn) { }
    void operator ()(ofstream *fp) {
        fp->close();                    // close file
        remove(fileName.c_str());       // delete file
    }
};

int main(int argc, char *argv[]) {
    shared_ptr<ofstream> fp(new ofstream("temp.txt"), FileDeleter("temp.txt"));
    // some thing else to do
    return 0;
}