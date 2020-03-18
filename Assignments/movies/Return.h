/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the .h file for creating and return commands
 * of customers and movies
 * Child class of transaction
 * When a customer returns a movie to store.
 * this class will deal with that command
 */

#pragma once
#include "Customer.h"
#include "Transaction.h"
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include <fstream>
#include <vector>

class Return : public Transaction {
    public:
        /**
         * Standard constructor 
         * @param: None
         * @return: None 
         */ 
        Return();

        /**
         * Destructor 
         * @param: None
         * @return: None 
         */ 
        ~Return();

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
        const char Command = 'R';

    private: 
        Movie* TitleMovie; 
        int CustomerID;
};
