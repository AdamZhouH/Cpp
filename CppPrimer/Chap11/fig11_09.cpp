// fig11_09.cpp

#include <map>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void readFile(const string &filename, map<string, list<size_t>> &words) {
	ifstream inputFile(filename);
	if (!inputFile) {
		cout << "打开文件失败" << endl;
		return;
	}
	size_t lineCount = 0;
	string lineContent;
	while (getline(inputFile, lineContent)) {
		lineCount++;
		if (!lineContent.empty()) {
			istringstream is(lineContent);
			string word;
			while (is >> word)
				words[word].push_back(lineCount);
		}
	}
} 

void showMap(const map<string, list<size_t>> &words) {
	for (auto const &p : words) {
		cout << p.first << " : ";
		for (auto i : p.second)
			cout << i << "  ";
		cout << endl;
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "输入参数有错，可能没有输入文件名" << endl;
		return -1;
	}
	map<string, list<size_t>> words;
	readFile(argv[1], words);
	showMap(words);
	return 0;
}