// fig16_19.cpp

// 接受一个容器的引用，然后打印容器中的引用（使用 size_type size() 成员控制循环）

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>


#define USE_SIZE_TYPE

// 利用容器的size_type 和 size() 成员对循环进行控制
// 对容器的操作要求则是容器重载了下标操作 ，比如 list 就不能使用
#ifdef USE_SIZE_TYPE

template <typename Vector>
void Print(const Vector &vec) {
	std::cout << "Using size_type member" << std::endl;
	typedef typename Vector::size_type size_type;
	for (size_type it = 0; it < vec.size(); it++)
		std::cout << vec[it] << '\t';
	std::cout << std::endl;
}

#else
// 利用容器的迭代器对循环进行控制
template <typename Vector> 
void Print(const Vector &vec) {
	std::cout << "Using iterator member" << std::endl;
	auto it = vec.begin();
	auto e = vec.end();
	while (it != e) 
		std::cout << *it++ << '\t';
	std::cout << std::endl;
}

#endif
int main(int argc, char *argv[]) {
	std::vector<int> ivec = {1, 3, 5, 7, 9};
	std::deque<std::string> strdeq = {"hello", "world", "thank you"};
	// std::list<std::string> ilst = {2, 4, 6, 8, 10};
	Print(ivec);
	Print(strdeq);
	// Print(ilst);
	return 0;
}