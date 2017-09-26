/*
 * extractdata.h
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef EXTRACTDATA_H
#define EXTRACTDATA_H

#include <string>
#include <vector>

using namespace std;


vector<string> getFileLines(const string fileName);
vector<string> split(const string str, const string sep);


#endif // EXTRACTDATA_H
