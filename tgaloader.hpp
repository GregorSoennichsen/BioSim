/*
 * tgaloader.hpp
 *
 *  Created on: 26.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef TGALOADER_HPP
#define TGALOADER_HPP

#include <string>

using namespace std;



struct tgaHeader {

    unsigned char imageIDlength;
    unsigned char colormapType;
    unsigned char imageType;
    short int colormapBegin;
    short int colormapLength;
    unsigned char sizeOfEntryInPallette;
    short int xOrigin;
    short int yOrigin;
    short int width;
    short int height;
    unsigned char bitsPerPoint;
    unsigned char attributeByte;

};

void loadTGA(string filePath);
struct tgaHeader readTGAHeader(FILE *myFile);
void printTGAHeader(struct tgaHeader *header);


#endif // TGALOADER_HPP
