// fig15_28.cpp

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Quote/Quote.h"
#include "Quote/Bulk_quote.h"

int main(int argc, char **argv) {
	std::vector<Quote> vec;
	std::vector<std::shared_ptr<Quote>> pvec;

	Bulk_quote b1("Thinking in Java", 85.0, 25, 8.5);
	Bulk_quote b2("C++ Primer", 99, 30, 7.8);
	Bulk_quote b3("Morden Computer Operating System", 77, 40, 6.5);

	vec.push_back(b1); vec.push_back(b2); vec.push_back(b3);
	pvec.push_back(std::make_shared<Bulk_quote> (b1));
	pvec.push_back(std::make_shared<Bulk_quote> (b2));
	pvec.push_back(std::make_shared<Bulk_quote> (b3));

	std::cout << "Using vector<Quote> :" << " :" << std::endl;
	double sum = 0.0;
	int count = 30;
	for (auto it = vec.begin(); it != vec.end(); it++) {
		sum += (*it).net_price(count);
		std::cout << (*it).isbn() << "\t";
	}
	std::cout << std::endl << "Total price :  " << sum << std::endl;

	std::cout << "Using vector<shared_ptr<Quote>> :" << " :" << std::endl;
	sum = 0.0;
	for (auto it = pvec.begin(); it != pvec.end(); it++) {
		sum += (*it)->net_price(count);
		std::cout << (*it)->isbn() << "\t";
	}
	std::cout << std::endl << "Total price :  " << sum << std::endl;
}

