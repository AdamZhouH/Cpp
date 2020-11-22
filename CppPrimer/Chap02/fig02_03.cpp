#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    unsigned u = 10;
    unsigned u2 = 42;

    cout << u2 - u << endl;
    cout << u - u2 << endl;

    int i = 10;
    int i2 = 42;
    int i3 = -10;

    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u << endl;
    cout << u - i << endl;

    cout << i - u2 << endl;
    cout << i3 + u2 << endl;
    cout << i3 - u2 << endl;

    return 0;
}