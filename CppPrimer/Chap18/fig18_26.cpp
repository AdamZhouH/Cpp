// fig18_26.cpp

#include <iostream>
#include <string>
#include <vector>

struct Base1 {
public:
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};

struct Base2 {
public:
	void print(double) const;
protected:
	double fval;
private:
	double dval;
};

struct Derived : public Base1 {
public:
	void print(std::string) const;
protected:
	std::string sval;
	double dval;
};

struct MI : public Derived, public Base2 {
	// using Base1::print;
	// using Base2::print;
public:
	void print(std::vector<double>);
	void foo(double cval);
protected:
	int *ival;
	std::vector<double> dvec;
};

int ival;
double dval;

void MI::foo(double cval) {
	int dval;
	// TODU
	dval = Base1::dval + Derived::dval;  // double to int

	fval = dvec.back();

	sval[0] = cval;
}



int main(void) {
	MI mi;
	mi.print(42);
	return 0;
}

// 1.修改MI的定义，使得对print(42)的调用可以正确的运行
//   由于print的名称查找，在MI类自身的作用域中就能找到，而且基类继承来的print会因为名称
//   已经存在而被遮掩，因此，调用的是本类的print(std::vector<double>),但是由于参数的
//   不匹配，因此，调用会报错
//   修改方法显然要考虑到让基类继承而来的print成为重载函数而不是被本类的print(std::vector<double>)
//   而遮掩，因此使用using声明，介于 间接基类Base1 和 直接基类Base2 都存在可行的函数
//   虽然Base2的是print(double)，但是int可以直接转换为double，因此可行方法两种
//   1) 添加 using Base1::print; 
//   2) 添加 using Base2::print;
//   或者两者都添加也行，此时，由于多个重载函数是可行的，编译器会选择最优匹配 Base1::print(int)

// 2.各种子问题的求解（熟悉名称查找的规则，多重继承时的继承特点）
//   a) 考虑 foo 函数中可见的名字
//		golbal: 全部被遮盖   // 原来的global的dval则被局部的dval 遮掩，ival 被类内指针变量遮盖
//      类内的部分
//          数据成员：int *ival  vector<double> dvec int dval(local variable in foo)
//					double fval(Base2)  string sval(Derived)
//				    char cval(Base1)
//			成员函数: print(std::vector<double>)
//   b) 
//   c) 见 foo 函数内的代码实现
