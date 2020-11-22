#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	map<string, size_t> word_count;
	set<string> exclude = {"the", "but",
					   	   "The", "But"};
	map<string, string> authors = {{"Joyce","James"},
								   {"Austin","Jane"},
								   {"Dickens","Charles"}};
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; i++) {
		ivec.push_back(i);
		ivec.push_back(i);
	}

	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;
	cout << miset.size() << endl;
	return 0;
}