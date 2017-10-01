/*
 * tgaloader.cpp
 *
 *  Created on: 26.09.2017
 *      Author: Gregor Soennichsen
 */

#include <string>
#include <fstream>
#include <iostream>

#include "tgaloader.hpp"
#include "helpfunctions.hpp"

using namespace std;



void loadTGA(string filePath) {

    ifstream myFile(filePath);

    struct tgaHeader header = readTGAHeader(&myFile);
    printTGAHeader(&header);

    if(header.imageIDlength!=0 || header.colormapType!=0 || header.colormapBegin!=0 ||
       header.colormapLength!=0 || header.imageType!=2        || header.xOrigin!=0 ||
       header.yOrigin!=0       || !(header.bitsPerPoint==24 || header.bitsPerPoint==32))
    {
        cout << "Image format is not supported." << endl;
        myFile.close();
        return;
    }

    // Since only TGA-files with no Image-ID and no Pallette are supported,
    // here immediatly the image data can be read.

    unsigned short bytesPerPoint = header.bitsPerPoint / 8;
    unsigned long long imSize    = ((long long) header.width) * header.height * bytesPerPoint;

    unsigned char *imData = new unsigned char[imSize];
    myFile.read((char *) imData, imSize);
    delete[] imData;

    // Further Meta-Data following the image data are ignored.

    myFile.close();
}



struct tgaHeader readTGAHeader(ifstream *myFile) {

    struct tgaHeader header;

    myFile->read((char *) &header.imageIDlength, sizeof(unsigned char));
    myFile->read((char *) &header.colormapType, sizeof(unsigned char));
    myFile->read((char *) &header.imageType, sizeof(unsigned char));

    myFile->read((char *) &header.colormapBegin, sizeof(short int));
    myFile->read((char *) &header.colormapLength, sizeof(short int));

    myFile->read((char *) &header.sizeOfEntryInPallette, sizeof(unsigned char));

    myFile->read((char *) &header.xOrigin, sizeof(short int));
    myFile->read((char *) &header.yOrigin, sizeof(short int));
    myFile->read((char *) &header.width, sizeof(short int));
    myFile->read((char *) &header.height, sizeof(short int));

    myFile->read((char *) &header.bitsPerPoint, sizeof(unsigned char));
    myFile->read((char *) &header.attributeByte, sizeof(unsigned char));

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
