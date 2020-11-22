
#ifndef HASPTR_H
#define HASPTR_H

#include <iostream>
#include <string>
#include <memory>

class HasPtr {
	friend std::ostream& operator <<(std::ostream &, const HasPtr &);
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) {
			std::cout << "带参构造函数被调用 " << std::endl;
		}
	HasPtr(const HasPtr &o);
	HasPtr& operator =(const HasPtr &orig);
	~HasPtr();
private:
	std::string *ps;
	int i;
};

std::ostream& operator <<(std::ostream &, const HasPtr &);

#endif
