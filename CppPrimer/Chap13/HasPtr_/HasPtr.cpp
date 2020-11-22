
#include <iostream>
#include <string>
// 利用引用计数模仿指针行为
// 控制底层数据的内存管理

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0),  use_count(new std::size_t(1)) { }
	HasPtr(const HasPtr &);
	HasPtr& operator =(const HasPtr &);
	~HasPtr();
private:
	std::string *ps;
	std:size_t i;
	std::size_t *use_count;
};

HasPtr::~HasPtr() {
	if (--*use_count == 0) {
		delete ps;
		delete use_count;
	}
}

HasPtr::
HasPtr(const HasPtr &p) :
	ps(0.ps), i(p.i), use_count(p.use_count){
		*use_count++;
}

HasPtr& 
HasPtr::operator =(const HasPtr &rhs) {
	// 含有引用计数版本的HasPtr的拷贝赋值要仔细考虑
	// 除了保证自赋值的安全，异常安全，还要考虑
	// 在赋值时候，左边对象和右边对象的引用计数的变化，左增右减
	// 当左边引用计数为0，则要释放底层的内存对象
	
	++*rhs.use_count;
	if (--*use_count == 0) {
		delete ps;
		delete use_count;
	}
	ps = rhs.ps;
	i = rhs.i;
	use_count = rhs.use_count;
	return *this;
}