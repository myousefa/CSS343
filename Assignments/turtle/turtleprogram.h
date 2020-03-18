/**
 * TurtleProgram interface
 *
 * @author Mohammed Ali
 * @date 17 January 2020
 */

#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H

#include <iostream>

using namespace std;

class TurtleProgram {
  friend ostream &operator<<(ostream &Out, const TurtleProgram &Tp);

public:
  // constructor
  TurtleProgram();
  // constructor with one parameter
  explicit TurtleProgram(const string &Command);
  // constructor with two parameters 
  TurtleProgram(const string &Command, const string &Times);
  // copy constructor
  TurtleProgram(const TurtleProgram &Tp);
  // destructor
  virtual ~TurtleProgram();

  // accessors and mutators
  int getLength() const;
  string getIndex(const int &I) const;
  void setIndex(const int &I, const string &Str);

  //equalities
  bool operator==(const TurtleProgram &Rhs) const;
  bool operator!=(const TurtleProgram &Rhs) const;

  //operators
  TurtleProgram &operator=(const TurtleProgram &Rhs);
  TurtleProgram operator+(const TurtleProgram &Tp);
  TurtleProgram operator+=(const TurtleProgram &Tp);
  TurtleProgram operator*(const int &Times);
  TurtleProgram &operator*=(const int &Times);


  
// protected:

// private:
  // Dynamically resize the array methods
  string* resizeArray();
  void clearArrayContents();

  int * PSize = nullptr; 
  int Size = 0;
  int currentSize = 0;
  // String array of commands
  string * Commands;
};

#endif // TURTLEPROGRAM_H
