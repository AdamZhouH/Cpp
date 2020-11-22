
#include "HasPtr.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	HasPtr obj;
	// 带参构造函数被调用
	std::string s("Hello World!");
	std::cout << obj << std::endl;
	obj = s;
	// 带参构造函数被调用 拷贝赋值函数被调用
	std::cout << obj << std::endl;
	HasPtr obj2 = obj;
	// 拷贝构造函数被调用
	HasPtr obj3(obj2);
	// 拷贝构造函数被调用 
	{
		std::cout << " obj3 赋值 开始 " << std::endl;
		obj3 = obj3;
		std::cout << " obj3 赋值 结束 " << std::endl;
		// 根据程序运行的结果，说明编译器对于自赋值这种行为进行了优化，没有调用相应函数
	}
	// 拷贝赋值函数被调用
	obj3 = std::string("Cpp kill Java");
	// 代参构造函数被调用 拷贝赋值函数被调用
	std::cout << obj3 << std::endl;
	return 0;
}