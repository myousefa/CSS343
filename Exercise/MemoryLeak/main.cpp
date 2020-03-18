/**
 * Lots of memory leaks. Gotta fix them all!
 * But, you cannot fix them all at once.
 * Work on one test at a time
 *
 * Below examples don't use -Wall -Wextra when compiling since there are
 * lots of unused variables
 *
 * To confirm memory leak is fixed use:
 *     $ g++ -std=c++14 -g *.cpp
 *     $ valgrind ./a.out
 * Or
 *     $ clang++ -std=c++14 -fsanitize=address -fno-omit-frame-pointer -g *.cpp
 *     $ ASAN_OPTIONS=detect_leaks=1 ./a.out
 *
 * Assuming a.out is the name of your executable,
 * which is a horrible name, but so it goes :-)
 *
 * .clang-format - This project uses LLVM coding style
 * .clang-tidy - Some warnings due to unavoidable tests
 *
 */

#include <iostream>

using namespace std;

// forward declarations
void test1();
void test2();
void test3();

int main() {
  cout << "Starting memory-leaks-r-us...." << endl;
  test1();
  test2();
  test3();
  cout << "Successfully completed memory-leaks-r-us...." << endl;
  return 0;
}
