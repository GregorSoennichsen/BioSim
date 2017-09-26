/*
 * extractdata.h
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H

#include <string>
#include <fstream>

using namespace std;


string stringTOlower(const string str) {
    string strnew;
    unsigned int i;
    for(i=0; i<str.size(); i++) {
        strnew += tolower(str[i]);
    }
    return strnew;
}


bool isValidFilepath(const string filePath) {
    ifstream myFile(filePath);
    if(myFile.is_open())
        return true;
    else
        return false;
}

#endif // HELPFUNCTIONS_H
