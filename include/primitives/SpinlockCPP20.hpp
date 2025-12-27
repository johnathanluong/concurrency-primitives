#ifndef SPINLOCK_20_HPP
#define SPINLOCK_20_HPP
#include <tests/TestRunner.hpp>
#include <atomic>

class SpinlockCPP20
{
public:
  void lock()
  {
    // Blocks while lock is cleared then acquires the lock
    while(locked_.test_and_set(std::memory_order_acquire))
    {
      locked_.wait(true, std::memory_order_relaxed);
    }
  }

  void unlock()
  {
    // Thread unlocks and notifies a thread that
    // they are good to acquire
    locked_.clear(std::memory_order_release);
    locked_.notify_one();
  }

private:
  std::atomic_flag locked_ {};
};


#endif // SPINLOCK_20_HPP
