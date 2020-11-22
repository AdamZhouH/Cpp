#include "HasPtr.h"
#include <string>
#include <iostream>

HasPtr::HasPtr(const HasPtr &o) :
	i(o.i), ps(new std::string(*o.ps)){
		std::cout << "拷贝构造函数被调用 " << std::endl;
	}

HasPtr&
HasPtr::operator =(const HasPtr &orig) {
	if (this != &orig) {
		auto temp = ps;
		auto p = new std::string(*orig.ps);
		ps = p;
		i = orig.i;
		delete temp;
		std::cout << "拷贝赋值函数被调用 " << std::endl;
	} 
	return *this;
}

HasPtr::~HasPtr() {
	delete ps;
}

std::ostream& operator << (std::ostream &os, const HasPtr &o) {
	os << *o.ps;
	return os;
}