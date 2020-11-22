#include <map>
#include <vector>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define method3

void fillStuff(vector<pair<string, int>> &stuff) {
    string str;
    int var;
    while (cin >> str >> var) {
#ifdef method1
        stuff.push_back(make_pair(str, var));
#else
    #ifdef method2
        stuff.push_back(pair<string, int>(str, var));
    #else
        stuff.push_back({str, var});
    #endif
#endif
    }
}

int main(int argc, char *argv[]) {
    vector<pair<string, int>> stuff;
    fillStuff(stuff);
    cin.clear();
    for (const auto &p : stuff) {
        cout << p.first << ":" << p.second << endl;
    }
    return 0;
}