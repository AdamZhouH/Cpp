// fig16_07.cpp

#include <iostream>
#include <string>
#include <vector>

template <typename T, unsigned N>
constexpr
size_t sizeArray(const T (&arr)[N]) {
    return N;
}

int main(int argc, char **argv) {
    int arr1[] = {1,2,3,4,5,6,7};
    std::vector<int> arr2[] = {{1,2,3}, {4,5,6}};
    std::cout << "arr1 size is :" << sizeArray(arr1) << std::endl;
    std::cout << "arr2 size is :" << sizeArray(arr2) << std::endl;
}
