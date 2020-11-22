// fig10_09.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

#define USE_STABLE

using namespace std;

// predicate isShorter
bool isShorter(const string &s1, const string &s2) { return s1.size() < s2.size(); }

void print(vector<string> &words) {
	for (auto it = words.cbegin(); it != words.cend(); it++)
		cout << *it << '\t';
	cout << endl;
}

#ifndef USE_STABLE
void elimDups(vector<string> &words) {
	cout << "not use stable" << endl;
	print(words);
	sort(words.begin(), words.end());
	print(words);
	auto end_unique = unique(words.begin(), words.end());
	print(words);
	words.erase(end_unique, words.end());
	print(words);
}
#else
void elimDups(vector<string> &words) {
	cout << "use stable" << endl;
	print(words);
	sort(words.begin(), words.end());
	print(words);
	auto end_unique = unique(words.begin(), words.end());
	print(words);
	words.erase(end_unique, words.end());
	stable_sort(words.begin(), words.end(), isShorter);
	print(words);
}
#endif

int main(void) {
	ifstream input("data.txt");
	string tmp;
	vector<string> svec;
	while(input >> tmp)
		svec.push_back(tmp);
	elimDups(svec);
	return 0;
}