#include <iostream>
#include <string>
#include "Bulk_quote.h"

double printTotal(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n 
	   << " total due: " << ret << std::endl;
	return ret;
}

int main(int argc, char **argv) {
	// 构造函数测试
	Bulk_quote bulkBook("CppPrimer",38.5,20,8);
	std::cout << bulkBook.net_price(30) << std::endl;
	std::cout << bulkBook.net_price(15) << std::endl;
	Quote quote("CppPrimer",100);
	

#include <iostream>
#include <string>

int main(void) {
	std::cout << "Enter two numbers:" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << " and " << v2 << " is "lk_quote bulk("CppPrimer",100,10,8.5);
	// printTotal函数测试
	printTotal(std::cout,quote,15);
	printTotal(std::cout,bulk,15);
	// Debug函数测试
	Quote *ptq1 = new Quote("Redis设计与实现",25);
	Quote *ptq2 = new Bulk_quote("STL源码剖析",45,10,7.5);
	// 包括回避虚函数机制的测试
	ptq1->debug();
	ptq1->Quote::debug();
	ptq2->debug();
	ptq2->Quote::debug();
 	return 0;
}