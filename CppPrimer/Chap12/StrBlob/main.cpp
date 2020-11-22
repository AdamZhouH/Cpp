#include "StrBlob.h"
#include <iostream>
using namespace std;

int main(void) {
    StrBlob b1;
    {
        StrBlob b2({"a","an","the"});
        cout << b1.size() << endl;
        cout << b2.size() << endl;
        b1 = b2;
        cout << b1.size() << endl;
        cout << b2.size() << endl;
        b2.push_back("about");
        cout << b1.size() << endl;
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;
    const StrBlob b3({"this","is","const"});
    cout << b3.size() << endl;
    return 0;
}