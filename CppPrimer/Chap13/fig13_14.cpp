// fig13_14.cpp

#include <iostream>
#include <string>

class Numbered {
public:
	static int count;
	Numbered() {
		mysn = count++;
	}
	Numbered(const Numbered &orig) {
		mysn = count ++;
	}
	// Numbered& operator =(const Numbered &orig) = default;
	void f() const {
		std::cout << mysn << std::endl;
	}
private:
	int mysn;
};

int Numbered::count = 0;

// void f(const Numbered * const this) const;
// void f(Numbered * const this);
// 由于类型转换的原因，非const对象其实可以调用const成员函数，因为指针可以自动转型为const指针

int main(int argc, char **argv) {
	Numbered a, b = a, c = b;
	a.f();	b.f(); c.f();
	return 0;
}