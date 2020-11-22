// fig12_14.cpp fig12_15.cpp

#include <iostream>
#include <memory>
#include <new>
using namespace std;
// 注意，给智能指针添加可调用的删除操作之后，智能指针可以去管理任何一个指针
// 而不仅仅是动态内存的指针了，而且，不会使用delete(默认使用delete)去处理
// 要销毁的对象，而是对管理的对象调用可调用的删除对象


#define USE_SMARTPOINTER
#define USE_LAMBDA

struct destination { };
struct connection { };

connection connect(destination *);
void disconnect(connection);
void f(destination &);
void end_connection(connection *);

connection connect(destination *d) {
    cout << "打开连接" << endl;
    return connection();
}

void disconnect(connection c) {
    cout << "关闭连接" << endl;
}

void end_connection(connection *c) {
    disconnect(*c);
}

#ifndef USE_SMARTPOINTER
void f(destination &d) {
    // 直接管理，不使用智能指针
    cout << "直接管理" << endl;
    connection c = connect(&d);
    // disconnect(c);
}
#else
void f(destination &d) {
    // 利用智能指针管理
#ifndef USE_LAMBDA
    cout << "使用智能指针管理，并且使用函数" << endl;
    connection c = connect(&d);
    shared_ptr<connection> pc(&c, end_connection);
#else
    cout << "使用智能指针管理，并且使用lambda表达式" << endl;
    connection c = connect(&d);
    shared_ptr<connection> pc(&c, [](connection *p) {
                                        disconnect(*p);
                                  });
#endif
}
#endif

int main(int argc, char **argv) {
    destination d;
    // 不要使用f(destination())
    // 因为不能去引用一个临时对象，参数类型是&而不是一个对象的副本
    f(d);
    return 0;
}
