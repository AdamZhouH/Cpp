/*7
int i = -1, &r = 0
非法，非常量引用的初始值必须是一个对象

int *const p2 = &i2
合法

const int i = -1, &r = 0;
合法，const对象的初始化，可以绑定到一个编译时常量上
const引用也是一样

const int *const p3 = &i2;
合法

const int *p1 = &i2;
合法

const int &const r2;
非法，引用必须初始化

const int i2 = i, &r = i;
合法
*/
