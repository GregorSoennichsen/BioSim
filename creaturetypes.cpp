/*
 * creaturetypes.cpp
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#include <iostream>
#include <string>
#include <set>
#include <exception>

#include "helpfunctions.hpp"
#include "creaturetypes.hpp"
#include "extractdata.hpp"

using namespace std;



/**
 * @brief CreatureTypes::CreatureTypes      Constructor to initialize all creature types from one file.
 * @param fileName                          Filepath to load the creature types from.
 *
 * The constructor loads all informations line by line from the specified file, where one line
 * represents one creature type. Every line is splitted by commatas and all entrys in the
 * resulting vector are interpreted particular.
 *
 * If an error is found in a line, a log is printed on the console and the actual line will
 * be skipped. Extracted creature types are saved in the internal data structure.
 *
 * In the end a short output containing some statistical informations is printed on the console.
 */
CreatureTypes::CreatureTypes(const string fileName) {

    unsigned int STATUS_READ_LINES = 0;
    unsigned int STATUS_NUMBER_OF_LINES;

    vector<string> data = getFileLines(fileName);
    STATUS_NUMBER_OF_LINES = data.size();

    unsigned int i;
    for(i=0; i<data.size(); i++) {

        vector<string> line = split(data[i], ",");

        if(line.size() != 6) {
            cout << "line " << i+1 << ": no valid number of arguments in the line" << endl;
            continue;
        }
        CreaTyp type;

        // get the creature type's name

        type.name = stringTOlower(line[0]);
        if(type.name == "") {
            cout << "line " << i+1 << ": name may not be empty" << endl;
            continue;
        }
        if(type.name.find_first_not_of("abcdefghijklmnopqrstuvwxyz ") != string::npos) {
            cout << "line " << i+1 << ": name has to contain only whitespaces and alphabetic characters" << endl;
            continue;
        }

        // get the creature type's strength, speed and lifetime

        try {
            if(line[1].find_first_not_of("0123456789") != string::npos ||
               line[2].find_first_not_of("0123456789") != string::npos ||
               line[3].find_first_not_of("0123456789") != string::npos)
                throw invalid_argument("");

            int t1 = stoi(line[1]);
            int t2 = stoi(line[2]);
            int t3 = stoi(line[3]);

            if(t1 < 0 || t2 < 0 || t3 < 0)
                throw invalid_argument("");

            type.strength = t1;
            type.speed =    t2;
            type.lifetime = t3;
        }
        catch (const invalid_argument& e) {
            cout << "line " << i+1 << ": strength-, speed- or lifetime-number was no positive integer" << endl;
            continue;
        }
        catch (const out_of_range& e) {
            cout << "line " << i+1 << ": strength-, speed- or lifetime-number was out of the range of an integer" << endl;
            continue;
        }

        // get the creature type's properities

        vector<string> props_data = split(line[4]," ");
        set<string> props;

        bool _break = false;
        unsigned int j;
        for(j=0; j<props_data.size(); j++) {
            string t = stringTOlower(props_data[j]);
            if(t.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos) {
                cout << "line " << i+1 << ": a single properity has to contain (only) alphabetic characters" << endl;
                _break = true;
                break;
            }
            props.insert(t);
        }
        if(props_data.empty()) {
            type.properities = props;
            _break = false;
        }
        if(_break)
            continue;
        type.properities = props;

        // get the creature type's image-filepath

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
    cout << "--------" << endl << endl;

}



/**
 * @brief CreatureTypes::addType            Method to add a type to the data structure.
 * @param type                              The creature type that has to be added.
 *
 * Simply adds a new entry.
 */
void CreatureTypes::addType(CreaTyp type) {

    types.push_back(type);
}



/**
 * @brief CreatureTypes::deleteType         Method to delete a creature type from the data structure.
 * @param name                              The creature type that has to be deleted.
 *
 * Simply deletes the specified creaturetype. Throws an error, if the name was not found.
 */
void CreatureTypes::deleteType(const string name) {

    unsigned int i;
    for(i=0; i<types.size(); i++) {
        if(types[i].name == name) {
            types.erase(types.begin()+i);
            return;
        }
    }
    throw runtime_error("name of creature type not found");
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
    throw runtime_error("name of creature type not found");
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
        text += "Name:\t\t" +     types[i].name + "\n";
        text += "Strength:\t" + to_string(types[i].strength) + "\n";
        text += "Speed:\t\t" +    to_string(types[i].speed) + "\n";
        text += "Lifetime:\t" + to_string(types[i].lifetime) + "\n";
        text += "Image:\t\t" +    types[i].image;
        text += "\n\n";
    }
    return text;
}
