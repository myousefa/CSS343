/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the .h file for borrowing movies
 * Child class of transaction
 * When a customer borrows a movie from store
 * this class deals with that command
 */

#pragma once
#include "Customer.h"
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include <fstream>
#include <set>

class Borrow : public Transaction {
    public:
        /**
         * Standard constructor 
         * @param: None
         * @return: None 
         */ 
        Borrow();

        /**
         * Main Constructor initializes values 
         * @param: int and movie* 
         * @return: None 
         */ 
        Borrow(Movie*, int);

        /**
         * Destructor 
         * @param: None
         * @return: None 
         */ 
        ~Borrow();

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
        const char Command = 'B';

    private: 
        Movie* titleMovie;
        int CustomerID;
};
