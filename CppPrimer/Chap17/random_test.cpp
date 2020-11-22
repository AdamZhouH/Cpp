#include <random>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

std::vector<int> foo_bar();

int main(void) {
	std::default_random_engine e;
	/*
	for (std::size_t i = 0; i < 10; i++) 
		cout << e() << endl;
	cout << "分布类型：" << endl;
	std::uniform_int_distribution<unsigned> u(0, 9);
	for (std::size_t i = 0; i < 10; i++) {
		// TODO
		cout << u(e) << " ";
	}
	*/
	cout << "Max random number: " << e.max() << endl;
	cout << "Min random number: " << e.min() << endl;
	/*
	std::vector<int> ret = foo_bar();
	for (auto i = 0; i < ret.size(); i++) {
		if (i % 10 == 0)
			cout << endl;
		cout << ret[i] << '\t';
	}
	*/

	default_random_engine e1;
	default_random_engine e2(2147483646);
	default_random_engine e3;
	default_random_engine e4(32767);
	e3.seed(32767);

	for (std::size_t i = 0; i !=100; i++) {
		if (e1() == e2())
			cout << "unseeded match at iteration: " << i << endl;
		if (e3() == e4())
			cout << "seeded differs at iteration: " << i << endl;
	}

	return 0;
}

// 随机数引擎
// Engine e;
// Engine e(s); s作为随机数种子
// e.seed(s);  设置新的随机数种子，重置引擎的状态
// e.min()
// e.max()
// Engine::result_type  类型成员
// e.discard(u)  把引擎推荐u步，u为signed long long类型

std::vector<int> foo_bar() {
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u(0, 9);
	std::vector<int> v;
	for (auto i = 0; i < 100; i++) 
		v.push_back(u(e));
	return v;
}

