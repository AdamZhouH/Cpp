#include <iostream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

int main(void) {
	default_random_engine e;
	// 正态分布 normal_distribution
	normal_distribution<> n(4, 1.5);
	vector<unsigned> vals(9);
	for (size_t i = 0; i != 200; i++) {
		// lround() 取最接近的整数
		unsigned v = lround(n(e));
		if (v < vals.size())
			++vals[v];
	}
	// 打印出vals中的数据的分布形态
	for (auto &val : vals) {
		for(std::size_t i = 0; i < val; i++)
			std::cout << '*';
		std::cout << std::endl;
	}
	return 0;
}
