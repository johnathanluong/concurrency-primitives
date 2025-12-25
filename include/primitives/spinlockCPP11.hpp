#ifndef SPINLOCKCPP11_HPP
#define SPINLOCKCPP11_HPP

#include <atomic>
#include <thread>

// This class implements a spinlock without the use of C++20 atomic_flag operations
// It will less performant as we will be using a busy wait to check for lock_ state
class SpinlockCPP11
{
public:
  // When function returns, the lock is guaranteed to be owned by the current thread
  void lock()
  {
    while(lock_.test_and_set(std::memory_order_acquire))
    {
      std::this_thread::yield();
    }
  }
  
  // When function returns, the lock is guaranteed to be unlocked
  void unlock()
  {
    lock_.clear(std::memory_order_release);
  }
  
  /*
   * Cannot use a CheckUnlocked() function as, by the time a function returns true/false,
   * another thread could have changed its state
   */
private:
  std::atomic_flag lock_{};
};

#endif // !SPINLOCKCPP11_HPP
