#include <map>
#include <vector>
#include <iostream>

using namespace std;

void showFamily(const map<string, vector<string>> &family) {
	for (const auto &p : family) {
		cout << "家庭名称:" << p.first << endl;
		cout << "家庭成员名称:";
		for (const auto &name : p.second)
			cout << name << '\t';
		cout << endl;
	}
}

int main(void) {
	map<string, vector<string>> family;
	string familyName;
	string childName;
	cout << "请输入家庭名称" << endl;
	while (cin >> familyName) {
		cout << "请输入要添加的孩子的名字" << endl;
		while (cin >> childName) 
			family[familyName].push_back(childName);
		cin.clear();
		cout << "请输入下一个家庭名称" << endl;
	}
	showFamily(family);
	return 0;
}