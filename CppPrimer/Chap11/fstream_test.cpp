#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
	ifstream input(argv[1]);
	string line;
	while (getline(input, line))
		cout << line << endl;
	return 0;
}