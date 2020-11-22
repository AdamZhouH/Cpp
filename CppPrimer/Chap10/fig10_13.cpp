// fig10_13.cpp

#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <list>

bool JudgeLength(const std::string &s) {
	return s.size() >= 5 ? true : false;
}

int main(void) {
	std::vector<std::string> svec;
	std::string s;
	while (std::cin >> s)
		svec.push_back(s);
	std::cin.clear();
	for (auto &s : svec)
		std::cout << s << '\t';
	std::cout << std::endl;
	auto lastTrue = std::partition(svec.begin(), svec.end(), JudgeLength);
	for (auto it = svec.cbegin(); it != lastTrue; it++)
		std::cout << *it << '\t';
	std::cout << std::endl;
	return 0;
}