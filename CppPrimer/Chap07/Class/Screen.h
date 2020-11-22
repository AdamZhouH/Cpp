#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen {
//  只让WindowMgr的clear方法成为Screen类的友元而不让整个WindowMgr成为友元
//  friend void WindowMgr::clear(ScreenIndex);
//  则需要将Screen和WindowMgr声明在同一个头文件中，才能保证依赖关系得到满足（分别声明的话比较麻烦，而且容易导致循环include）
//  要考虑到Incomplete Type的使用范围是非常有限的：
//      1.声明以不完全类型为参数或者返回值的函数（仅仅函数声明，不涉及函数定义）
//      2.定义不完全类型的指针或者引用类型
//      因为这两种情况下，不需要直到类型的成员变量和成员函数
    friend class WindowMgr;
public:
	typedef std::string::size_type Pos;
public:
	Screen() = default;
	Screen(Pos ht, Pos wd);
	Screen(Pos ht, Pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
	
	Screen &set(char c);
	Screen &set(Pos ht, Pos wd, char c);

	char get() const {
		return contents[cursor];
	}
	inline char get(Pos ht, Pos wd) const;

	Screen &move(Pos ht, Pos wd);
	void some_member() const;

	Screen &display(std::ostream &);
	const Screen &display(std::ostream &) const;
private:
    void do_display(std::ostream &) const;
private:
	Pos cursor = 0;
	Pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr = 0;
};

inline
void Screen::do_display(std::ostream &os) const {
    os << contents;
}

// 内联函数如果定义在类声明之外，也必须和类的声明在同一个头文件中
inline
Screen &Screen::move(Pos ht, Pos wd) {
	std::cout << "Calling move Method" << std::endl;
	cursor = ht * width + wd;
	return *this;
}

char Screen::get(Pos ht, Pos wd) const {
	return contents[ht * width + wd];
}


#endif // SCREEN_H
