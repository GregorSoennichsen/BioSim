/*
 * extractdata.h
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef STRINGFILE_MANIP_HPP
#define STRINGFILE_MANIP_HPP

#include <string>
#include <vector>

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



/**
 * @brief getFileLines      Procedure to read a file into a vector.
 * @param filePath          The filepath that contains the informations.
 *
 * Reads the informations of the file line by line into a vector. Throws errors if the file
 * could not be opened or read.
 */
vector<string> getFileLines(const string filePath);



/**
 * @brief split             Procedure to split a string into a vector.
 * @param str               The string that has to be splitted.
 * @param sep               A string that seperates parts of the string.
 *
 * Splits a string into a vector of strings by cutting at positions,
 * where the separator is found. Ocurring errors are printed on the
 * console.
 */
vector<string> split(const string str, const string sep);



#endif // STRINGFILE_MANIP_HPP
