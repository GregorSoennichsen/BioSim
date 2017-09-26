/*
 * creaturetypes.hpp
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef CREATURETYPES_H
#define CREATURETYPES_H

#include <string>
#include <set>
#include <vector>

using namespace std;



/**
 * @brief CreaTye           The basic representation of a creature type.
 *
 * This struct is the elementar component that represents a creature type.
 */
struct CreaTyp {

    string          name;
    unsigned int    strength, speed, lifetime;
    set<string>     properities;
    string          image;

};



/**
 * @brief CreatureTypes     Class to manage the creature types.
 *
 * In this class methods can be found to add, delete, access and initialize
 * all creature types. Internally a data structure saves all loaded informations.
 */
class CreatureTypes{

    public:

        CreatureTypes(const string fileName);
        void addType(CreaTyp type);
        void deleteType(const string name);
        CreaTyp getInformation(const string name);
        string getText();

    private:

        vector<CreaTyp> types;

};


#endif // CREATURETYPES_H
