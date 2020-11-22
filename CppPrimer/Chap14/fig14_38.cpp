// fig14_38.cpp

// 编写一个类检查某个给定的string的长度是否和一个阀值相等
// 并使用此对象编写程序，统计输入的文件中的长度为1的单词的个数，长度为2的单词的个数...
// 直到统计完所有的单词的个数

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

// 可调用对象

class JudgeLength {
    public:
//      JudgeLength(std::size_t s) :
//          size(s) { }
        std::size_t operator() (const std::string &s) {
            return s.size();
        }
//  private:
//      std::size_t size;
};

void lengthCount(const std::string &filePath) {
    std::map<std::size_t, std::size_t> wordCountMap;
    std::ifstream input(filePath);
    if (!input) {
        throw std::runtime_error("Open filed filed.");
    }
    std::string lineContent;
    while (getline(input, lineContent)) {
        std::istringstream wordsOfLine(lineContent);
        if (!lineContent.size())
            continue;
        std::string word;
        JudgeLength judge;
        while (wordsOfLine >> word)
            wordCountMap[judge(word)]++;  
    }
    // show count result
    for (auto it = wordCountMap.begin(); it != wordCountMap.end(); it++)
        std::cout << "length " << it->first << " appears " << it->second << " times" << std::endl;
}

int main(int argc, char **argv) {
    lengthCount(argv[1]);
    return 0;
}