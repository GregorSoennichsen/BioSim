/*
 * main.cpp
 *
 *  Created on: 01.09.2017
 *      Author: Gregor Soennichsen
 */

#include <iostream>
#include <string>
#include <vector>

#include "creaturetypes.hpp"
#include "tgaimage.hpp"

using namespace std;


int main(int argc, char *argv[])
{
    if(argc < 2) {
        cout << "Not enough arguments to identify a filepath." << endl;
        return 0;
    }

    cout << argv[1] << endl; return 0;
    CreatureTypes creatureTypes(argv[1]);

    cout << endl;

    TgaImage tanne("images/land/tanne.tga");
    tanne.printTGAHeader();

    cout << endl;

    return 0;
}
