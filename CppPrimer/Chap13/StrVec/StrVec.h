#ifndef STRVEC_H_
#define STRVEC_H_

#include <string>
#include <stdexcept>
#include <memory>
#include <utility>
#include <initializer_list>

namespace zq {

class StrVec {
public:
	// Constructor and Destructor and some other copy control memeber
	// Including Move Constructor
	StrVec() :
		elements(nullptr), first_free(nullptr), elements(nullptr) { }
	StrVec(std::initializer_list<const char *>);
	StrVec(const std::string *, const std::string *);
	StrVec(const StrVec &);
	StrVec(StrVec &&) noexcept;
	~StrVec();
	
	// About size and Capacity
	std::size_t size() const;
	std::size_t capacity() const;

	// Get Iterator of begin and end
	std::string *begin() const;
	std::string *end() const;

	// Push and Pop
	void push_back(const std::string &);
	void pop_back(const std::string &);

	// Operator overload (including Move Assignment)
	StrVec& operator=(const StrVec &);
	StrVec& operator=(StrVec &&) noexcept;
	std::string &operator[](std::size_t n);
private:
	// Private Operation helper

	// Make sure the strvec have space to hold string object
	void chk_n_alloc();
	// Allocate memory and Copy some elmennts from a range
	std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
	// To free the memory
	void free();
	// When the previous memory is used, malloc more memory 
	// And copy the previous Elements in new memory
	void reallocate();

	// Data
	static std::allocator<std::string> alloc;
	std::string *elements;              // Point to first element
	std::string *first_free;            // Point to first spare space
	std::string *cap;                   // Point to last memory position
};

} // namespace zq

#endif