/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the .h file for creating and getting history
 * of customers and movies
 * Child class of transaction
 * When a customer  a movie from store.
 */

#pragma once
#include "Transaction.h"
#include "HashTable.h"
#include "Movie.h"
#include "Transaction.h"
#include <fstream>
#include <vector>

class Inventory : public Transaction {
    public:
        /**
         * Standard constructor 
         * @param: None
         * @return: None 
         */ 
        Inventory();

        /**
         * Destructor 
         * @param: None
         * @return: None 
         */ 
        ~Inventory();

        /**
         * Sets data from commands file
         * @param: File
         * @return: None 
         */ 
        virtual bool SetData(ifstream&);

        /**
         * Process transaction command 
         * @param: None
         * @return: None 
         */ 
        virtual void DoTransactionCommand(const vector<Movie*>&, 
                                          const HashTable&);

        /**
         * Getter for command
         * @param: None
         * @return: None 
         */ 
        virtual char GetCommand() const;

        /**
         * Displays transaction
         * @param: None
         * @return: None 
         */ 
        virtual void Display() const;

        /**
         * Finds movie
         * @param: None
         * @return: None 
         */ 
        Movie* getTitleMovie() const;

    protected:
        const char Command = 'I';
};
