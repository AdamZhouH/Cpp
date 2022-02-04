#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

// 需要明确的几点
// 1.创建线程都是通过std::stread对象来创建的
// 2.std::thread对象的构造函数接受任何的callable object（包括函数、函数指针、lambda表达式、functional、重载了operator()的类的对象等）
//   如果传入的是一个重载了operator()的对象，那么这个对象实际上是被copy到新的线程的。
// 3.创建了std::thread对象后，新的线程开始执行，你必须决定是等待线程执行结束还是让线程自己运行（所谓join和detach）
//   如果是join的话，那么std::thread对象会在线程执行结束后被销毁，否则可能std::thread对象在线程执行完毕之前销毁，而std::thread对象的
//   析构函数中调用了terminate，导致整个进程结束。所以必须确保线程是正确的join或者detached，即使是在面对抛出异常的情况下。
//   如果线程标记为detachecd，那么线程便可以独自运行，即使std::thread对象销毁了也不会影响(不会调用terminate)。
// 4.由此引出了对象在多线程中的生命周期的问题。另一个线程访问的对象是否已经被销毁？

// 每个thread对象只能调用一次join，并且可以通过joinable()来判断是否可以join
// 当调用join时，如果线程已经执行完毕，那么会清理线程的相关的storage，然后thread对象就不能再次被join了

// 调用join的时机也要注意，因为如果线程中执行的代码可能抛出异常，那么即使之后的代码中有调用join，也可能因为
// 抛出的异常而忽略掉。比如如下的处理方式
//
////////////////////////////////////////////////////////////////////////////
void do_something_in_main_thread();
void my_func();
void f() {
    int some_local_state = 0;
    func my_func(some_local_data);
    std::thread t(my_func);
    try {
        do_something_in_main_thread();
    } catch(...) {
        t.join();
        throw;
    }
    t.join();
}
// 或者使用RAII的做法，将thread对象包在一个class对象中，然后析构函数中调用join
class thread_guard {
    std::thread &t;
public:
    explicit thread_guard(std::thread &t_) : t(t_) { }
    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    }

    thread_guard(const thread_guard &) = delete;
    thread_guard &operator = (const thread_guard &) = delete;
};
////////////////////////////////////////////////////////////////////////////

void do_something(int val) {
    // some stuff here
    std::cout << val << std::endl;
    sleep(1);
}
struct func {
    int &i;
    func(int &i_) : i(i_) {}

    void operator() () {
        for (unsigned j = 0; j < 10; j++) {
            do_something(i);
        }
    }
};

void oops() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    // 这里开始detach线程，让线程脱离my_thread对象独立运行
    // 但是实际上在函数opps退出后，some_local_state也被销毁了
    // 并且在oops推出后，main函数所在的主线程也退出，导致整个进程结束，因此func中的循环执行不了多久
    my_thread.detach();
    std::cout << "opps() exit and the local_variable some_local_state destroyed" << std::endl;
}


int main(int argc, char *argv[]) {
    oops();
    // 这里sleep是因为，如果主线程不sleep的话，直接结束，导致整个进程结束，从而观察不到my_thread线程中的输出
    sleep(5);
    return 0;
}