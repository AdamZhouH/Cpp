#include <iostream>
using namespace std;

int func(void) {
	static int count = -1;
	return ++count;
}

int main(void) {
	for (int i = 0; i < 10; i++)
		cout << func() << endl;
	return 0;
}