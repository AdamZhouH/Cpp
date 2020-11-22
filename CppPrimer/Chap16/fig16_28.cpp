#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// shared_ptr
template <typename T>
class Shared_ptr {
public:
    // Construct and Destruct
    Shared_ptr() :
        use_cnt(nullptr),
        data(nullptr) { }

    explicit Shared_ptr(T *t) :
        use_cnt(new int(1)),
        data(t) { }

    // 注意obj可能为空或非空的情况
    Shared_ptr(const Shared_ptr &obj) :
        use_cnt(obj.use_cnt),
        data(obj.data) {
        // 如果obj不是一个空Shared_ptr，则引用计数+1
        if (use_cnt)
            ++*use_cnt;
    }
    // 提供到bool类型的类型转换
    operator bool() const {
        return data != nullptr;
    }

    ~Shared_ptr();
    // 注意拷贝一个空Shared_ptr的情况
    Shared_ptr &operator =(const Shared_ptr &rhs);
    T &operator *();
    T &operator *() const;
private:
    int *use_cnt;
    T *data;
};

template <typename T>
Shared_ptr<T>::~Shared_ptr() {
    if (use_cnt) {
        assert(data != nullptr);
        assert(*use_cnt != 0);
    }
    if (use_cnt && --*use_cnt == 0) {
        delete data;
        delete use_cnt;
        cout << "Shared_ptr destruct object" << endl;
    }
}

template <typename T>
Shared_ptr<T> &Shared_ptr<T>::operator =(const Shared_ptr &rhs) {
    if (rhs.use_cnt) {
        ++*rhs.use_cnt;
    }
    if (use_cnt && --*use_cnt == 0) {
        delete use_cnt;
        delete data;
    }
    use_cnt = rhs.use_cnt;
    data = rhs.data;
    return *this;
}

template <typename T>
T &Shared_ptr<T>::operator * () const {
    return *data;
}

template <typename T>
T &Shared_ptr<T>::operator *() {
    return *data;
}

// Unique_ptr 
template <typename T>
class Unique_ptr {
public:
    Unique_ptr() : data(nullptr) { }
    Unique_ptr(T *t) : data(t) { }
    Unique_ptr(const Unique_ptr &obj) = delete;
    ~Unique_ptr() {
        if (data) {
            delete data;
            cout << "Unique_ptr destruct object" << endl;
        }
    }
    operator bool() const {
        return data != nullptr;
    }

    Unique_ptr &operator =(const Unique_ptr &rhs) = delete;

    T &operator *();
    T &operator *() const;
    T *release();
    void reset(T *t);
private:
    T *data;
};

template <typename T>
T *Unique_ptr<T>::release() {
    T *ret = data;
    data = nullptr;
    return ret;
}

template <typename T>
T &Unique_ptr<T>::operator *() { return *data; }

template <typename T>
T &Unique_ptr<T>::operator *() const { return *data; }

template <typename T>
void Unique_ptr<T>::reset(T *t) {
    if (data) {
        delete data;
        cout << "Unique_ptr destruct Object in reset Method" << endl;
    }
    data = t;
}

int main(int argc, char *argv[]) {
    Shared_ptr<int> ptr(new int(99));
    Shared_ptr<int> another = ptr;
    if (ptr) {
        cout << "Shared_ptr<string> sptr is not null" << endl;
    } else {
        cout << "Shared_ptr<string> sptr is null" << endl;
    }
    cout << *ptr << endl;
    cout << *another << endl;
    Unique_ptr<string> uptr(new string("Hello World"));
    cout << *uptr << endl;
    uptr.reset(new string("Replace"));
    cout << *uptr << endl;
    // Unique_ptr<string> anotherUptr(uptr);
    Unique_ptr<string> anotherUptr;
    // anotherUptr = uptr;
    return 0;
}