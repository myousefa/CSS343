/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the header (.h) file for Transaction.cpp
 * This will be used for creating new transaction objects depending
 * on the transaction type.
 * Borrow, return, inventory
 */

#pragma once
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"
#include "Transaction.h"

class TransactionFactory { 
    public: 
        /**
         * Standard constructor
         * @param: None 
         * @return: None 
         */ 
        TransactionFactory();

        /**
         * Destructor
         * @param: None 
         * @return: None 
         */ 
        ~TransactionFactory();

        /**
         * Create function creates transaction object type 
         * dependent on the type of transaction
         * @param: string refrence on type of transaction 
         * @return: Transaction pointer object return type 
         */ 
        static Transaction* create(const string&);
};