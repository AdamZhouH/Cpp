// fig10_01.cpp

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	vector<int> ivec;
	int temp;
	while (cin >> temp) 
		ivec.push_back(temp);
	cin.clear();
	cout << "请输入要查找的元素" << endl;
	int val;
	while (cin >> val) {
		auto counts = count(ivec.cbegin(), ivec.cend(), val);
		cout << val << " occurs " << counts
								  << (counts > 1 ? " times" : " time") << endl;
	}
	return 0;
}