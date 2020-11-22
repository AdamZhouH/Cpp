#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
    // regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    // 下面的正则表示匹配的是要么以ei开头，要么ei的前面不出现c字符的单词
    regex r("(^|[^c]+)ei[[:alpha:]]*");
    string str;
    smatch results;
    while (cin >> str) {
        if (regex_search(str, results, r)) {
            cout << results.str() << endl;
        }
    }
    return 0;
    
