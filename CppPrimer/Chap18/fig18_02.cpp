// fig18_03.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

void exercise(int *b, int *e) {
	vector<int> v(b, e);
	int *p = new int[v.size()];
	try {
		ifstream in("filename");
		// TODU
	} catch {
		delete p;
		// TODU
	}
}


// 定义一个示范性质的，非常简单的资源管理类，仅仅具有构造和析够函数
// 能够使用的类似资源管理类类似 智能指针，还需要考虑很多方面的内容
// 拷贝行为 移动行为 解引用行为 重载下标操作等
class Resource {
public:
	Resource(size_t size)
		: p(new int[size]) { }
	~Resource {
		if (r)
			delete p;
	}
private:
	int *p;
};

void exercise(int *b, int *e) {
	vector<int> v(b, e);
	Resource r(v.size());
	ifstream in("filename");
	// TODU 
	// 这样，即使发生异常，由于栈展开机制时，局部对象的析够函数被调用
	// Resource保存的数组内存也会被释放，保证不产生内存leaks
}
