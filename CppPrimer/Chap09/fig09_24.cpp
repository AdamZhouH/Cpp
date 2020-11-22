// fig09_24.cpp

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
	std::vector<std::string> strvec;
	// 利用at 下标 front begin 访问空vector的第一个元素
 	std::cout << strvec.at(0);
	std::cout << strvec[0];
	auto first = strvec.front();
	std::cout << first;
	auto it = strvec.begin();
	std::cout << *it;
	std::cout << std::endl;
	return 0;
}

// at: 抛出异常out_of_range
// 下标：段错误，核心转储
// front: 段错误，核心转储
// begin: 段错误，核心转储