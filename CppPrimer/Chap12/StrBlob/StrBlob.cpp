#include "StrBlob.h"
#include <stdexcept>

StrBlob::StrBlob() :
    data(std::make_shared<std::vector<std::string>> ()) { }

StrBlob::StrBlob(std::initializer_list<std::string> il) :
    data(std::make_shared<std::vector<std::string>> (il)) { }

void StrBlob::check(size_type i, const std::string &s) const {
    if (i >= size())
        throw std::out_of_range(s);
}

void StrBlob::pop_back() {
    check(0, "pop back on an empty StrBlob");
    data->pop_back();
}

std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::front() const {
    return
        static_cast<const std::string&>
            ((const_cast<StrBlob&>(*this)).front());
}

const std::string& StrBlob::back() const {
    return
        static_cast<const std::string&>  
            ((const_cast<StrBlob&>(*this)).back());
}