/*
 * tgaloader.cpp
 *
 *  Created on: 26.09.2017
 *      Author: Gregor Soennichsen
 */

#include <string>
#include <stdio.h>
#include <iostream>

#include "tgaloader.hpp"
#include "helpfunctions.hpp"

using namespace std;



void loadTGA(string filePath) {

    FILE *myFile = fopen(filePath.c_str(), "rb");

    struct tgaHeader header = readTGAHeader(myFile);
    printTGAHeader(&header);

    if(header.imageIDlength!=0 || header.colormapType!=0 || header.colormapBegin!=0 ||
       header.colormapLength!=0 || header.imageType!=2        || header.xOrigin!=0 ||
       header.yOrigin!=0       || !(header.bitsPerPoint==24 || header.bitsPerPoint==32))
    {
        cout << "Image format is not supported." << endl;
        fclose(myFile);
        return;
    }

    // Since only TGA-files with no Image-ID and no Pallette are supported,
    // here immediatly the image data can be read.

    unsigned short bytesPerPoint = header.bitsPerPoint / 8;
    unsigned long long imSize    = ((long long) header.width) * header.height * bytesPerPoint;

    unsigned char *imData = new unsigned char[imSize];
    fread(imData, sizeof(char), 1, myFile);
    delete[] imData;

    // Further Meta-Data following the image data are ignored.

    fclose(myFile);
}



struct tgaHeader readTGAHeader(FILE *myFile) {

    struct tgaHeader header;

    fread(&header.imageIDlength, sizeof(unsigned char), 1, myFile);
    fread(&header.colormapType, sizeof(unsigned char), 1, myFile);
    fread(&header.imageType, sizeof(unsigned char), 1, myFile);
    fread(&header.colormapBegin, sizeof(short int), 1, myFile);
    fread(&header.colormapLength, sizeof(short int), 1, myFile);
    fread(&header.sizeOfEntryInPallette, sizeof(unsigned char), 1, myFile);
    fread(&header.xOrigin, sizeof(short int), 1, myFile);
    fread(&header.yOrigin, sizeof(short int), 1, myFile);
    fread(&header.width, sizeof(short int), 1, myFile);
    fread(&header.height, sizeof(short int), 1, myFile);
    fread(&header.bitsPerPoint, sizeof(unsigned char), 1, myFile);
    fread(&header.attributeByte, sizeof(unsigned char), 1, myFile);

    return header;

}



void printTGAHeader(struct tgaHeader *header) {

    cout << "Image-ID length:\t" << (short int) header->imageIDlength << endl;
    cout << "Color-Pallete type:\t" << (short int) header->colormapType << endl;
    cout << "Imagetype:\t\t" << (short int) header->imageType << endl;
    cout << "Pallette-Begin:\t\t" << header->colormapBegin << endl;
    cout << "Pallette-Length:\t" << header->colormapLength << endl;
    cout << "Size of an entry\nin the pallette:\t" << (short int) header->sizeOfEntryInPallette << endl;
    cout << "x-Origin:\t\t" << header->xOrigin << endl;
    cout << "y-Origin:\t\t" << header->yOrigin << endl;
    cout << "Image width:\t\t" << header->width << endl;
    cout << "Image height:\t\t" << header->height << endl;
    cout << "Bits per point:\t\t" << (short int) header->bitsPerPoint << endl;

}
