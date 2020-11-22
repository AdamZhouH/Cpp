// fig13_13.cpp

#include <iostream>
#include <string>
#include <vector>

struct X {
	X() { 
		std::cout << "X() " << std::endl; 
	}

	X(const X&) { 
		std::cout << "X(const X&) " << std::endl; 
	}

	X& operator =(const X&) { 
		std::cout << "X& operator =(const X&) " << std::endl; 
	}
	
	~X() { 
		std::cout << "~X() " << std::endl; 
	}
};

void foo(const X&) { std::cout << "传递引用 " << std::endl; }
void bar(X) { std::cout << "传递非引用 " << std::endl; }

int main(int argc, char **argv) {
	X x;
	std::cout << std::endl;
	{
		std::vector<X> xvec;
		xvec.push_back(x);
	}
	std::cout << std::endl;
	X *px = new X();
	std::cout << std::endl;
	*px = x;
	std::cout << std::endl;
	delete px;
	std::cout << std::endl;
	return 0;
}

// output result
/*
# panda @ ThinkPad in ~/文档/代码/CppPrimer/Chap13 [21:16:04] 
$ ./fig13_13 
X() 

X(const X&) 
~X() 

X() 

X& operator =(const X&) 

~X() 

~X() 

*/