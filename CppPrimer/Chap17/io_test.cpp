#include <iostream>
/**
std::string resp;
default_random_engine e;
bernoulli_distribution b;

do {
	bool frist = b(e);
	std::cout << (first ? "We go first" : "You get to go first") << std::endl;
	std::cout << (play(first) ? "Sorry, you lost" : " congrates, you won") << std::endl;
	std::cout << "play again? Enter 'yes' or 'no'" << std::endl;

} while (std::cin >> resp && resp[0] == 'y')
*/
int main(int argc, char *argv[]) {
	// 格式控制，未格式化的IO和随机访问

	std::cout << "default bool values: " << true << " " << false
			  << "\nalpha bool values: " << std::boolalpha
			  << true << " " << false << std::endl;

	bool bool_val = 0;
	std::cout << bool_val
			  << std::noboolalpha 
			  << std::endl;

	std::cout << std::showbase;

	std::cout << "default: " << 20 << " " << 1024 << std::endl;
	std::cout << "octal: " << std::oct << 20 <<" " << 1024 << std::endl;
	std::cout << "hex: " << std::hex << 20 << " " << 1024 << std::endl;
	std::cout << "decimal: " << std::dec << 20 << " " << 1024 << std::endl;

	return 0;
}


 