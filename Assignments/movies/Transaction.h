/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the header (.h) file for Transaction.cpp
 * Parent class of:
 * Return, Borrow, Inventory, History 
 * Some functions implemented in .cpp file but most in child classes
 */

#pragma once
#include "Movie.h"
#include <fstream>
#include <string>
#include <vector>

class HashTable;

using namespace std;

class Transaction {
    public:
        /**
         * Standard constructor 
         * @param: None
         * @return: None 
         */ 
        Transaction();

        /**
         * Destructor 
         * @param: None
         * @return: None 
         */ 
        ~Transaction();

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
         * Movie title getter 
         * @param: None
         * @return: None 
         */ 
        virtual Movie* GetTitleMovie() const;

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
        Movie* FindMovie(const vector<Movie*>&, Movie*) const;
        
    protected: 
        string MediaType = "D";
};