#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult {
	friend 
	std::ostream& print(std::ostream&, QueryResult);
public:
	QueryResult(std::shared_ptr<std::vector<std::string>>,
				std::shared_ptr<std::map<std::string,std::set<std::size_t>>>,
				std::map<std::string,std::set<std::size_t>>::iterator);
private:
	std::shared_ptr<std::vector<std::string>> pFileData;
	std::shared_ptr<std::map<std::string, std::set<std::size_t>>> pWordMap;
public:
	std::map<std::string,std::set<std::size_t>>::iterator result;
};

#endif