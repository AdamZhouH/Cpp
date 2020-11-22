// fig18_28.cpp

struct Base {
	void bar(int);
protected:
	int ival;
};

struct Derived1 : public virtual Base {
	void bar(char);
	void foo(char);
protected:
	char cval;
};

struct Derived2 : public virtual Base {
	void foo(int);
protected:
	int ival;
	char cval;
};

class VMI : public Derived1, public Derived2 { };

// 需要限定符的： Base::ival  Base::bar(int)  
// 			    Base::ival  Derived1::cval  Derived2::cval
//				Derived1::foo(char)  Derived2::foo(int)
// 不需要限定符的：bar(char) ival 

