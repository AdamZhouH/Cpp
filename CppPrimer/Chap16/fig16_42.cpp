
template <typename T> void f(T &&); // 绑定到非const右值
template <typename T> void f(const T &); // 左值和const右值

template <typename T> void g(T &&val);
int i = 0;
const int ci = i;

// 1.g(i);
// T: int &  |  val: int &   (发生了引用折叠 X & && -> X &)

// 2.g(ci)
// T: const int & | val: const int & (同样的引用折叠)

// 3.g(i *ci)
// T: int   | val: int && (未发生引用折叠)
