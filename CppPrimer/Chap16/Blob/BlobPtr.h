#ifndef BLOBPTR_H
#define BLOBPTR_H
// 其实，本质上 BlobPtr 可以视为是 Blob 的迭代器类型
// 利用 BlobPtr 来遍历 Blob 中的元素
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include "Blob.h"

// 迭代器比较操作
template <typename T>
bool operator ==(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
bool operator !=(const BlobPtr<T> &, const BlobPtr<T> &);


// 类模板定义
template <typename T>
class BlobPtr {
	friend bool operator ==<T>
						   (const BlobPtr<T> &, const BlobPtr<T> &);
	friend bool operator !=<T>
							 (const BlobPtr<T> &, const BlobPtr<T> &);
public:
	// 构造函数
	BlobPtr() :
		curr(0) { }
	BlobPtr(Blob<T> &a, size_t sz = 0) :
		curr(sz), wptr(a.data) { }    // 利用weak_ptr引用底层数据，不增加引用计数
	// operator *重载，使其模拟指针的行为
	T& operator *() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	BlobPtr& operator ++();
	BlobPtr &operator ++(int); // 后置递增运算符
	BlobPtr& operator --();
	BlobPtr &operator --(int); // 后置递减运算符

private:
	std::shared_ptr<std::vector<T>>
	check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<T>> wptr;   // 使用weak_ptr不增加引用计数
	std::size_t curr;
};



template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
	auto p = wptr.lock();
	if (!p)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= p->size())
		throw std::out_of_range(msg);
	return p;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator ++() {
	check(++curr, "pass the end");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator ++(int) {
	auto tmp = *this;
	this->operator ++();
	return tmp;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator --() {
  check(--curr, "before the head");
	return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator --(int) {
	auto tmp = *this;
	this->operator --();
	return tmp;
}

template <typename T>
bool operator ==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return
		lhs.wptr.lock() == rhs.wptr.lock() &&
		lhs.curr == rhs.curr;
}

template <typename T>
bool operator !=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return
		!(operator ==(lhs, rhs));
}

/*
template <typename T>
BlobPtr<T>
Blob<T>::begin() {
	return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T>
Blob<T>::end() {
	return BlobPtr<T>(*this, data->size());
}
*/
#endif
