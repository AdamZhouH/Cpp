#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;

void test1() {
shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutta"));
    // shared_ptr<string> pJutta{new string("jutta")};
    // shared_ptr<string> pJutta = maake_shared<string>("jutta");

    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "J");

    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    for (auto ptr: whoMadeCoffee) {
        cout << *ptr << " ";
    }
    cout << endl;
    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
}

void test2() {
    shared_ptr<string> pNico;
    // this is error because there is no assignment for ordinary pointers
    // you have to use reset method instead of assignment operator
    // pNico = new string("nico"); // ERROR
    pNico.reset(new string("echo"));
}

// use our own deletor
void test3() {
    shared_ptr<string> pJutta(new string("jutta"), [](string *p) {
        cout << "delete string " << *p << endl;
        delete p;
    });
    // when pJutta was assgined by nullptr, original element will be released because pJutta is the only owner of
    // the string "jutta" at that time
    pJutta = nullptr;
    cout << "shared_ptr<string> has been assgined by nullptr";
}

// deal with arrays
void test4() {
    shared_ptr<int> pIntArr(new int[10], [](int *p) { delete [] p; });
    shared_ptr<double> pDoulbeArr(new double[10], default_delete<double[]>());
}

// shared_ptr and unique_ptr deal with deleters in slightly different ways
// 1.unique_ptrs provide the ability to own an array simply by passing the 
//   corresponding element type as template argument, whereas for shared_ptrs this is not possible
void test5() {
    unique_ptr<int[]> upIntArr(new int[10]);
    shared_ptr<int> spIntArr(new int[10], default_delete<int[]>());
    // if you want to use your own deletor in unique_ptr
    // you have yo specify a sceond template argument to specify your won deleter
    unique_ptr<int, void(*)(int*)> ipIntArr2(new int[10], [](int *p) {
        delete [] p;
    });
}

void test6() {
    shared_ptr<string> sp;
    cout << sp.unique() << endl;
    sp.reset(new string("Hello World"));
    shared_ptr<string> sp2(sp);
    cout << sp.unique() << " and use count is " << sp.use_count() << endl;
}

void test7() {
    shared_ptr<string> sp(new string("Hello World"));
    cout << sp << endl;
}

int main(int argc, char *argv[]) {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();
    return 0;
}