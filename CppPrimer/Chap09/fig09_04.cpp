// fig09_04.cpp

#include <vector>
#include <iostream>


typedef vector<int>::iterator Iterator;
bool findInVector(Iterator beg, Iterator end, int val);

bool findInVector(Iterator beg, Iterator end, int val) {
	while (beg != end) {
		if (*beg == val)
			return true;
		++beg;
	}
	return false;
}