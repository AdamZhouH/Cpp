#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <new>
using namespace std;

vector<int>* factory() {
	return new vector<int>;
}

void fill(vector<int> *pv) {
	int tmp;
	while (cin >> tmp)
		pv->push_back(tmp);
}

void display(vector<int> *pv) {
	if (!pv) {
		cout << "空指针" << endl;
		return;
	}
	for (auto it = pv->cbegin(); it != pv->cend(); it++)
		cout << *it << '\t';
	cout << endl;
}

int main() {
	auto p = factory();
	fill(p);
	display(p);
	delete p;
	return 0;
}

