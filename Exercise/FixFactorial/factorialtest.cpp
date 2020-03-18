/**
 * Defines testAll() which calls
 * all our test functions
 *
 * @file maintest.cpp
 *
 * @author Yusuf Pisan
 * @date 24 Sep 2019
 */
#include <cassert>
#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;

// prototypes to be tested
int factorialRecursive(int X);
int factorialIterative(int X);
int factorial(int X);
void factorialWrite(int X, ostream &Os);


// Testing base condition
void test01() {
  assert(1 == factorialRecursive(1) && "factorialRecursive of 1 should be 1");
  assert(1 == factorialIterative(1) && "factorialIterative of 1 should be 1");
  stringstream Ss;
  factorialWrite(1, Ss);
  string Res = Ss.str();
  assert("1" == Res && "factorialWrite should be writing 1 to output stream");
  cout << "test01 complete" << endl;
}

// Testing definition 0! = 1
void test02() {
  assert(1 == factorial(0));
  cout << "Test02 complete" << endl;
}

// Testing small number
void test03() {
  assert(2 == factorial(2));
  cout << "Test03 complete" << endl;
}

// Testing recursion
void test04() {
  assert(120 == factorial(5));
  cout << "Test04 complete" << endl;
}

// Testing large number
void test05() {
  // assert(2432902008176640000 == factorial(20));
  cout << "Test05 complete" << endl;
}

// run all tests
void testAll() {
  test01();
  test02();
  test03();
  test04();
  test05();
  cout << "TestAll complete" << endl;
}
