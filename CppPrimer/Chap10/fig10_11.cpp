#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

template <typename Container>
void print(const Container &container) {
    for (auto it = container.begin(); it != container.end(); it++)
        cout << *it << ' ';
    cout << endl;
}

template <typename T, size_t N>
void print(const T(&arr)[N]) {
    auto last = end(arr);
    for (auto it = begin(arr); it != last; it++)
        cout << *it << ' ';
    cout << endl;
}

template <typename T>
void elimDups(vector<T> &vec) {
    sort(vec.begin(), vec.end());
    auto it = unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
}

bool isShorter(const string &lhs, const string &rhs) {
    return lhs.size() < rhs.size();
}

int main(void) {
    vector<string> vec = {"Hello", "Kitty", "China", "America", "Cpp", "Python", "China", "Hello", "Banana", "Cpp"};
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    print(vec);
    string arr[] = {"Apple", "Banana", "Orange", "Pea", "Milk"};
    print(arr);
    return 0;
}