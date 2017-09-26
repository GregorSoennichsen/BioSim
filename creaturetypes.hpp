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


struct CreaTyp {

    string          name;
    unsigned int    strength, speed, lifetime;
    set<string>     properities;
    string          image;

};

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
