// 形参：形参的作用域在函数的块内，生命周期则是当函数退出之后就被销毁
// 局部变量：在块作用于内，一般当退出块作用域之后，局部变量也被销毁
// 局部静态变量：局部变量的作用域仍然是在函数块内，但是生命周期则是存在于整个程序的运行期间

int countAddingTimes(int a, int b) {
	static size_t times = 0;
	int sum = a + b;
	return ++times;
}