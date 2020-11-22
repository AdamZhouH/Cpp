// fig10_20.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int biggest(vector<string> &wordSet, int size) {
	int num = 0;
	// 先去除重复数据
	sort(wordSet.begin(), wordSet.end());
	vector<string>::iterator after_last_unique;
	after_last_unique = unique(wordSet.begin(), wordSet.end());
	wordSet.erase(after_last_unique, wordSet.end());
	// 统计数据
	num = count_if(wordSet.begin(), wordSet.end(), [size] (const string &word) {
		return word.size() > size;
	});
	return num;
}

int main(void) {
	int count;
	int size = 6;
	vector<string> svec = {"hello", "harray potter", "word set", "word set", "harray potter"};
	count = biggest(svec, size);
	cout << "长度大于" << size << "的单词一共有" << count << "个（重复单词只做一次统计）" << endl;
	return 0;
}
