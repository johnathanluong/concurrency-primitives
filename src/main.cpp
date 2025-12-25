#include "tests/TestRunner.hpp"

int main()
{
  TestRunner::Instance().run_all();
  return 0;
}
