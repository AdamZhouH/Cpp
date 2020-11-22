// fig11_33.cpp
// 单词转换程序

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <stdexcept>
using namespace std;

// 读取规则
void readMapRules(const string &ruleFile, map<string, string> &mapRules);
// 根据规则是否转换单词
const string transWord(const map<string, string> &mapRules, const string &word);
// 文本转换程序
void transText(const string &ruleFile, const string &ObjFile);

void readMapRules(const string &ruleFile, map<string, string> &mapRules) {
	ifstream is(ruleFile);
	if (!is) {
		cout << "Open file failed" << endl;
		return;
	}
	string key, value;
	while (is >> key && getline(is, value)) {
		if (value.size() > 1)
			mapRules[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
}

const string transWord(const map<string, string> &mapRules, const string &word) {
	if (mapRules.find(word) != mapRules.end())
		// 不能使用mapRules[word]，因为有改变mapRules的可能性，而传入的参数是const的，因此编译器报错
		return mapRules.find(word)->second;
	else 
		return word;
}

void transText(const string &ruleFile, const string &ObjFile) {
	map<string, string> mapRules;
	readMapRules(ruleFile, mapRules);
	ifstream input(ObjFile);
	if (!input) {
		cout << "open file filed" << endl;
		return;
	}
	string line;
	string word;
	bool firstWord = true;
	while (getline(input, line)) {
		istringstream iss(line);
		while (iss >> word) {
			if (!firstWord) 
				cout << ' ';
			else
				firstWord = false;
			cout << transWord(mapRules, word);
		}
		cout << endl;
		firstWord = true;
	}
}

int main(int argc, char **argv) {
	transText(argv[1], argv[2]);
	return 0;
}

/**
简单来说，map的[]运算符会在索引项不存在的时候自动创建一个对象，有可能会改变map本身，所以不能够用在一个const map上。
解决办法有两个：
                  方法1、不要将形参声明为const
                  方法2、用find代替[]

        不过第二中方法存在风险，因为end()->second是合法的，于是就会产生传说中的null引用。
*/