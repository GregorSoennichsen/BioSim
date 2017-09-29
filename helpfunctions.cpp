/*
 * extractdata.h
 *
 *  Created on: 26.09.2017
 *      Author: Gregor Soennichsen
 */

#include <string>
#include <fstream>

using namespace std;



/**
 * @brief stringTOlower     Turns all uppercase chars to lowercase chars.
 * @param str               The string that has to be manipulated.
 *
 * Generates a new string, that contains all characters of the input string
 * in lowercase.
 */
string stringTOlower(const string str) {
    string strnew;
    unsigned int i;
    for(i=0; i<str.size(); i++) {
        strnew += tolower(str[i]);
    }
    return strnew;
}



/**
 * @brief isValidFilepath   Tests if the given filepath is accessable.
 * @param filePath          The filepath that has to be tested.
 *
 * Returns the informations, if the file is at the moment accesable.
 */
bool isValidFilepath(const string filePath) {
    ifstream myFile(filePath);
    if(myFile.is_open())
        return true;
    else
        return false;
}
