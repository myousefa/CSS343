/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the .h file for Store.cpp 
 * This class is essential as it stores 
 * movies, customers, and transactions
 */

#pragma once
#include "Customer.h"
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include "TransactionFactory.h"
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <queue>

class Store {
    public:
        /**
         * Standard constructor 
         * @param: None
         * @return: None 
         */ 
        Store();

        /**
         * Destructor 
         * @param: None
         * @return: None 
         */ 
        ~Store();

        /**
         * Gets the inventory from vector based on genre
         * @param: string reference for the genre
         * @return: vector return
         */ 
        vector<Movie*>& getInv(const string&);

        /**
         * Gets the customers from hashtable
         * @param: None 
         * @return: None
         */ 
        HashTable& getCustomers();

        /**
         * Displays the inventory of movies
         * @param: None
         * @return: None 
         */ 
        void displayInv();        

        /**
         * Builds store by taking in movie customer and transaction type
         * @param: 3 string refrences associated with movie, customer, and 
         *         transaction type
         * @return: True if successfully reading the file or false if not
         */ 
        bool storeBuilder(const string&, const string&, const string&);

        /**
         * Executes commands utilizes a queue to store commands
         * @param: None
         * @return: None 
         */ 
        void executeCommand();

    protected:
        /**
         * Helper functions to public functions
         * @param: Reads file
         * @return: None
         */ 
        void verifyMovie(ifstream&);
        void verifyCustomer(ifstream&);
        void verifyCommand(ifstream&);

        /**
         * Adds movie into container depending on genre
         * @param: Movie pointer and string reference 
         * @return: true or false if successful 
         */ 
        bool addInv(Movie*, const string&);

        /**
         * Helper function to addInv
         * @param: vector movie pointer and movie pointer 
         * @return: true or false if successful
         */  
        bool addInvHelper(vector<Movie*>&, Movie*);

        /**
         * Discards line or remaining part of line 
         * @param: None
         * @return: None 
         */ 
        void lineDiscard(ifstream&);

    private: 
        /**
         * Private variables that will store everything
         * @param: None
         * @return: None 
         */ 
        HashTable Customers;
        vector<Movie*> Comedy;
        vector<Movie*> Classic;
        vector<Movie*> Drama;
        vector<Movie*> Temporary;
        queue<Transaction*> Commands;
};
