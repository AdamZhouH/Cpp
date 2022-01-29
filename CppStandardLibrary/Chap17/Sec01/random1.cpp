#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) { 
    default_random_engine dre;
    uniform_int_distribution<int> di(10, 20);

    // use engine to generate integral numbers between 10 and 20(both included)
    for (int i = 0; i < 20; i++) {
        cout << di(dre) << " ";
    }
    cout << endl;

    // use engine to generate floating-point numbers between 10.0 and 20.0
    // 10.0 included but not for 20.0
    // default template argument type is double 
    // can use uniform_real_distribution<double> as well
    uniform_real_distribution<> dr(10, 20);
    for (int i = 0; i < 20; i++) {
        cout << dr(dre) << " ";
    }
    cout << endl;

    // use engine to shuffle nubmers;
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    shuffle(v.begin(), v.end(), dre);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    shuffle(v.begin(), v.end(), dre);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}