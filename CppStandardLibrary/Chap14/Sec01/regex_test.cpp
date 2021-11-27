#include <regex>
#include <string>
#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

std::atomic<int> count_ = {0};

struct A {
    int a;
    double b;
};

int main(int argc, char *argv[]) {
    std::thread t1([](){
        count_.fetch_add(1);
    });
    std::thread t2([](){
        count_++;    // 等价于 fetch_add
        count_ += 1; // 等价于 fetch_add
    });
    t1.join();
    t2.join();
    std::cout << count_ << std::endl; 

    atomic<A> atomicA;
    cout << boolalpha << atomicA.is_lock_free() << endl;
    return 0;
    // string fileNames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    // regex txt_regex("[a-z]+\\.txt");
    // for (auto &file: fileNames) {
    //     cout << file << " : " << regex_match(file, txt_regex) << endl;
    // }
    // return 0;
}