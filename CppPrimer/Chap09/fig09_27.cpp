#include <forward_list>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	forward_list<int> flst = {1,2,3,4,5,6,7,8,9,10};
	for_each(flst.begin(), flst.end(), [](int var){ cout << var << ' '; });
	cout << endl;
	auto it = flst.begin();
	auto before = flst.before_begin();
	while (it != flst.end()) {
		if (*it % 2) {
			it = flst.erase_after(before);
		} else {
			it++;
			before++;
		}
	}
	for_each(flst.begin(), flst.end(), [](int var){ cout << var << ' '; });
	return 0;
}
