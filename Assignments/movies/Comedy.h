/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the header (.h) file for comedy.cpp
 * This class is a child class of Movie
 * Will be used to verify comedies and sort 
 */

#pragma once
#include "Movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class Comedy : public Movie {
    public: 
        /**
         * Standard Constructor
         * @param: None 
         * @return: None
         */
        Comedy();

        /**
         * Constructor to initialize values  
         * @param: int, string refrence, string refrence, int (order of in file)
         * @return: None
         */
        Comedy(int, const string&, const string&, int);

        /**
         * Destructor
         * @param: None 
         * @return: None
         */
        ~Comedy();

        /**
         * Gets genre of movie
         * @param: None 
         * @return: None
         */ 
        string GetGenre();

        /**
         * Sets data from movie file 
         * @param: None 
         * @return: None
         */ 
        void SetTransactionData(ifstream&);

        /**
         * Operators 
         * @param: None 
         * @return: None
         */ 
        bool operator==(const Movie&) const;
        bool operator<(const Movie&) const;

        /**
         * Display information about movie
         * @param: None 
         * @return: None
         */ 
        string TransactionDisplay() const;
    
    private:
        /**
         * Private variables for Classic
         * @param: None 
         * @return: None
         */ 
        const string Genre = "F";
        string ActorFirstName;
        string ActorLastName;

};