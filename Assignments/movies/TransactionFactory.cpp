/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of pramaters and returns and what the functions do 
 * are in the header file
 */

#include "TransactionFactory.h"

TransactionFactory::TransactionFactory() {}

TransactionFactory::~TransactionFactory() {}

Transaction* TransactionFactory::create(const string& TransactionType) {
    if (TransactionType == "B") { 
        return new Borrow();
    }
    if (TransactionType == "R") { 
        return new Return();
    }
    if (TransactionType == "H") { 
        return new History();
    }
    if (TransactionType == "I") { 
        return new Inventory();
    }
    cout << "Invalid command!" << endl;
    return nullptr;
}