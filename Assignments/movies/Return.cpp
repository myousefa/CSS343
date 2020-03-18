/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of pramaters and returns and what the functions do 
 * are in the header file
 */

#include "Return.h"

Return::Return() {
    CustomerID = 0;
    TitleMovie = nullptr;
}

Return::~Return() {
    delete TitleMovie;
}

bool Return::SetData(ifstream& FileName)
{
    string Genre;
    FileName >> CustomerID >> MediaType >> Genre; 
    TitleMovie = MovieFactory::create(Genre);
    if (!TitleMovie) {
        return false;
    }
    TitleMovie->SetTransactionData(FileName);
    return true;
}

void Return::DoTransactionCommand(const vector<Movie*>& Mov, 
                                  const HashTable& Customers) {
    Customer* TempCustomer; 
    TempCustomer = Customers.GetItem(CustomerID);
    if (!TempCustomer) {
        cout << "Customer " << CustomerID << " not found!" <<endl;
    }

    Movie* Temp = FindMovie(Mov, TitleMovie); 
    if(!Temp) {
        cout << "Movie " + TitleMovie->TransactionDisplay() << 
        " not found!" <<endl;
    }

    if (TempCustomer && Temp) {
        if (TempCustomer->isBorrowed(Temp)) {
            TempCustomer->AddTransactionHistory(this);
            Temp->IncramentStock();
        }
        else { 
            cout << Temp->TransactionDisplay() + 
            " Customer did not borrow this movie!" << endl;
        }
    }
    else {
        cout << "Return Failed" << endl;
    }
}

void Return::Display() const {
  cout << "Return: " << MediaType << " " << 
  TitleMovie->TransactionDisplay() << endl;
}

char Return::GetCommand() const
{
  return Command;
}

Movie* Return::getTitleMovie() const
{
  return TitleMovie;
}
