// fig10_03.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(void) {
	vector<int> ivec = {1,2,3,4,5,6,7};
	vector<double> dvec = {1.3, 2.5, 3.2, 4.8};
	int isum = 0;
	int dsum = 0;
	isum = accumulate(ivec.cbegin(), ivec.cend(), isum);
	dsum = accumulate(dvec.cbegin(), dvec.cend(), dsum);
	cout << "vector<int> Sum is " << isum << endl;
	// double 会先转换为 int 类型，再和 dsum 相加，而不是把 dsum 转化为 double 类型
	cout << "vector<double >Sum is " << dsum << endl;
	return 0;
} 