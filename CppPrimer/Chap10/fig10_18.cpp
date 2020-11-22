// fig10_17.cpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 求大于等于一个给定长度的单词的个数

void biggest(vector<string> &words, vector<string>::size_type sz) {
    // 单词去重复，并且按照字典顺序排序
    std::sort(words.begin(), words.end());
    vector<string>::iterator end_of_unique = std::unique(words.begin(), words.end());
    words.erase(end_of_unique, words.end());
    // 使用partition把单词按照长度分成前后两部分
    // lambda捕获局部变量sz
    vector<string>::iterator after_last_biggest = partition(words.begin(), words.end(), [sz](const string &s) {
        return s.size() >= sz;
    });
    for_each(words.begin(), after_last_biggest, [](const string &s) { std::cout << s << " "; });
}

void stable_biggest(vector<string> &words, vector<string>::size_type sz) {
    // 单词去重复，并且按照字典顺序排序
    std::sort(words.begin(), words.end());
    vector<string>::iterator end_of_unique = std::unique(words.begin(), words.end());
    words.erase(end_of_unique, words.end());
    // 使用stable_partition把单词按照长度分成前后两部分，并保证原有相对顺序
    // lambda捕获局部变量sz
    vector<string>::iterator after_last_biggest = std::stable_partition(words.begin(), words.end(), [sz](const string &s) {
        return s.size() >= sz;
    });
    for_each(words.begin(), after_last_biggest, [](const string &s) { std::cout << s << " "; });
}

int main(void) {
    std::vector<string> svec = {"fox", "jumps", "over", "quickly" , "the", "slow", "the", "turtle", "red"};
//  std::vector<string> svec = {"fox", "over", "the", "slow", "the", "red"};
//  stable_biggest(svec, 5);
    biggiest(svec, 5);
    return 0;
}