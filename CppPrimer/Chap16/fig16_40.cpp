template <typename It>
auto fcn3(It beg, It end) -> decltpye(*beg + 0) {
  return *beg;
}

// 返回值的类型并不确定
// 因此使用auto和尾置返回类型声明
// decltype是完全的类型推断,这点和auto不相同,因此,如果
// 直接使用decltype(*beg)返回的是引用类型
// 但是decltype(*beg + 0)中,*beg + 0 的到的是一个右值,因此推断出来类型就不是引用的类型了

// 限制条件,It迭代器解引用得到的元素支持和整数的加法运算
