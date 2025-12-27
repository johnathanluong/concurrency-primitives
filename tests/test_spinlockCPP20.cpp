#include "primitives/SpinlockCPP20.hpp"
#include "tests/TestRunner.hpp"
#include <cassert>
#include <thread>

void test_spinlockCPP20()
{
  SpinlockCPP20 spinlock;
  int resource = 0;
  constexpr int rounds = 1000;

  // Task for each thread that increments the same resource 1000 times concurrently
  auto task = [&]()
  {
    for(int i = 0; i < rounds; ++i)
    {
      spinlock.lock();
      ++resource;
      spinlock.unlock();
    }
  };

  std::thread t1(task);
  std::thread t2(task);

  if(t1.joinable())
  {
    t1.join();
  }
  if(t2.joinable())
  {
    t2.join();
  }

  constexpr int kExpected = rounds * 2; 
  assert(resource == kExpected);
}

TEST("Test SpinlockCPP20", test_spinlockCPP20);
