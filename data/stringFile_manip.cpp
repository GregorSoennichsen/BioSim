/*
 * stringFile_manip.cpp
 *
 *  Created on: 26.09.2017
 *      Author: Gregor Soennichsen
 */

#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <vector>

#include "creaTypeManager.hpp"

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

    for(i=0; i < str.size(); i++)
        strnew += tolower(str[i]);

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



/**
 * @brief getFileLines      Procedure to read a file into a vector.
 * @param filePath          The filepath that contains the informations.
 *
 * Reads the informations of the file line by line into a vector. Throws errors if the file
 * could not be opened or read.
 */
vector<string> getFileLines(const string filePath) {

    vector<string> lines;
    string line;
    ifstream myFile(filePath);

    if(!myFile.is_open())
        throw runtime_error("creature types file could not be opened");

    while(getline(myFile, line)) {
        if(line != "") {
            lines.push_back(line);
        }
    }

    if(myFile.bad())
        throw runtime_error("creature types file could not be read");

    myFile.close();
    return lines;

}



/**
 * @brief split             Procedure to split a string into a vector.
 * @param str               The string that has to be splitted.
 * @param sep               A string that seperates parts of the string.
 *
 * Splits a string into a vector of strings by cutting at positions,
 * where the separator is found. Ocurring errors are printed on the
 * console.
 */
vector<string> split(const string str, const string sep) {

    vector<string> sepList;

    if(str == sep)
        return sepList;

    if(str.find(sep) == string::npos) {
        sepList.push_back(str);
        return sepList;
    }

    int start = 0;
    for(unsigned int i=0; i<str.size(); i++) {
        if(str.substr(i, sep.size()) == sep) {

            sepList.push_back(str.substr(start, i-start));
            if(start == 0)
                start = i+sep.size();
            else
                start = i+1;
        }
    }

    sepList.push_back(str.substr(start, str.size()-start));
    return sepList;
}
