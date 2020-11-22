/*
 int i, *const cp;
 整型变量i，常量指针cp，但是cp必须被初始化

 int *p1, *const p2;
 同样的问题，p2必须被初始化

 const int ic, &r = ic;
 整型常量ic，必须被初始化但是没有

 const int *const p3;
 指向整型常量的常量指针，由于是const对象，应该被初始化，但是没有

 const int *p;
 合法
  */
