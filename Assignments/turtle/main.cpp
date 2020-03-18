/**
 * A generic main file
 * @file main.cpp
 *
 *
 * @author Yusuf Pisan
 * @date 24 Sep 2019
 */

#include "turtleprogram.h"
#include <iostream>

// forward declaration, testAll is defined in another file
void testAll();


void my_tests(){

  // TurtleProgram t("F","100");
  // cout << t << endl;

  // TurtleProgram tp(t);
  // cout << tp << endl;

  // tp *= 3;
  // cout << tp << endl;
  // cout << t << endl;

  // t = tp;
  // cout << t << endl;

  // cout << t << endl;
  // TurtleProgram t3("L","20");
  // t = t + t3;
  // cout << t << endl;
  // TurtleProgram t4("R","45");
  // t = t + t4;
  // cout << t << endl;
  // TurtleProgram t5("F","422");
  // t = t + t5;
  // cout << t << endl;
  // TurtleProgram t6("R","360");
  // t = t + t6;
  // cout << t << endl;
  // TurtleProgram t7("R","475");
  // t = t + t7;
  // cout << t << endl;

  // TurtleProgram t8("F","100");

  // cout << " --- Testing == Operater -----\n";
  // bool res = t != t2;
  // cout << "Result t == t2? ---> " << res << endl;
  // bool res2 = t1_5 != t8;
  // cout << "Result t == t8? ---> " << res2 << endl;
}

int main() {
  //my_tests();
  testAll();

  std::cout << "Done!" << std::endl;
  return 0;
}

