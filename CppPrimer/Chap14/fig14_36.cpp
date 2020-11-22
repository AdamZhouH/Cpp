// fig14_36.cpp

#include <iostream>
#include <string>
#include <vector>

class ReadLine {
public:
    ReadLine(std::istream &i = std::cin) :
        is(i) { }
    const std::string operator() () const {
        std::string content;
        if (getline(is, content))
            return content;
//      else
//          is.clear();
        return std::string();
    }
private:
    std::istream &is;
};

int main(void) {
    std::vector<std::string> svec;
    ReadLine readLine;
    while (std::cin) {
        svec.push_back(readLine());
    }
    for (auto &s : svec) 
        std::cout << s << std::endl;
    return 0;
}