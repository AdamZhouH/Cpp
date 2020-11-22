#include <string>
#include <forward_list>
#include <iostream>
#include <algorithm>
using namespace std;

void func(forward_list<string> &lst, const string &s1, const string &s2) {
	auto it = find(lst.begin(), lst.end(), s1);
	if (it != lst.end()) {
		lst.insert_after(it, s2);
	} else {
		// 插入链表末尾
		auto prev = lst.before_begin();
		auto curr = lst.begin();
		while (curr != lst.end()) {
			prev = curr;
			curr++;
		}
		lst.insert_after(prev, s2);
	}
}

int main(int argc, char *argv[]) {
	forward_list<string> lst = {"Hello", "World"};
	for_each(lst.begin(), lst.end(), [](const string &s) { cout << s << ' '; });
	cout << endl;
	func(lst, "HaHa", "ZackQ");
	for_each(lst.begin(), lst.end(), [](const string &s) { cout << s << ' '; });
	return 0;
}
