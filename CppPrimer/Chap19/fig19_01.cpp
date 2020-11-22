// fig19_01.cpp

#include <iostream>
#include <cstdlib>
#include <stdexcept>

void *operator new(size_t size) {
	if (void *mem = malloc(size + 2)) {
		std::cout << "Use Personal operator new to allocate memory" << std::endl;
		std::cout << "Malloc 2 more bytes" << std::endl;
		return mem;
	}
	else
		throw std::bad_alloc();
}

void operator delete(void *mem) noexcept {
	std::cout << "Use Personal operator delete to free memory" << std::endl;
	free(mem);
}

int main(void) {
	int *p = new int(42);
	std::cout << *p << std::endl;
	delete p;
	return 0;
}