#include "tests/TestRunner.hpp"
#include <iostream>

void TestRunnerTest()
{
  std::cout << "The test runner works !!" << std::endl;
}

TEST("TestTheTestRunner", TestRunnerTest);
