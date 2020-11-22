#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include "../StrBlobPtr/StrBlobPtr.h"

class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;

    void push_back(const std::string &s) { data->push_back(s); }
    void pop_back();

    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
private:
    std::shared_ptr<std::vector<std::string>> data;
    
    void check(size_type i, const std::string &s) const;
};

#endif