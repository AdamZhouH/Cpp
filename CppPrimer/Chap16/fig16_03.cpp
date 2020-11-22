// fig16_03.cpp

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <typename It, typename V>
It find(const It &begin, const It &end, const V &value) {
	It it;
	for (it = begin; it != end; it++)
		if (*it == value)
			return it;
	return it;
}

int main(void) {
	vector<int> iv = {1,2,4,5,7,8,9,100,400};
	list<string> sl = {"hello",
		"this", "really", "object", "Java", "Cpp"};

	auto it = find(iv.cbegin(), iv.cend(), 100);
	if (it != iv.cend())
		cout << "find " << *it << " in vector<int>" << endl;
	else
		cout << "not in vector<int>" << endl;

	auto it1 = find(sl.cbegin(), sl.cend(), "Java");
	if (it1 != sl.cend())
		cout << "find " << *it1 << " in list<string>" << endl;
	else
		cout << "not in list<string>" << endl;

	vector<list<int>> v = {{1,3,5,7,9},
						   {2,4,6},
						   {3,3,3,3}};
	auto it2 = find(v.cbegin(), v.cend(), list<int>({3,3,4,3,3}));
	if (it2 != v.cend()) {
		cout << "find in v" << endl;
		for (auto i : *it2)
			cout << i << "\t";
		cout << endl;
	}
	else
		cout << "not in v" << endl;
	return 0;
}
