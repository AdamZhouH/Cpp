#ifndef Quote_h
#define Quote_h

#include <string>
#include <iostream>

class Quote {
public:
	// 构造函数 析构函数
	Quote() = default;
	Quote(const std::string &book, double sales_price) : 
		bookNo(book), price(sales_price) { }
	//
	virtual Quote *clone() const & {
		return new Quote(*this);
	}
	virtual Quote *clone() && {
		return new Quote(std::move(*this));
	}
	virtual ~Quote() = default;
	// 返回书籍的isbn号
	std::string isbn() const { 
		return bookNo;
	}
	// 返回书籍的实际总额售价(用户购买的书的数量必须达到一定标准)
	virtual double net_price(std::size_t n) const { 
		return n * price; 
	}
	// Debug函数
	virtual void debug() {
		std::cout << "Quote verison debug" << std::endl;
	}
protected:
	double price = 0.0;   //  普通状态下不打折的价格
private:
	std::string bookNo;   // 书ISBN号
};

#endif