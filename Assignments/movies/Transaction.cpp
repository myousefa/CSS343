/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of pramaters and returns and what the functions do 
 * are in the header file
 * 
 * These functions are blank and will be implemented in child classes
 */

#include "HashTable.h"
#include "Transaction.h"

Transaction::Transaction() {}

Transaction::~Transaction() {}

bool Transaction::SetData(ifstream&) {
  return false;
}

void Transaction::DoTransactionCommand(const vector<Movie*>&, 
                                       const HashTable&) {}

void Transaction::Display() const {}

char Transaction::GetCommand() const {
    return ' ';
}

Movie* Transaction::GetTitleMovie() const {
    return nullptr;
}

Movie* Transaction::FindMovie(const vector<Movie*>& Mov, Movie* Target) const {
    for (auto I : Mov)
        if (*Target == *I) {
            return I;
        }
    return nullptr;
}
