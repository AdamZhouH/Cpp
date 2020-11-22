#ifndef Disc_quote_h
#define Disc_quote_h

#include <string>
#include <iostream>
#include "Quote.h"

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double sales_price,
			   std::size_t qty, double disc) :
		Quote(book, sales_price), quantity(qty), discount(disc) { }
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

#endif