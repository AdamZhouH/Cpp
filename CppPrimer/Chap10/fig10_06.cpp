// fig10_06.cpp

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[]) {
	std::vector<int> ivec;
	int val;
	while (std::cin >> val) 
		ivec.push_back(val);
	std::cin.clear();
	std::cout << "Before:" << std::endl;
	for (auto it = ivec.begin(); it != ivec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::fill_n(ivec.begin(), ivec.size(), 0);
	std::cout << "After fill with 0" << std::endl;
	for (auto it = ivec.begin(); it != ivec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	return 0;
}
