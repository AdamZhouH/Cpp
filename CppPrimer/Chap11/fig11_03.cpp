// fig11_03.cpp fig11_04.cpp
// 单词统计      单词统计（乎略最后的标点和大写字母）

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

#define IGNORE_PUNCT_UPPERCASE

string &wipePunctAndUpper(string &word) {
	if (ispunct(word.back()))
		word.pop_back();
	for (auto &c : word)
		c = tolower(c);
	return word;
}

void wordCount() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) 

#ifndef IGNORE_PUNCT_UPPERCASE
		++word_count[word];
#else
		++word_count[wipePunctAndUpper(word)];
#endif

	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second
			 << ((w.second > 1) ? "times" : "time") << endl;
}

// 当从map中提起一个元素时，我们会得到一个pair

int main(void) {
	wordCount();
	return 0;
}

