#include <random>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


void printNumbers(default_random_engine& dre) {
    for (int i = 0; i < 6; i++) {
        cout << dre() << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    // create engine and generate numbers
    default_random_engine dre;
    printNumbers(dre);

    // create equal engine and generate nubmers;
    default_random_engine dre2;
    printNumbers(dre2);

    // create engine with initial state specified by a seed
    default_random_engine dre3(42);
    printNumbers(dre3);

    // save state of engine
    stringstream engineState;
    engineState << dre;

    // generate numbers according to current state of dre
    
}
