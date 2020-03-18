/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of pramaters and returns and what the functions do 
 * are in the header file
 */

#include "Inventory.h"

Inventory::Inventory() {}

Inventory::~Inventory() {}

bool Inventory::SetData(ifstream&) {
  return true;
}

void Inventory::DoTransactionCommand(const vector<Movie*>&, const HashTable&) {
}

char Inventory::GetCommand() const {
  return Command;
}

void Inventory::Display() const {}

Movie* Inventory::getTitleMovie() const {
  return nullptr;
}