/*
 * creaturetypes.cpp
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#include <iostream>
#include <string>
#include <set>
#include <stdexcept>

#include "helpfunctions.hpp"
#include "creaturetypes.hpp"
#include "extractdata.hpp"

using namespace std;



/**
 * @brief CreatureTypes::CreatureTypes      Constructor to initialize all CreatureTypes from one file.
 * @param fileName                          Filepath to load the CreatureTypes from.
 *
 * The Constructor loads all informations line by line from the specified file, where one line
 * represents one CreatureType. If an error is found in a line, a log is printed on the console
 * and the actual line will be skipped. Extracted CreatureTypes are saved in the internal
 * data structure.
 */
CreatureTypes::CreatureTypes(const string fileName) {

    unsigned int STATUS_READ_LINES = 0;
    unsigned int STATUS_NUMBER_OF_LINES;

    vector<string> data = getFileLines(fileName);
    STATUS_NUMBER_OF_LINES = data.size();
    int t1, t2, t3;
    unsigned int i;
    for(i=0; i<data.size(); i++) {

        vector<string> line = split(data[i], ",");
        CreaTyp type;

        // get the Creatue Type's name

        type.name = stringTOlower(line[0]);
        if(type.name == "") {
            cout << "line " << i+1 << ": name may not be empty" << endl;
            continue;
        }
        if(type.name.find_first_of("abcdefghijklmnopqrstuvwxyz ") == string::npos) {
            cout << "line " << i+1 << ": name has to contain only whitespaces and alphabetic characters" << endl;
            continue;
        }

        // get the Creatue Type's strength, speed and lifetime

        try {
            t1 = stoi(line[1]);
            t2 = stoi(line[2]);
            t3 = stoi(line[3]);

            if(t1 < 0 || t2 < 0 || t3 < 0)
                throw invalid_argument("");

            type.strength = t1;
            type.speed =    t2;
            type.lifetime = t3;
        }
        catch (const invalid_argument& e) {
            cout << "line " << i+1 << ": strength-, speed- or lifetime-number was no positive number" << endl;
            continue;
        }
        catch (const out_of_range& e) {
            cout << "line " << i+1 << ": strength-, speed- or lifetime-number was out of the range of an integer" << endl;
            continue;
        }

        // get the Creatue Type's properities

        vector<string> props_data = split(line[4]," ");
        set<string> props;
        string t;
        bool _break = false;
        unsigned int i;
        for(i=0; i<props_data.size() && !_break; i++)
            t = stringTOlower(props_data[i]);
            if(t.find_first_of("abcdefghijklmnopqrstuvwxyz ") == string::npos) {
                cout << "line " << i+1 << ": a single properity has to contain only whitespaces and alphabetic characters" << endl;
                _break = true;
            }
            props.insert(t);
        type.properities = props;

        // get the Creatue Type's image-filepath

        type.image = line[5];
        if(!isValidFilepath("images/"+type.image)) {
            cout << "line " << i+1 << ": the filename is no valid filepath" << endl;
            continue;
        }

        addType(type);
        STATUS_READ_LINES++;
    }

    // some statistics
    cout << "--------" << endl;
    cout << "number of lines:\t\t"              << STATUS_NUMBER_OF_LINES << endl;
    cout << "successfull read operations:\t"    << STATUS_READ_LINES << endl;
    cout << "failed read operations:\t\t"       << STATUS_NUMBER_OF_LINES - STATUS_READ_LINES << endl;
    cout << "--------" << endl;

}



/**
 * @brief CreatureTypes::addType            Method to add a type to the data structure.
 * @param type                              The creature type that has to be added.
 *
 * Simply adds the new entry.
 */
void CreatureTypes::addType(CreaTyp type) {

    types.push_back(type);
}



/**
 * @brief CreatureTypes::deleteType         Method to delete a type from the data structure.
 * @param name                              The creature type that has to be deleted.
 *
 * Simply deletes the specified creature type. Throws an error, if the name was not found.
 */
void CreatureTypes::deleteType(const string name) {

    unsigned int i;
    for(i=0; i<types.size(); i++) {
        if(types[i].name == name) {
            types.erase(types.begin()+i);
            return;
        }
    }
    throw "name of creature type not found";
}



/**
 * @brief CreatureTypes::getInformation     Method to get the informations to a creature type.
 * @param name                              The informations to this creature type are returned.
 *
 * Returns a struct of type CreaType with informations. Throws an error, if the name was not found.
 */
CreaTyp CreatureTypes::getInformation(const string name) {

    unsigned int i;
    for(i=0; i<types.size(); i++) {
        if(types[i].name == name) {
            return types[i];
        }
    }
    throw "name of creature type not found";
}



/**
 * @brief CreatureTypes::getText            Method, that returns a status string about all creature types.
 *
 * Returns a string containing the names of all creature types saved in the data structure..
 */
string CreatureTypes::getText() {

    string text;
    unsigned int i;
    for(i=0; i<types.size(); i++) {
        text += types[i].name;
        if(i != types.size()-1)
            text += "\n";
    }
    return text;
}
