#include <thread>
#include <iostream>
#include "spinlock.h"

using namespace std;

// Lock, we need to use a release fence to synchronize the flag
// update, with any other threads attempts to read/write the
// value.
void spinlock::lock() {
    // Spin until we can set the flag
    while (flag.test_and_set()) {}
    std::atomic_thread_fence(std::memory_order_release);
}

void spinlock::unlock() {
    flag.clear();
    std::atomic_thread_fence(std::memory_order_release);
}

bool spinlock::locked() {
    bool set = flag.test();
    std::atomic_thread_fence(std::memory_order_acquire);
    return set;
}

