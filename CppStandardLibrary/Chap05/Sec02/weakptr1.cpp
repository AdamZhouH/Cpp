#include <memory>
#include <string>
#include <vector>
#include <iostream>

using std::shared_ptr;
using std::string;
using std::vector;
using std::cout;
using std::endl;

// class Person should have the object semantic but no a value semantic
// so we use shared_ptr to hold an Person
class Person {
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<shared_ptr<Person>> kids;

    Person(const string &n,
           shared_ptr<Person> m = nullptr,
           shared_ptr<Person> f = nullptr)
        : name(n), mother(m), father(f) { }

    ~Person() {
        cout << "delete " << name << endl;
    }
};

// cyclic reference
shared_ptr<Person> initFamily(const string &name) {
    shared_ptr<Person> mom(new Person(name + "'s mom"));
    shared_ptr<Person> dad(new Person(name + "'s dad"));
    shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}

// as we can see, the nico's mom and nico's dad and nico himself
// will never be released
int main(int argc, char *argv[]) {
    shared_ptr<Person> p = initFamily("nico");
    
    cout << "nico's family exist" << endl;
    cout << "- nico is shared " << p.use_count() << " times" << endl;
    cout << "- name of lst kid of nico's mom: " << p->mother->kids[0]->name << endl;

    p = initFamily("jim");
    cout << "jim's family exists" << endl;
    return 0;
}