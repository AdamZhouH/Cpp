#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

void ReadFromFile(const string &fileName, vector<PersonInfo> &persons) {
	ifstream fileInput(fileName);
	if (!fileInput) {
		cout << "Open " << fileName << " error!" << endl;
		return;
	}
	string line;
	while (getline(fileInput, line)) {
		istringstream contents(line);
		string var;
		PersonInfo person;
		contents >> var;
		person.name = var;
		while (contents >> var) {
			person.phones.push_back(var);
		}
		persons.push_back(person);
	}
}

void ShowPersons(const vector<PersonInfo> &persons) {
	for (auto &person : persons) {
		cout << "==========================" << endl;
		cout << "Name: " << person.name << endl;
		cout << "Phones: ";
		for (auto &phone : person.phones) {
			cout << phone << " ";
		}
		cout << endl;
	}
	cout << "==========================" << endl;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage: ./Main FileName" << endl;
		return 0;
	}
	vector<PersonInfo> persons;
	ReadFromFile(argv[1], persons);
	ShowPersons(persons);
	return 0;
}
