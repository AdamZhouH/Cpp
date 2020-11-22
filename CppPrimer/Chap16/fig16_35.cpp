
template <typename T>
T calc(T, int);

template <typename T>
T fcn(T, T);

double d;
float f;
char c;

calc(c, 'c');  // 合法，推断的模板类型为char，而非模板参数则按照正常的转换规则，转换为 int

cal(d, f); // 同上，推断出的类型为double，非模板参数正常转换

fcn(c, 'c'); // 合法，两个推断出的类型一个是 char, 另一个也是char，可以调用

fcn(d, f); // 非法，两者推断出的类型一个是double，一个是float，不相同
