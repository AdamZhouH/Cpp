#include "StrBlobPtr.h"
#include "../StrBlob/StrBlob.h"
#include <stdexcept>

StrBlobPtr::StrBlobPtr() :
    curr(0) { }

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) :
    wptr(a.data), curr(sz) { }

std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string &s) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(s);
    return ret;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::decr() {
    curr--;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    auto pl = lhs.wptr.lock();
    auto pr = rhs.wptr.lock();
    if (pl == pr) {
        return ( !pr || lhs.curr == rhs.curr );
    } else {
        return false;
    }
}