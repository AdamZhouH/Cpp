// fig10_24.cpp

#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace std::placeholders;

bool check_size(int a, string::size_type sz) {
	return (to_string(a)).size() >= sz;
}

int main(void) {
	vector<int> ivec;
	ifstream input("intData.txt");
	if (!input) {
		cout << "打开文件失败" << endl;
		return -1;
	}
	int i;
	while (input >> i) 
		ivec.push_back(i);
	cout << ivec.size() << endl;
	string lengthInString;
	cout << "请输入查询整数的长度" << endl;
	cin >> lengthInString;
	int length = stoi(lengthInString);
	auto it = find_if(ivec.begin(), ivec.end(),
					  bind(check_size, _1, length));
	if (it == ivec.end())
		cout << "没有符合条件的整数" << endl;
	else 
		cout << "第一个长度大于 "<< length <<" 的整数是 " << *it << endl;
	return 0;
}