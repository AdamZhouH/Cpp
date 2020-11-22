// fig15_03.cpp
// Quote类 printTotal 函数的定义

#include <iostream>
#include <string>
#include <vector>

// Quote
class Quote {
public:
	// 构造函数 析构函数
	Quote() = default;
	Quote(const std::string &book, double sales_price) : 
		bookNo(book), price(sales_price) { }
	virtual ~Quote() = default;
	// 返回书籍的isbn号
	std::string isbn() const { return bookNo; }
	// 返回书籍的实际销售价格(用户购买的书的数量必须达到一定标准)
	virtual double net_price(std::size_t n) const { return n * price; }
protected:
	double price = 0.0;   //  普通状态下不打折的价格
private:
	std::string bookNo;   // 书ISBN号
};

// printTotal
double printTotal(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n 
	   << " total due: " << ret << std::endl;
	return ret;
}