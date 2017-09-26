/*
 * extractdata.cpp
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "extractdata.hpp"

using namespace std;


vector<string> getFileLines(const string fileName) {

    vector<string> lines;
    string line;
    ifstream myFile(fileName);

    if(!myFile.is_open())
        throw "file could not be opened";

    while (getline(myFile, line)) {
        if(line != "") {
            lines.push_back(line);
        }
    }

    if(myFile.bad())
        throw "file could not be read";

    myFile.close();
    return lines;

}


vector<string> split(const string str, const string sep) {

    vector<string> sepList;

    if(str == sep) {
        cout << "input-string equals seperator" << endl;
        sepList.push_back(str);
        return sepList;
    }
    if(str.find(sep) == string::npos) {
        cout << "not a single seperator found in input-string" << endl;
        return sepList;
    }

    int start = 0;
    for(unsigned int i=0; i<str.size(); i++) {

        if( str.substr(i, sep.size()) == sep) {
            sepList.push_back(str.substr(start, i-start));
            if(start == 0) {
                start = i+sep.size();
            }
            else {
                start = i+1;
            }
        }
    }

    sepList.push_back(str.substr(start, str.size()-start));
    return sepList;
}
