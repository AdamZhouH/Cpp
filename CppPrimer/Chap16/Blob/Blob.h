#ifndef BLOB_H
#define BLOB_H

// 本质上是在设计一种共享底层数据的容器类
// 不过内存管理暂且丢给了智能指针，而没有手动管理
// 即 设计其拷贝构造 拷贝赋值 移动构造 移动赋值 析构函数
// 由于使用了智能指针，因此默认的上述操作一般不会引发内存问题
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>

/**
 * 对于模板类中，两个模板类的成员函数相互引用的矛盾
 * 暂时想到的方法是把Blob类中生成迭代器的具体实现，放在BlobPtr也就是迭代器头文件中
 * 防止由于头文件相互包含带来的各种问题
 * 如果有更好的做法，之后更新注释
 */

// 前置声明

template <typename T>
class BlobPtr;

template <typename T>
class Blob;

template <typename T>
bool operator ==(const Blob<T> &, const Blob<T> &);

template <typename T>
bool operator !=(const Blob<T> &, const Blob<T> &);

// 类模板定义
template <typename T>
class Blob {
	// 友元类和友元函数
	friend class BlobPtr<T>;
	friend bool operator ==<T>
						   (const Blob<T>&, const Blob<T>&);
	friend bool operator !=<T>
						   (const Blob<T>&, const Blob<T>&);
public:
    // 类型别名
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
    // 构造函数
	Blob();
	Blob(std::initializer_list<T> il);
	// 空容器判断
	size_type size() const;
	bool empty() const;
    // 元素添加和删除
	void push_back(const T &t);
	void push_back(T &&t);
	void pop_back();
    // 元素访问
	T &front();
	const T &front() const;
	T &back();
	const T &Blob<T>::back() const;
	const T& Blob<T>::operator [](size_type i) const;
	T& operator [](size_type i);
	// 迭代器获取
	BlobPtr<T> begin();
	BlobPtr<T> end();

private:
	// 底层利用shared_ptr管理vector
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

// 空容器判断
template <typename T>
size_type Blob<T>::size() const {
	return data->size();
}

template <typename T>
bool Blob<T>::empty() const {
	return data->empty();
}

// check函数
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

// 元素访问函数

template <typename T>
T &Blob<T>::front() {
	return const_cast<T &> (
		static_cast<const Blob<T> *>(this)->front();
	);
}

template <typename T>
const T &Blob<T>::front() const {
	check(0, "front on empty Blob");
	return data->front();
}

// 非const版本，基于const版本实现
template <typename T>
T & Blob<T>::back() {
	return const_cast<T &> (
		static_cast<const Blob<T> *>(this)->back();
	);
}

// 针对const版本的back函数
template <typename T>
const T &Blob<T>::back() const {
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
const T &Blob<T>::operator [](size_type i) const {
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
T& Blob<T>::operator [](size_type i) {
	return const_cast<T &> (
		static_cast<const Blob<T> *>(this)->operator [](i);
	);
}

// 元素添加和删除函数
template <typename T>
void Blob<T>::push_back(const T &) {
	data->push_back(t);
}

template <typename T>
void Blob<T>::push_back(T &&t) {
	data->push_back(std::move(t));
}

template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop on empty Blob");
	data->pop_back();
}

// 构造函数
template <typename T>
Blob<T>::Blob() :
	data(std::make_shared<std::vector<T>> ()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T>> (il)) { }

// 比较函数
template <typename T>
bool operator ==(const Blob<T> &lhs, const Blob<T> &rhs) {
	return
		lhs.data == rhs.data;
}

template <typename T>
bool operator !=(const Blob<T> &lhs, const Blob<T> &rhs) {
	return
		!(operator !=(lhs, rhs));
}

// 迭代器获取函数
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


// 鉴于模板的特殊性，模板成员你的声明和定义都必须在一个头文件中
// 因此对于这种 Blob和BlobPtr的特殊情况（BlobPtr其实是作为Blob的迭代器的），如果分别在
// 两个模板头文件中，需要相互包含引用，从而导致最终编译失败
// 实际上个人认为应当放在同一个模板头文件内，这个问题可以解决
#endif   // BLOB_H
