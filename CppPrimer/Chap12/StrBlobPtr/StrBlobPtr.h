#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <string>
#include <vector>
#include <memory>
#include <new>

// 前置声明
class StrBlob;

class StrBlobPtr {
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob&, size_t = 0);

    std::string& deref() const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();
private:
    std::shared_ptr<std::vector<std::string>> 
    check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

bool eq(const StrBlobPtr&, const StrBlobPtr&);
#endif