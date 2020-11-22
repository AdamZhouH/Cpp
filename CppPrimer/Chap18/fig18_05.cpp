// fig18_05.cpp

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main(void) {
	// 使用C++标准
	try {
		throw exception();
	} catch (exception e) {
		cerr << "Caught a Exception" << endl;
		cerr << e.what() << endl;
	}
	cout << "Exception handlered" << endl;
	return 0;
}