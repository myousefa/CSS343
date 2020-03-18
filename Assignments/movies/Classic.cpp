/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of pramaters and returns and what the functions do 
 * are in the header file
 * 
 * Operators, constructors, setters and getters, are implemented here
 * 
 * Documentation in header file
 */

#include "Classic.h"

Classic::Classic() {
    Month = 0;
}

Classic::~Classic() {}

string Classic::GetGenre() {
    return Genre;
}

bool Classic::SetData(ifstream& FileName) {
    string Temp;
    FileName >> Stock >> Temp;
    Movie::SetDataHelper(FileName);
    FileName >> ActorFirstName >> ActorLastName >> Month >> Year;
    InitialStock = Stock;
    return true;
}

void Classic::SetTransactionData(ifstream& FileName) {
    FileName >> Month >> Year >> ActorFirstName >> Year;
}

bool Classic::operator<(const Movie& Movies) const{
    const auto temp = dynamic_cast<const Classic&>(Movies);

    if (Year < temp.Year) {
        return true;
    }
    if (Year == temp.Year && Month < temp.Month) {
        return true;
    }
    if (Year == temp.Year && Month == temp.Month && 
        ActorFirstName < temp.ActorFirstName) {
        return true;
    }
    return (Year == temp.Year && Month == temp.Month && 
            ActorFirstName == temp.ActorFirstName && 
            ActorLastName < ActorFirstName);
}

bool Classic::operator==(const Movie& Movies) const{
    const auto temp = dynamic_cast<const Classic&>(Movies);
    return (ActorFirstName == temp.ActorFirstName && 
            ActorLastName == temp.ActorLastName &&
            Month == temp.Month && Year == temp.Year);
}

void Classic::Display() const {
    string Actor = ActorFirstName + " " + ActorLastName;
    cout << left << setw(35) << Title << setw(19) << Director << setw(3) << 
    Month << setw(5) << Year << setw(19) << Actor << "Borrowed: " << setw(3) 
    << GetAmountBorrowed() << " " << "Remaining: " << Stock << endl;
}

string Classic::TransactionDisplay() const {
    auto Mon = to_string(Month);
    auto Yea = to_string(Year);
    string temp;
    temp += Genre + " " + Mon + " " + Yea + " " + ActorFirstName + " " + 
    ActorLastName;
    return temp;
}
