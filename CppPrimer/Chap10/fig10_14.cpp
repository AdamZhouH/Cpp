// fig10_14.cpp
#include <iostream>
#include <vector>

int main(void) {
    auto f = [](int a, int b) ->int {
        return a + b;
    };
    int a, b;
    while (std::cin >> a >> b)
        std::cout << f(a, b) << std::endl;
    return 0;
}