#include "QueryResult.h"

QueryResult::QueryResult(
		std::shared_ptr<std::vector<std::string>> p1,
		std::shared_ptr<std::map<std::string,std::set<std::size_t>>> p2,
		std::map<std::string,std::set<std::size_t>>::iterator it
	) :
	pFileData(p1),
	pWordMap(p2),
	result(it) { }