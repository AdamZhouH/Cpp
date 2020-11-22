// fig14_42.cpp
// 利用算法库的算法配合可调用对象作为参数传入算法中
// 从而完成相应的功能实现

#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

// 统计大于1024的值的个数
// 找到第一个不等于pooth的字符串
// 将所有的值乘以2

int main(int argc, char **argv) {
	int val;
	string s;

	vector<int> ivec;
	vector<string> svec;

	while (cin >> val)
		ivec.push_back(val);
	if (!cin) {
		cout << "vector<int>输入结束" << endl;
		cin.clear();
	}
	while (cin >> s) 
		svec.push_back(s);
	if (!cin) {
		cout << "vector<string>输入结束" << endl;
		cin.clear();
	}
	
	count_if(ivec.begin(), ivec.end(), bind2nd(greater<int>(), 1024));
	find_if(svec.begin(), svec.end(), bind2nd(not_equal_to<string>(), "pooh"));
	transform(ivec.begin(), ivec.end(), bind2nd(multiplies<int>(), 2));
}