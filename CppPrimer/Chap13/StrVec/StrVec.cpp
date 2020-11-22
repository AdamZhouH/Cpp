
#include <iostream>
#include <string>
#include "StrVec.h"

namespace za {

std::allocator<std::string> 
StrVec::alloc;

// Move Constructor
StrVec::StrVec(StrVec &&o) noexcept 
	: elements(o.elements),
	  first_free(o.first_free),
	  cap(o.cap) {
	s.elements = nullptr;
	s.first_free = nullptr;
	s.cap = nullptr;
}

// Move Assignment
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
	// Self assignment need to be considered
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		// Make the rhs destructable
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

} // namespace zq
