#include <atomic>

class spinlock {
public:
    spinlock(): flag(ATOMIC_FLAG_INIT) {}

    void lock();
    void unlock();
    bool locked();
private:
    std::atomic_flag flag;
};