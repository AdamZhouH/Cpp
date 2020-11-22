// fig13_18.cpp

#include <iostream>
#include <string>

class Employee {
private:
	static int count;
	int ID;
	std::string name;
public:
	Employee() : ID(count++) { }
	Employee(const std::string &n) : name(n), ID(count++) { }
	// 其余拷贝控制成员的定义
	// 其实有一点很迷惑，个人觉得这种证件或者个人信息都是独立的，并不应该被拷贝构造或者随意赋值
	// 个人倾向与拷贝构造和拷贝赋值均设定为delete
	// 鉴于题目要求，还是给出一般的拷贝控制定义
	Employee(const Employee &o) : name(o.name), ID(count++) { }
	Employee& operator =(const Employee &o) {
		name = o.name;
		ID = count++;
	}
	std::string getName() const { return name; }
	int getID() const { return ID; }
};

int Employee::count = 0;

int main(void) {
	Employee e1("ZackQ");
	Employee e2(e1);
	Employee e3;
	e3 = e2;
	std::cout << e1.getName() << ' ' << e1.getID() << std::endl;
	std::cout << e2.getName() << ' ' << e2.getID() << std::endl;
	std::cout << e3.getName() << ' ' << e3.getID() << std::endl;
	return 0;
}