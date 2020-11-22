// fig_10_27.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>

// 使用插入迭代器往一个空容器中拷贝元素

using namespace std;

void uniqueCopy(vector<int> &src, vector<int> &des) {
	vector<int> tmp = src;
	sort(tmp.begin(), tmp.end());
	auto endOfUnique = unique(tmp.begin(), tmp.end());
	tmp.erase(endOfUnique, tmp.end());
	auto it= back_inserter(des);
	unique_copy(tmp.cbegin(), tmp.cend(), it);
}

inline
void printElement(vector<int> &vec) {
	for_each(vec.begin(), vec.end(),
			 [] (int i) {
			 	cout << i << '\t';
			 });
	cout << endl;
}

bool readElement(vector<int> &vec, const string &s) {
	ifstream input(s);
	if (!input) {
		cout << "打开文件失败" << endl;
		return false;
	} else {
		int i;
		while (input >> i)
			vec.push_back(i);
		return true;
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "参数不正确" << endl;
		return -1;
	} 
	vector<int> src, des;
	if (!readElement(src, argv[1])) {
		cout << "读取数据失败" << endl;
		return -1;
	}
	uniqueCopy(src, des);
	printElement(src);
	printElement(des);
	return 0;
}