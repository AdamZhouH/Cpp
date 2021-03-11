#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

void test1() {
    unique_ptr<string> uptr(new string("Hello World"));
    unique_ptr<string> uptr2;
    // it's ok because we assgin uptr2 with a rvalue
    uptr2 = unique_ptr<string> (new string("rvalue"));
    // it's ok we use move to get rvalue
    uptr2 = move(uptr);
}

void passUniquePtr(unique_ptr<string> uptr) {
    // do nothing
}

unique_ptr<string> returnUniquePtr() {
    unique_ptr<string> uptr(new string("Hello World"));
    return uptr;
}

void test2() {
    unique_ptr<string> uptr(new string("Hello World"));
    // not ok because it will call the copy constructor which is deleted in unique_ptr
    // testUniquePtr(uptr);
    // and move(uptr) is ok because move semantic is allowed in unique_ptr
    passUniquePtr(move(uptr));
}

int main(int argc, char *argv[]) {
    test1();
    test2();
    return 0;
}