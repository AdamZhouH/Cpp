// fig10_29.cpp

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void readData(vector<string> &v, istream &is) {
	istream_iterator<string> iter(is), eof;
	while (iter != eof) {
		v.push_back(*iter++);
	}
}

void printData(vector<string> &v, ostream &os) {
	ostream_iterator<string> iter(os, " ");
	for_each(v.begin(), v.end(), [&](const string &s) {
		*iter++ = s;
	});
	os << endl;
}

int main(void) {
	vector<string> svec;
	readData(svec, cin);
	printData(svec, cout);
	return 0;
}