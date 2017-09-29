/*
 * extractdata.h
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H

#include <string>

using namespace std;



/**
 * @brief stringTOlower     Turns all uppercase chars to lowercase chars.
 * @param str               The string that has to be manipulated.
 *
 * Generates a new string, that contains all characters of the input string
 * in lowercase.
 */
string stringTOlower(const string str);



/**
 * @brief isValidFilepath   Tests if the given filepath is accessable.
 * @param filePath          The filepath that has to be tested.
 *
 * Returns the informations, if the file is at the moment accesable.
 */
bool isValidFilepath(const string filePath);

#endif // HELPFUNCTIONS_H
