/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the header (.h) file for Movie.cpp
 * This class is the parent class of movie types:
 * Classic, drama, and Comedy
 * This will be used for processing the movies.txt files 
 * Some will be implemneted in the .cpp file and others in the child classes
 */

#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Movie {
    public:
        /**
         * Standard Constructor
         * @param: None 
         * @return: None
         */ 
        Movie();

        /**
         * Destructor
         * @param: None 
         * @return: None
         */ 
        virtual ~Movie();

        /**
         * Gets the number of movies in stock
         * @param: None 
         * @return: Number of stock remaining
         */ 
        int getStockQuantity() const;

        /**
         * Gets the amount that are currently borrowed
         * @param: None 
         * @return: Number of stock being borrowed 
         */ 
        int GetAmountBorrowed() const;

        /**
         * Stock before anything is taken
         * @param: None 
         * @return: Number of total stock of movie
         */ 
        int GetInitialStock() const; 

        /**
         * Increases number of movies in stock 
         * if movie is returned
         * @param: None 
         * @return: None
         */ 
        void IncramentStock();

        /**
         * Decreases number of movies in stock
         * if movie is taken 
         * @param: None 
         * @return: None
         */ 
        void DecrementStock();

        /**
         * Gets genre of movie
         * @param: None 
         * @return: None
         */ 
        virtual string GetGenre();

        /**
         * Sets data from movie file 
         * @param: None 
         * @return: None
         */ 
        virtual bool SetData(ifstream&);
        virtual void SetTransactionData(ifstream&);

        /**
         * Operators 
         * @param: None 
         * @return: None
         */ 
        virtual bool operator==(const Movie&) const;
        virtual bool operator<(const Movie&) const;

        /**
         * Display information about movie
         * @param: None 
         * @return: None
         */ 
        virtual void Display() const;
        virtual string TransactionDisplay() const;

    protected:
        /**
         * Helper functions 
         * @param: File names  
         * @return: None
         */ 
        void SetDataHelper(ifstream&);
        void SetDirectorHelper(ifstream&); 
        void SetTitleHelper(ifstream&);

        /**
         * Protected variables for movies
         * @param: None 
         * @return: None
         */ 
        int Stock;
        int InitialStock;
        string Director;
        string Title;
        int Year;
};