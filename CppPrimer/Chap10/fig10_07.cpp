// fig10_07.cpp

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

template <typename Iter>
void printContainer(Iter begin, Iter end) {
	while (begin != end) {
		cout << *begin << ' ';
		begin++;
	}
}

int main(void) {
	vector<int> vec;
	list<int> lst;
	int i;
	while (cin >> i)
		lst.push_back(i);
	
	cout << "Before" << endl;
	cout << "vector<int> : ";
	printContainer(vec.begin(), vec.end());
	cout << endl;

	cout << "list<int> :";
	printContainer(lst.begin(), lst.end());
	cout << endl;

	copy(lst.begin(), lst.end(), back_inserter(vec));

	cout << "After" << endl;
	cout << "vector<int> : ";
	printContainer(vec.begin(), vec.end());
    cout << endl;
	return 0;
}