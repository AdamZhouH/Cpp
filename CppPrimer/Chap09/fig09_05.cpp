// fig09_05.cpp

#include <vector>
#include <iostream>


typedef vector<int>::iterator Iterator;
Iterator findInVector(Iterator beg, Iterator end, int val);

Iterator findInVector(Iterator beg, Iterator end, int val) {
	while (beg != end) {
		if (*beg == val)
			return beg;
		++beg;
	}
	return end;
}