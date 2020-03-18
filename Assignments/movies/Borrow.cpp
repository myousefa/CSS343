/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of pramaters and returns and what the functions do 
 * are in the header file
 */

#include "Borrow.h"

Borrow::Borrow() {
    CustomerID = 0;
    titleMovie = nullptr;
}

Borrow::Borrow(Movie* Mov, int ID) {
    CustomerID = ID;
    titleMovie = Mov; 
}

Borrow::~Borrow() {
    delete titleMovie;
}

bool Borrow::SetData(ifstream& FileName) {
    string Genre;
    FileName >> CustomerID >> MediaType >> Genre; 
    titleMovie = MovieFactory::create(Genre);
    if (titleMovie == nullptr) {
        return false;
    }
    titleMovie->SetTransactionData(FileName);
    return true;
}

void Borrow::DoTransactionCommand(const vector<Movie*>& Mov, 
                                  const HashTable& Customers) {
    Customer* TempCustomer; 
    TempCustomer = Customers.GetItem(CustomerID);
    if (TempCustomer == nullptr) {
        cout << "Customer " << CustomerID << " not found!" <<endl;
    }

    Movie* Temp = FindMovie(Mov, titleMovie); 
    if(Temp == nullptr) {
        cout << "Movie " + titleMovie->TransactionDisplay() << 
        " not found!" <<endl;
    }

    if (TempCustomer != nullptr && Temp != nullptr) {
        if (Temp->getStockQuantity() > 0) {
            TempCustomer->AddTransactionHistory(this);
            Temp->DecrementStock();
        }
        else {
            cout << "This movie has 0 stock." << endl;
        }
    }
}

void Borrow::Display() const {
    cout << "Borrow: " << MediaType << " " << 
    titleMovie->TransactionDisplay() << endl;
}

char Borrow::GetCommand() const {
  return Command;
}

Movie* Borrow::getTitleMovie() const {
  return titleMovie;
}

