/*
 * creaturetypes.hpp
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef CREATURE_TYPES_HPP
#define CREATURE_TYPES_HPP

#include <string>
#include <vector>
#include <set>

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
 * In this class, methods can be found to add, delete, access and initialize
 * all creature types. Internally a data structure saves all loaded informations.
 */
class CreatureTypes{

    public:

        explicit CreatureTypes(const string fileName);
        ~CreatureTypes();

        void addType(CreaTyp type);
        void deleteType(const string name);
        CreaTyp getInformation(const string name);
        string getText();

    private:

        CreatureTypes(const CreatureTypes &s);
        CreatureTypes& operator=(const CreatureTypes &s);

        vector<CreaTyp> *types;

};


#endif // CREATURE_TYPES_HPP
