// fig09_26.cpp
// g++ -std=c++11 -o main fig09_26.cpp
// 使用数组的begin end函数，最好加上std::作用域声明符

#include <iostream>
#include <vector>
#include <list>

#define USE_ASSIGN //  使用assign给空list和vector赋值，默认使用insert

int ai[] = {0,1,1,2,3,5,8,13,21,55,89};

int main(int argc, char **argv) {

	std::vector<int> ivec;
	std::list<int> ilst;
	// copy from array
#ifdef USE_ASSIGN
	std::cout << "use assign " << std::endl;
	ivec.assign(std::begin(ai), std::end(ai));
	ilst.assign(std::begin(ai), std::end(ai));
#else
	std::cout << "use insert " << std::endl;
	ivec.insert(ivec.begin(), std::begin(ai), std::end(ai));
	ilst.insert(ilst.begin(), std::begin(ai), std::end(ai));
#endif

	// before deleting
	std::cout << "in vector" << std::endl;
	for (auto i : ivec) 
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << "in list" << std::endl;
	for (auto i : ilst) 
		std::cout << i << " ";
	std::cout << std::endl;

	// erasing even int from vector
	auto vit = ivec.begin();
	while (vit != ivec.end()) {
		if (*vit % 2 == 0) {
			vit = ivec.erase(vit);
		} else {
			vit++;
		}
	}
	// erasing odd int from vector
	auto lit = ilst.begin();
	while (lit != ilst.end()) {
		if (*lit % 2 != 0) {
			lit = ilst.erase(lit);
		} else {
			lit++;
		}
	}

	// after deleting
	std::cout << "in vector" << std::endl;
	for (auto i : ivec) 
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << "in list" << std::endl;
	for (auto i : ilst) 
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}