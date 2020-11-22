// fig10_16.cpp fig10_18.cpp
// lambda表达式的练习
// 注意：实际上当我们定义一个lambda表达式时，编译器实际上创建了一个新的未命名类类型

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#define USE_PARTITION

using namespace std;

// 使用lambda表达式
void biggest(vector<string> &words, vector<string>::size_type sz) {
	// 按照字典排序并且删除重复的单词
	sort(words.begin(), words.end());
	auto endOfUnique = unique(words.begin(), words.end());
	words.erase(endOfUnique, words.end());
#ifndef USE_PARTITION
	cout << "stable_sort version:" << endl;
	// 按照长度排序,同时保持原来的字典顺序
	stable_sort(words.begin(), words.end(),
				[] (const string &s1, const string &s2) -> bool { 
					return s1.size() < s2.size();
				});
	// 找到第一个长度不小于sz的元素，并得到其迭代器
	auto bigWord = find_if(words.begin(), words.end(), 
							   [sz] (const string &s) -> bool {
							   		return s.size() >= sz;
							   });
	// 显示所有长度不小于sz的元素
	for (; bigWord != words.end(); bigWord++)
		cout << *bigWord << '\t';
	cout << endl;
#else
	cout << "partition version:" << endl;
	// 只需要删除重复元素，然后再partition即可，不需要按照长度进行排序，节省了工作量
	// 利用库函数partition给元素排序
	auto afterLastBigWord = partition(words.begin(), words.end(),
							 [sz] (const string &s) -> bool {
							 	return s.size() >= sz;
							 });
	// 显示所有长度不小于sz的元素
	for (auto it = words.begin(); it != afterLastBigWord; it++)
		cout << *it << '\t';
	cout << endl;
#endif
}

int main(void) {
	vector<string> words;
	string w;
	ifstream input("data.txt");
	while (input >> w)
		words.push_back(w);
	for (auto &w : words)
		cout << w << '\t';
	cout << endl;
	biggest(words, 5);
	for (auto &w : words)
		cout << w << '\t';
	cout << endl;
}
