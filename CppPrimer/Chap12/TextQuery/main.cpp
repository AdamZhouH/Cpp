#include "tools.h"
#include <string>
#include <iostream>

void runQuery(const std::string &fileName) {
	TextQuery textQuery(fileName);
	std::string word;
	while (true) {
		std::cout << "请输入要查询的单词" << std::endl;
		if (!(std::cin >> word) || word == "q")
			break;
		print(std::cout,textQuery.query(word)) << std::endl;
	}
}

int main(int argc, char **argv) {
	runQuery(argv[1]);
	return 0;
}