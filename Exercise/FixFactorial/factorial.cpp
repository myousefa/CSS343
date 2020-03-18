/**
 * Defines various versions of factorial
 *
 * @file factorial.cpp
 *
 * @author Yusuf Pisan
 * @date 24 Sep 2019
 */
#include <cmath>
#include <iostream>

// Only for class code, OK to use namespace
using namespace std;

// Calculate factorial using recursive function
// TODO(student): FIX it, not working -- Remove this line after fixing it
int factorialRecursive(int Number) {
  if (Number > 1) {
    return Number * factorialRecursive(Number - 1);
  }
  return 1;
}

// Calculate factorial using iterative function
// TODO(student): FIX it, not working -- Remove this line after fixing it
int factorialIterative(int Number) {
  int Res = 1;
  for (int I = Number; I > 1; I--) {
    Res *= I;
  }
  if (Number == 0) {
    Res = 1;
  }
  return Res;
}

// Generic factorial function
// TODO(student): FIX it, not working -- Remove this line after fixing it
int factorial(int Number) {
  int Res = factorialRecursive(Number);
  std::cout << "Result = " << Res << std::endl;
  return Res;
}

// Writes the result of factorial to given ostream or cout
void factorialWrite(int Number, ostream &Os = cout) { Os << factorial(Number); }
