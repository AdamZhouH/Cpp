// fig18_01.cpp

#include <iostream>
#include <stdexcept>
using namespace std;


// #define THROWBYPOINTER 

void TestException() {
	cout << "In TestException()" << endl;
	range_error r("error");
#ifndef THROWBYPOINTER
	throw r;
#else
	exception *p = &r;
	throw *p;
#endif
} 

int main(void) {
	TestException();
	cout << "In main()" << endl;
	return 0;
}