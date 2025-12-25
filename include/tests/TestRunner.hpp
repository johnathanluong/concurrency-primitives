#ifndef TEST_RUNNER_HPP
#define TEST_RUNNER_HPP

#include <exception>
#include <string>
#include <vector>
#include <iostream>

using FuncPtr = void(*)();
struct Test_t
{
  std::string name;
  FuncPtr test_function;
};

class TestRunner
{
public:
  static TestRunner& Instance()
  {
    static TestRunner instance;
    return instance;
  }

  void registerTest(std::string name, FuncPtr test_function)
  {
    tests_.emplace_back(std::move(name), std::move(test_function));
  }

  void run_all()
  {
    int passed{0};
    std::cout << "Starting Test Suite !!!\n" << std::endl;

    for(const auto& test : tests_)
    {
      std::cout << "[ RUN    ] " << test.name << std::endl;
      try
      {
        test.test_function(); 
        std::cout << "[     OK ]" << test.name << std::endl;
        ++passed;
      }
      catch(const std::exception& e)
      {
        std::cerr << "[  FAILED  ] " << test.name << " (Exception: " << e.what() << ")" << std::endl;
      }
      catch(...)
      {
        std::cerr << "[  FAILED  ] " << test.name << " (Unknown Error)" << std::endl;
      }
    }

    std::cout << "\n==== Summary: " << passed << "/" << tests_.size() << " tests passed ====" << std::endl;
  }

private:
  std::vector<Test_t> tests_;
};

// Helper to register test functions
struct TestRegister 
{
    TestRegister(std::string name, FuncPtr test_function) {
        TestRunner::Instance().registerTest(std::move(name), std::move(test_function));
    }
};

// TEST Macro
// Usage: TEST("Test SpinlockCPP11", test_spinlockCPP11);
#define TEST(test_name, func_name) \
    static TestRegister test_reg_##func_name(test_name, func_name)

#endif // !TEST_RUNNER_HPP
