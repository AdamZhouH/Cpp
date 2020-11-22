// fig16_06.cpp
// 定义自己版本的 为数组提供迭代器的 begin 和 end 函数

#include <iostream>
#include <string>
// using namespace std;

// begin() end()
// 很显然，end 必须知道数组元素的类型，以及数组的大小， 才能计算尾后指针的值，数组大小利用
// 模板参数列表中的非类型参数去推断
// begin 则不需要直到数组的大小, 但是为了保证 对于数组的引用，一定要知道大小，应此加上


template <typename T, unsigned N>
T* begin(const T (&arr)[N]) {
	std::cout << "Using begin" << std::endl;
	return (T *)(arr);
}

template <typename T, unsigned N>
T* end(const T (&arr)[N]) {
	std::cout << "Using end" << std::endl;
	return (T *)(arr) + N;
}

int main(void) {
	int a[] = {1,2,3,5,6,7,9,8,4};
	auto b = begin(a);
	auto e = end(a);
	std::cout << *b << " " << *--e << std::endl;
	return 0;
}