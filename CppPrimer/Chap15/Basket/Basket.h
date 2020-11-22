#ifndef Basket_h
#define Basket_h

#include <iostream>
#include <string>
#include <memory>
#include <multiset>
#include "../Quote/Quote.h"
#include "../Quote/Bulk_quote.h"

class Basket;
double print_total(std::ostream &os, const Quote &item, size_t n) {
	double price = item.net_price(n);
	os << "ISBN:" << item.isbn()
	   << "# sold:" << n 
	   << "total due:" << price << std::endl;
	return price;
}

class Basket {
public:
	/*
	void add_item(const std::shared_ptr<Quote> &sale) {
		items.insert(sale);
	}
	*/
	void add_item(const Quote &);
	void add_item(Quote &&);
	double total_receipt(std::ostream &) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
					    const std::shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double 
Basket::total_receipt(std::ostream &os) const {
	double sum = 0.0;
	for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}

void
Basket::add_item(const Quote &sale) {
	items.insert(std::shared_ptr<Quote> (sale.clone()));
}

void 
Basket::add_item(Quote &&sale) {
	item.insert(
			std::shared_ptr<Quote> (std::move(sale).clone())
		);
}

#endif