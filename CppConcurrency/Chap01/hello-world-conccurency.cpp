#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello Concurrent World" << std::endl;
}

int main(int agrc, char *argv[]) {
    std::thread t(hello);
    t.join();
}