#include <regex>
#include <string>
#include <iostream>
using namespace std;

void foo() {
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    string test_str = "receipt freind theif receive";
    if (regex_search(test_str, results, r))
        cout << results.str() << endl;
}

void bar() {
    regex r("[[:alpha:]]+\\.(cpp|cc|cxx)$", regex::icase);
    smatch results;
    string str;
    while (cin >> str) {
        if (regex_search(str, results, r))
            cout << results.str() << endl;
    }
}

int main(int argc, char *argv[]) {
    // foo();
    bar();
    return 0;
}
