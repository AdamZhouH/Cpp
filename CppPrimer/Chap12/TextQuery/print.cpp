#include "tools.h"

std::ostream&
print(std::ostream &os, QueryResult rt) {
	if (rt.result == rt.pWordMap->cend())
		std::cout << "要查找的单词不存在" << std::endl;
	else {
		std::cout << rt.result->first << "出现了" 
				  << rt.result->second.size() << "次。"
				  << "分别在 :" << std::endl;
		for (auto i : rt.result->second)
			std::cout << "第" << i+1 << "行: " 
					  << (*rt.pFileData)[i] << std::endl;
	}
	return os;
}