/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of pramaters and returns and what the functions do 
 * are in the header file
 * 
 * Operators, destructors, genre, transaction display are implemented in
 * child classes
 */

#include "Movie.h"

Movie::Movie() {
    Stock = 0;
    InitialStock = 0;
    Year = 0;
}

Movie::~Movie() {}

int Movie::getStockQuantity() const {
    return Stock;
}

int Movie::GetAmountBorrowed() const {
    int BorrowAmount = InitialStock - Stock;
    return BorrowAmount;
}

int Movie::GetInitialStock() const {
    return InitialStock;
}

void Movie::IncramentStock() {
    Stock++;
}

void Movie::DecrementStock() {
    Stock--;
}

string Movie::GetGenre() {
  return string();
}

bool Movie::SetData(ifstream& FileName) {
    string Temp;
    FileName >> Stock >> Temp;
    SetDataHelper(FileName);
    FileName >> Year;
    InitialStock = Stock;
    return true;
}

void Movie::SetTransactionData(ifstream&) {}

bool Movie::operator==(const Movie&) const {
  return false;
}

bool Movie::operator<(const Movie&) const {
  return false;
}

void Movie::SetDataHelper(ifstream& FileName) {
    SetDirectorHelper(FileName);
    SetTitleHelper(FileName);
}

void Movie::SetDirectorHelper(ifstream& FileName) {
    string Temp;
    FileName >> Director;
    while (Director.back() == ',') { 
        FileName >> Temp;
        Director += " ";
        Director += Temp;
    }
    Director.pop_back();
}

void Movie::SetTitleHelper(ifstream& FileName) {
    string Temp;
    FileName >> Title;
    while (Title.back() == ',') { 
        FileName >> Temp;
        Title += " ";
        Title += Temp;
    }
    Title.pop_back();
}

void Movie::Display() const {
    cout << left << setw(35) << Title << setw(19) << Director << setw(5) <<
    Year << " " << "Borrowed: " << setw(3) << GetAmountBorrowed() << " " <<
    "Remaining: " << Stock << endl;
}

string Movie::TransactionDisplay() const {
  return string();
}