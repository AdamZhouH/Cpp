// fig16_02.cpp

#include <string>
#include <iostream>

template <typename T>
inline 
bool compare(const T& lhs, const T& rhs) {
	return lhs < rhs;
}

int main(void) {
	std::cout << compare(1.2, -4.4) << std::endl;
	std::cout << compare(3, 5) << std::endl;
	std::cout << compare("HELLO", "WORLD") << std::endl;
	std::cout << compare(std::string("HELLO"), std::string("WORLD")) << std::endl;
	// 最后两行输出不一致，说明compare模板并不支持正确的指针比较行为
	return 0;
}
