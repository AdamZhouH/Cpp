// fig10_30.cpp

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

void sortInIOStream() {
	// 输入输出迭代器绑定
	istream_iterator<int> input_iter(cin), eof;
	ostream_iterator<int> output_iter(cout, " ");
	vector<int> wordSet;
	// 标准输入读取，存入vector
	copy(input_iter, eof, back_inserter(wordSet));
	// 排序
	sort(wordSet.begin(), wordSet.end());
	// 输出到标准输出
	copy(wordSet.begin(), wordSet.end(), output_iter);
	cout << endl;
}

int main(void) {
	cout << "请输入一系列整数" << endl;
	sortInIOStream();
	return 0;
}