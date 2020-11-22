#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <new>
using namespace std;

shared_ptr<vector<int>> factory() {
	return make_shared<vector<int>>();
}
void fill(shared_ptr<vector<int>> sp) {
	int tmp;
	while (cin >> tmp) 
		sp->push_back(tmp);
}

void display(shared_ptr<vector<int>> sp) {
	if (!sp) {
		cout << "没有指向任何vector" << endl;
		return;
	}
	for (auto it = sp->cbegin(); it != sp->cend(); it++)
		cout << *it << '\t';
	cout << endl;
}

int main() {
	auto p = factory();
	fill(p);
	display(p);
	return 0;
}