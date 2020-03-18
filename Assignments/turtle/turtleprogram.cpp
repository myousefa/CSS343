/**
 * This program creates a dynamic array 
 * that expands. It also implements turtleprogram.h.
 *
 * @author Mohammed Ali
 * @date 18 January 2020
 */

#include "turtleprogram.h"
#include <cassert>

using namespace std;

// -------------------------------------------------------------------------------------------------------

// constructor with no parameter
TurtleProgram::TurtleProgram() {
  Commands = nullptr;
  Size = 0;
}

// -------------------------------------------------------------------------------------------------------

// constructor with one parameter
TurtleProgram::TurtleProgram(const string &Command) {
  Size = 1;
  Commands = new string[Size];
  Commands[0] = Command;
}

// -------------------------------------------------------------------------------------------------------

// constructor with two parameters
TurtleProgram::TurtleProgram(const string &Command, const string &Times) {
  Size = 2;
  PSize = &Size;
  currentSize = 2;
  Commands = new string[Size];
  Commands[0] = Command;
  Commands[1] = Times;
}

// -------------------------------------------------------------------------------------------------------

// copy constructor
TurtleProgram::TurtleProgram(const TurtleProgram &Tp) {
  this->Size = Tp.Size;
  this->currentSize = Tp.currentSize;

  auto * TempContents = new string[this->Size];
  for(int I = 0; I < this->Size; ++I){
    TempContents[I] = Tp.Commands[I];
  }
  for(int I = 0; I < this->Size; ++I){
    //cout << temp_contents[I] << " ";
  }
  //cout << endl;

  this->Commands = TempContents;
}

// -------------------------------------------------------------------------------------------------------

// accessors
// getLength returns the amount of strings in the program
int TurtleProgram::getLength() const {
  int Count = 0;
  for(int I = 0; I < this->Size; I++){
    if(this->Commands[I] != "null"){
      Count++;
    }
  }
  return Count;
}
// getIndex returns the string in the desired index
string TurtleProgram::getIndex(const int &I) const {
  return Commands[I];
}

// mutators
// setIndex replaces string at that index
void TurtleProgram::setIndex(const int &I, const string &Str) {
  Commands[I] = Str;
}

// -------------------------------------------------------------------------------------------------------

// equality
bool TurtleProgram::operator!=(const TurtleProgram &Rhs) const {
  if(this->Size == Rhs.Size && this->currentSize == Rhs.currentSize ){
    int Counter = 0;
    // Check if the contents are the same
    for(int I = 0; I < this->currentSize; ++I){
      if(this->Commands[I] == Rhs.Commands[I]){
        Counter++;
      }
      else{
        return true;
      }
      if(Counter == this->currentSize){
        return false;
      }
    }
  }
  return true;
}

bool TurtleProgram::operator==(const TurtleProgram &Rhs) const {
  if(this->Size == Rhs.Size && this->currentSize == Rhs.currentSize ){
    int Counter = 0;
    // Check if the contents are the same
    for(int I = 0; I < this->currentSize; ++I){
      if(this->Commands[I] == Rhs.Commands[I]){
        Counter++;
      }
      else{
        return false;
      }
      if(Counter == this->currentSize){
        return true;
      }
    }
  }
  return true;
}

// + and +=
TurtleProgram TurtleProgram::operator+(const TurtleProgram &Tp) {
  // count the number of null spaces left to place elements from Tp
  int LeftOverSize = this->Size - this->currentSize;

  // check if there is space to place elements from Tp
  if(LeftOverSize >= Tp.getLength()){
    // emplace elements of Tp into "this" object's Command array
    int PlaceLocation = this->currentSize;
    for(int I = PlaceLocation, J = 0; I < this->Size + Tp.Size; ++I, ++J){
      if(J < Tp.Size){
        this->Commands[I] = Tp.Commands[J];
      }
    }
    // Update the size increase
    this->currentSize += Tp.getLength();
  }
  else{
    // if there are not enough element spaces for the contents of Tp --> resize array
    this->Commands = this->resizeArray();
    // add new elements from incoming Tp
    int PlaceLocation = this->currentSize;
    for(int I = PlaceLocation, J = 0; I < this->Size + Tp.Size; ++I, ++J){
      if(J < Tp.Size){
        this->Commands[I] = Tp.Commands[J];
      }
    }
    // Update the size increase
    this->currentSize += Tp.getLength();
  }
  return *this;
}


// Copy of + operator
TurtleProgram TurtleProgram::operator+=(const TurtleProgram &Tp) {
  // count the number of null spaces left to place elements from Tp
  int LeftOverSize = this->Size - this->currentSize;
  // check if there is space to place elements from Tp
  if(LeftOverSize >= Tp.getLength()){
    // emplace elements of Tp into "this" object's Command array
    int PlaceLocation = this->currentSize;
    for(int I = PlaceLocation, J = 0; I < this->Size + Tp.Size; ++I, ++J){
      if(J < Tp.Size){
        // += to add on
        this->Commands[I] = Tp.Commands[J];
      }
    }
    // Update the size increase
    this->currentSize += Tp.getLength();
  }
  else{
    printf("ok\n");
    cout << "size rn = " << this->currentSize << endl;
    // if there are not enough element spaces for the contents of Tp --> resize array
    this->Commands = this->resizeArray();
    cout << "size rn = " << this->Size << endl;
    // add new elements from incoming Tp
    int PlaceLocation = this->currentSize;
    for(int I = PlaceLocation, J = 0; I < this->Size + Tp.Size; ++I, ++J){
      if(J < Tp.Size){
        // += to add on
        this->Commands[I] = Tp.Commands[J];
      }
    }
    // Update the size increase
    this->currentSize += Tp.getLength();
  }
  return *this;
}

// * and *=
TurtleProgram TurtleProgram::operator*(const int &Times) {
  if(this->Size == 2){
    for(int I = 0; I < Times - 1; I++){
      string Direction = this->Commands[0];
      string Amnt = this->Commands[1];
      TurtleProgram Temp(Direction,Amnt);
      *this = *this + Temp;
    }
  }
  else{
    int patternSize = this->currentSize;
    for(int I = 0; I < Times - 1; I++){
      for(int J = 0, K = this->currentSize + 1 ; J < patternSize; J++,K++){
        if(K >= this->Size){
          this->Commands = this->resizeArray();
        }
        this->Commands[K - 1] = this->Commands[J];
        this->currentSize++;
      }
    }
  }
  return *this;
}

TurtleProgram &TurtleProgram::operator*=(const int &Times) {
  if(this->Size == 2){
    for(int I = 0; I < Times - 1; I++){
      string Direction = this->Commands[0];
      string Amnt = this->Commands[1];
      TurtleProgram Temp(Direction,Amnt);
      *this = *this + Temp;
    }
    return *this;
  }
  else{
    int patternSize = this->currentSize;
    for(int I = 0; I < Times - 1; I++){
      for(int J = 0, K = this->currentSize + 1 ; J < patternSize; J++,K++){
        if(K >= this->Size){
          this->Commands = this->resizeArray();
        }
        this->Commands[K - 1] = this->Commands[J];
        this->currentSize++;
      }
    }
  }
  return *this;
}

// Sets index to value
TurtleProgram &TurtleProgram::operator=(const TurtleProgram &Rhs) { // copy assignment
  this->Size = Rhs.Size;
  this->PSize = &this->Size;
  this->Commands = Rhs.Commands;
  this->currentSize = Rhs.currentSize;
  return *this;
}

// Destructor
TurtleProgram::~TurtleProgram() {
  // this->Size = 0;
  // this->currentSize = 0;
  // this->clearArrayContents();
}

// --------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
ostream &operator<<(ostream &Out, const TurtleProgram &Tp) {
  Out << "[";
  for(int I = 0; I < Tp.Size; ++I){
    if(Tp.Commands[I] != "null"){
      Out << Tp.Commands[I];
      if(I < Tp.Size - 1){
        Out << " ";
      }
    }
  }
  Out << "]";
  return Out;               
}

// ---------------------- Dynamic Array Functions ---------------------------
string* TurtleProgram::resizeArray(){
  // Create & allocate a new array with 2 times the size
  int NewSize = this->Size * 2;
  auto * NewSizeCommands = new string[NewSize];

  // copying old contents into bigger array
  for(int I = 0; I < NewSize; ++I){
    // copy elements until the end of the small array
    if(I < this->Size){
      NewSizeCommands[I] = this->Commands[I];
    }
    else{
    // the rest of the elements will be "null"
    NewSizeCommands[I] = "null";
    } 
  }

  // clear memory location + contents of small array 
  this->clearArrayContents();
  // update the class fields with new sizes and data array
  this->Size = NewSize;
  this->PSize = &NewSize;
  this->Commands = NewSizeCommands;
  return this->Commands;
}

// delete array to free up memory
void TurtleProgram::clearArrayContents(){
  delete[] this->Commands;
  this->Commands = nullptr;
}