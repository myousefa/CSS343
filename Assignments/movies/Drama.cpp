/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of paramaters and returns and what the functions does 
 * are in the header file
 * 
 * Operators, constructors, setters and getters, are implemented here
 * 
 * Documentation in header file
 */

#include "Drama.h"

Drama::Drama() {}

Drama::~Drama() {}

string Drama::GetGenre() {
    return Genre;
}

void Drama::SetTransactionData(ifstream& FileName) {
    Movie::SetDataHelper(FileName);
}

bool Drama::operator<(const Movie& Movies) const {
    const auto temp = dynamic_cast<const Drama&>(Movies);
    if (Director < temp.Director) {
        return true;
    }
    return (Director == temp.Director && Title < temp.Title);
}

bool Drama::operator==(const Movie& Movies) const {
    const auto temp = dynamic_cast<const Drama&>(Movies);
    return (Genre == temp.Genre && Director == temp.Director && 
            Title == temp.Title);
}


string Drama::TransactionDisplay() const {
    string temp;
    temp += Genre + " " + Director + ", " + Title;
    return temp;
}
