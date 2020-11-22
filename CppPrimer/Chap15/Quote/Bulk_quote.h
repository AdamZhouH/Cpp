#ifndef Bulk_quote_h
#define Bulk_quote_h

#include <iostream>
#include <string>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
	//  构造函数
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	// 
	Bulk_quote *clone() const & {
		return new Bulk_quote(*this);
	}
	Bulk_quote *clone() && {
		return new Bulk_quote(*this);
	}
	// 返回实际实际总售价（根据买书的数量打一定的折扣）
	double net_price(std::size_t) const override;
	// Debug函数
	void debug() override;
};

Bulk_quote::Bulk_quote(const std::string &book, double sales_price, std::size_t qty, double disc) :
	Disc_quote(book, sales_price, qty, disc) { } 

double Bulk_quote::net_price(std::size_t n) const {
	if (n >= quantity) {
		// std::cout << "Discounted." << std::endl;
		return n * discount * price / 10.0;
	}
	else {
		// std::cout << "Sorry, No Discount." << std::endl;
		return n * price;
	}
}

void Bulk_quote::debug() {
	std::cout << "Bulk_quote version debug" << std::endl;
}

#endif
