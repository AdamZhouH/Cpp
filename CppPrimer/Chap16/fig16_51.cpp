#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename... Args>
void foo(const T &t, const Args & ...args) { 
	cout << "template argument size: " << sizeof...(Args) << endl;
	cout << "factual argument size: " << sizeof...(args) << endl;
}

int main(void) {
	int i = 47;
	double d = 3.14;
	string s = "how now brown cow";

	foo(i, s, 42, d);
	foo("hi");
	foo(d, s);
	foo(s, 42, 34, "hi");

	return 0;
}