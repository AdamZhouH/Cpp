// fig17_28.cpp

#include <random>
#include <iostream>

unsigned int Random() {
	static std::default_random_engine e;
	return e();
}

unsigned int RandomSeed(unsigned int s = 0) {
	std::default_random_engine e(s);
	return e();
}

unsigned int RandomRange(unsigned int s, unsigned int min, unsigned int max) {
	std::default_random_engine e(s);
	std::uniform_int_distribution<unsigned int> u(min, max);
	return u(e);
}

void Test1() {
	// Random()
	std::size_t i = 0;
	for (; i < 10; i++)
		std::cout << Random() << '\t';
}

void Test2() {
	// Random()
	std::size_t s = 15;
	std::size_t i = 0;
	for (; i < 10; i++)
		std::cout << RandomSeed() << '\t';
	std::cout << std::endl;
	for (i = 0; i < 10; i++)
		std::cout << RandomSeed() << '\t';
	std::cout << std::endl;
    for (i = 0; i < 10; i++)
		std::cout << RandomSeed(s) << '\t';
}

void Test3() {
	std::size_t s = 15;
	std::size_t min = 0, max = 18;
	for (auto i = 0; i < 20; i++)
		std::cout << RandomRange(s, min, max) << '\t';
}

int main(void) {
	// Random
	std::cout << "Test Random():" << std::endl;
	Test1();
	std::cout << std::endl;
	Test1();
	// RandomSeed
	std::cout << "Test RandomSeed():" << std::endl;
	Test2();
	// RandomRange
	std::cout << "Test RandomRange():" << std::endl;
	Test3();
	return 0;
}