#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_of_unique = unique(words.begin(), words.end());
	words.erase(end_of_unique, words.end());
}

bool check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

void biggiest(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	for_each(words.begin(), words.end(),
			 [] (const string &s) {
			 	cout << s << '\t';
			 });
	cout << endl;
	auto wc = partition(words.begin(), words.end(),
						bind(check_size, _1, sz));
	auto count = wc - words.begin();
	cout << count << " 个长度至少为 " << sz << " 的元素" << endl;
	for_each(words.begin(), wc, 
			[] (const string &s) {
				cout << s << '\t';
			});
	cout << endl;
}

int main(void) {
	ifstream input("data.txt");
	if (!input) {
		cout << "打开文件失败" << endl;
		return -1;
	}
	vector<string> svec;
	string tmp;
	while (input >> tmp)
		svec.push_back(tmp);
	biggiest(svec, 5);
	return 0;
}