#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
#include <string>
#include <fstream>
#include <stdexcept>

TextQuery::TextQuery(const std::string &fileName) :
	pFileData(std::make_shared<std::vector<std::string>> ()),
	pWordMap(std::make_shared<std::map<std::string,std::set<std::size_t>>> ()) {
		readFile(fileName);
	}

void
TextQuery::readFile(const std::string &fileName) {
	std::ifstream input(fileName);
	if (!input) {
		throw std::runtime_error("打开文件失败");
		return;
	}
	// 读取文件内容，每一行存入vector中的string
	// 并且构造
	std::size_t lineNum = 0;
	std::string line;
	while (getline(input,line)) {
		pFileData->push_back(line);
		generateMap(lineNum++,line);
	}
}

void 
TextQuery::generateMap(std::size_t lineNum,const std::string &lineContent) {
	if (!lineContent.empty()) {
		std::istringstream content(lineContent);
		std::string word;
		while (content >> word)
			(*pWordMap)[word].insert(lineNum);
	}
}

QueryResult 
TextQuery::query(const std::string &word) {
	auto result = pWordMap->find(word);
	return QueryResult(pFileData,pWordMap,result);
} 