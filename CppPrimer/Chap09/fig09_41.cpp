// fig09_41.cpp
// 从vector<char>初始化一个string
// 把vector<char>当成字符数组使用，则必须直到首元素的地址，使用data()成员函数返回首地址

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	vector<char> cvec = {'s','i','z','e'};
	string s(cvec.data(), cvec.size());
	cout << s << endl;
	return 0;
}