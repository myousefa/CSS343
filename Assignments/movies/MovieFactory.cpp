/**
 * Mohammed Ali
 * CSS 343 Yusuf Pisan 
 * 11 March 2020
 * 
 * This is the implementation of the header file
 * All descriptions of pramaters and returns and what the functions do 
 * are in the header file
 */

#include "MovieFactory.h"

MovieFactory::MovieFactory() {}

MovieFactory::~MovieFactory() {}

Movie* MovieFactory::create(const string& Genre) {
    if (Genre == "D") {
        return new Drama();
    }
    if (Genre == "F") {
        return new Comedy();
    }
    if (Genre == "C") {
        return new Classic();
    }
    cout << "Invalid Movie!" << endl;
    return nullptr;
}