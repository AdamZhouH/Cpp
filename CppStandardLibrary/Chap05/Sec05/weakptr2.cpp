#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <exception>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::exception;
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Person {
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<weak_ptr<Person>> kids;

    Person(const string &n,
           shared_ptr<Person> m = nullptr,
           shared_ptr<Person> f = nullptr)
        : name(n), mother(m), father(f) { }

    ~Person() {
        cout << "delete " << name << endl;
    }
};

// cyclic reference will be break because we have use the weak_ptr
shared_ptr<Person> initFamily(const string &name) {
    shared_ptr<Person> mom(new Person(name + "'s mom"));
    shared_ptr<Person> dad(new Person(name + "'s dad"));
    shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}

// use_count now is normal and it make sure the release of 
// the whole nico family
int main(int argc, char *argv[]) {
    shared_ptr<Person> p = initFamily("nico");
    
    cout << "nico's family exist" << endl;
    cout << "- nico is shared " << p.use_count() << " times" << endl;
    shared_ptr<Person> firstKidOfMom;
    // if (firstKidOfMom = p->mother->kids[0].lock()) {
    //     cout << "- nico's mom' first kids " << firstKidOfMom->name << endl;
    // }
    if ((firstKidOfMom = p->mother->kids[0].lock())) {
        cout << "- nico's mom' first kids " << firstKidOfMom->name << endl;
    }

    p = initFamily("jim");
    cout << "jim's family exists" << endl;
    return 0;
}