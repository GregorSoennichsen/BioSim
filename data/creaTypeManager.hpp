/*
 * creaturetypes.hpp
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef CREATYPEMANAGER_HPP
#define CREATYPEMANAGER_HPP

#include <string>
#include <vector>
#include <set>

using namespace std;



/**
 * @brief CreaType          The basic representation of a creature type.
 *
 * This struct is the elementar component that represents a creature type.
 */
struct CreaType {

    string          name;
    unsigned int    strength, speed, lifetime;
    set<string>     properities;
    string          image;

};



/**
 * @brief CreaTypeManager    Class to manage the creature types.
 *
 * In this class, methods can be found to add, delete, access and initialize
 * all creature types. Internally a data structure saves all loaded informations.
 */
class CreaTypeManager{

    public:

        explicit CreaTypeManager(const string filePath);
        ~CreaTypeManager();

        void addType(CreaType type);
        void deleteType(const string name);
        vector<string> getTypeNames();
        CreaType getTypeInfo(const string name);
        string getText();

    private:

        CreaTypeManager(const CreaTypeManager &s);
        CreaTypeManager& operator=(const CreaTypeManager &s);

        vector<CreaType> *types;

};


#endif // CREATYPEMANAGER_HPP
