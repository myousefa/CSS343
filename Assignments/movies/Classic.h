/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the header (.h) file for classic.cpp
 * This class is a child class of Movie
 * Will be used to verify classics and sort
 * Year, Month, Actor FirstName, Actor LastName 
 */

#pragma once
#include "Movie.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class Classic : public Movie {
    public: 
        /**
         * Standard Constructor
         * @param: None 
         * @return: None
         */
        Classic();

        /**
         * Destructor
         * @param: None 
         * @return: None
         */
        ~Classic();

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
        bool SetData(ifstream&);
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
        void Display() const;
        string TransactionDisplay() const;
    
    private:
        /**
         * Private variables for Classic
         * @param: None 
         * @return: None
         */ 
        const string Genre = "C";
        string ActorFirstName;
        string ActorLastName;
        int Month;

};