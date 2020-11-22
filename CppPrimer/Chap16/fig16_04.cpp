// fig16_05.cpp

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <typename T, unsigned N>
void print(ostream &os, const T (&arr)[N]) {
	for (auto &e : arr)
		os << e << ' ';
}

int main(void) {
	string a[15] = {"Hello", "World", "Funny"};
	a[13] = "Java";
	int b[] = {1,3,4,5,6,8};
	print(cout, a);
	cout << endl;
	print(cout, b);
	cout << endl;
	return 0;
}