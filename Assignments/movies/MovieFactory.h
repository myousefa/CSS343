/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the header (.h) file for MovieFactory.cpp
 * This will be used for creating new movie objects depending
 * on the genre type.
 */

#pragma once
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Movie.h"

class MovieFactory {
    public: 
        /**
         * Standard constructor 
         * @param: None
         * @return: None 
         */ 
        MovieFactory();

        /**
         * Destructor 
         * @param: None
         * @return: None 
         */ 
        ~MovieFactory();

        /**
         * Creates type Movie object depending on genre type
         * @param: string reference depending on movie type
         * @return: Movie pointer 
         */ 
        static Movie* create(const string&);
};