// fig15_13.cpp

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    string name(){ return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};

class Derived : public Base {
public:
    void print(ostream &os) { 
        Base::print(os);
        os << " " << i;
    }
private:
    int i = 15;
};

int main(void) {
	Derived d;
	d.print(std::cout);
	return 0;
}