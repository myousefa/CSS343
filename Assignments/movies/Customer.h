/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the header (.h) file for Customer.cpp
 * This will be used for customers accounts. 
 * It will store the data from the file.
 */

#pragma once
#include "Movie.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int MINID = 1000;
const int MAXID = 9999;
class Transaction; 

class Customer { 
    public: 
        
        /**
         * Standard constructor 
         * @param: None
         * @return: None 
         */ 
        Customer();

        /**
         * Destructor 
         * @param: None
         * @return: None 
         */ 
        ~Customer();

        /**
         * Gets User ID
         * @param: None
         * @return: None 
         */ 
        int GetID();

        /**
         * Adds transaction to history
         * @param: 
         * @return: None 
         */ 
        void AddTransactionHistory(Transaction*);

        /**
         * Displays history of item
         * @param: None
         * @return: None 
         */ 
        void DisplayHistory();

        /**
         * Sets the data
         * @param: File
         * @return: None 
         */ 
        bool SetData(ifstream&);

        /**
         * Checks if a movie is borrowed 
         * @param: Passes in movie
         * @return: None 
         */ 
        bool isBorrowed(Movie*);

    private:
        /**
         * Private variables 
         * @param: None
         * @return: None 
         */ 
        int ID;
        string LastName;
        string FirstName;
        vector<Transaction*> History;
};