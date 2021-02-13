#include <memory>
#include <unistd.h>
#include <sys/mman.h>
#include <cstring>
#include <cerrno>
#include <string>
#include <iostream>
using namespace std;

// define a shared memory deleter
class SharedMemoryDetacher {
public:
    void operator ()(int *p) {
        cout << "unlink /tmp1234" << endl;
        if (shm_unlink("/tmp1234") != 0) {
            cerr << "OOPS: shm_unlink() failed" << endl;
        }
    }
};

shared_ptr<int> getSharedMemoryIntMemory(int num) {
    void *mem;
    int shmfd = shm_open("/tmp1234", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
    if (shmfd < 0) {
        throw string(strerror(errno));
    }
    if (ftruncate(shmfd, num * sizeof(int)) == -1) {
        throw string(strerror(errno));
    }
    mem = mmap(nullptr, num * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (mem == MAP_FAILED) {
        throw string(strerror(errno));
    }
    return shared_ptr(static_cast<int *>(mem), SharedMemoryDetacher());
}

int main(int argc, char *argv[]) {
    shared_ptr<int> smp(getSharedIntMemory(100));

    for (int i = 0; i < 100; i++) {
        smp.get()[i] = i * 42; 
    }
    // deal with shared memory somewhere else
    cout << "<return>" << endl;
    cin.get();

    // you can just release shared memory here by use reset method
    smp.reset();
    // do some thing else
    return 0;
}