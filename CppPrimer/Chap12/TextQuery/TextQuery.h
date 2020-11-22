#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <set>

// 前置声明
class QueryResult;

class TextQuery {
public:
	// 对外接口仅仅是一个TextQuery的构造函数和查询函数
	// 构造函数接受文件名，并由此对文件进行遍历，产生查找的map
	// QueryResult函数对外提供单词查找功能
	TextQuery(const std::string&);
	QueryResult query(const std::string&);
private:
	void readFile(const std::string&);
	void generateMap(std::size_t,const std::string&);
	std::shared_ptr<std::vector<std::string>> pFileData;
	std::shared_ptr<std::map<std::string, std::set<std::size_t>>> pWordMap;
};

#endif

int main(void)