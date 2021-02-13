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
using std::enable_shared_from_this;

// in this case, we will show the misusing of shared_ptr in the comment
// and why the enable_shared_from_this() exist


// class Person {
class Person : public enable_shared_from_this<Person> {
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

    void setParentsAndKids(shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr) {
        mother = m;
        father = f;
        if (mother != nullptr) {
            // mother->kids.push_back(shared_ptr<Person> (this));
            mother->kids.push_back(shared_from_this());
        }
        if (father != nullptr) {
            // father->kids.push_back(shared_ptr<Person> (this));
            father->kids.push_back(shared_from_this());
        }
    }
};