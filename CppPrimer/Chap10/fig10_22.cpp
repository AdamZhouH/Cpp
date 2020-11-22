// fig10_22.cpp

#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

// 可调用对象不一定单指的 lambda 表达式
// 函数 函数指针 重载调用运算符的对象 都可以作为可调用对象
// bind 函数作为一个函数适配器，用于装饰一个函数，让其能够表现出附加的属性
// bind 修饰一个可调用对象，可以减少其参数，从而满足部分算法对于謂词的参数个数的约束
// bind 修饰后的可调用对象仍然是一个可调用对象

using namespace std::placeholders;
using namespace std;

bool JudgeSize(const string &s, size_t sz) { 
	return s.size() >= sz;
}

int main(void){
	vector<string> words;
	string w;
	size_t size = 5;
	ifstream input("data.txt");
	while (input >> w)
		words.push_back(w);
	auto num = count_if(words.begin(), words.end(), bind(JudgeSize, _1, size));
	cout << "There are " << num << (num > 1 ? " words " : " word ")
		 << "in the vector" << endl;
	return 0;
}