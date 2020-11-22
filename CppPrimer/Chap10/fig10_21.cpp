#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int a = 5;
	// lambda 表达式的参数列表不要随便省略，未加括号时，编译报错如下
	// 另外，对于值捕获，在lambda内也只是read-only变量，除非加上mutable属性
	auto f = [&]() -> bool {
		if (a > 0) {
			a--;
			return false;
		} else
			return true;
	};
	while(!f()) { 
		cout << a << endl;
	}
	return 0;
}

/**
fig10_21.cpp: In lambda function:
fig10_21.cpp:9:15: error: expected ‘{’ before ‘->’ token
  auto f = [&] -> bool {
               ^
fig10_21.cpp: In function ‘int main()’:
fig10_21.cpp:9:15: error: base operand of ‘->’ has non-pointer type ‘main()::<lambda()>’
fig10_21.cpp:9:18: error: expected unqualified-id before ‘bool’
  auto f = [&] -> bool {
                  ^
fig10_21.cpp:20:1: error: expected ‘,’ or ‘;’ at end of input
 }
 ^
fig10_21.cpp:20:1: error: expected ‘}’ at end of input
*/