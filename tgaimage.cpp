/*
 * tgaimage.cpp
 *
 *  Created on: 02.10.2017
 *      Author: Gregor Soennichsen
 */

#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "tgaimage.hpp"

using namespace std;


TgaImage::TgaImage(string filePath) {

    ifstream myFile(filePath);

    header = readTGAHeader(&myFile);

    if(header->imageIDlength!=0  || header->colormapType!=0    || header->colormapBegin!=0 ||
       header->colormapLength!=0 || header->imageType!=2       || header->xOrigin!=0 ||
       header->yOrigin!=0        || !(header->bitsPerPoint==24 || header->bitsPerPoint==32))
    {
        cout << "Image format is not supported." << endl;
        myFile.close();
        return;
    }

    // Since only TGA-files with no Image-ID and no Pallette are supported,
    // here immediatly the image data can be read.

    pixels = readTGAPixels(&myFile, header);

}



TgaImage::~TgaImage() {

    for(uint16_t h=0; h<header->height; h++)
        delete[] pixels[h];
    delete[] pixels;

    delete header;

}



struct tgaHeader * TgaImage::readTGAHeader(ifstream *myFile) {

    struct tgaHeader *header = new struct tgaHeader;

    myFile->read((char *) &header->imageIDlength, 1);
    myFile->read((char *) &header->colormapType, 1);
    myFile->read((char *) &header->imageType, 1);

    myFile->read((char *) &header->colormapBegin, 2);
    myFile->read((char *) &header->colormapLength, 2);

    myFile->read((char *) &header->sizeOfEntryInPallette, 1);

    myFile->read((char *) &header->xOrigin, 2);
    myFile->read((char *) &header->yOrigin, 2);
    myFile->read((char *) &header->width, 2);
    myFile->read((char *) &header->height, 2);

    myFile->read((char *) &header->bitsPerPoint, 1);
    myFile->read((char *) &header->attributeByte, 1);

    return header;

}



vector<uint8_t> **TgaImage::readTGAPixels(ifstream *myFile, tgaHeader *header) {

    uint16_t bytesPerPoint = header->bitsPerPoint / 8;
    unsigned long long imSize = ((long long) header->width) * header->height * bytesPerPoint;

    uint8_t *imRawData = new uint8_t[imSize];
    myFile->read((char *) imRawData, imSize);

    // In TGA-images the origin is in the lower-right corner and the image has to
    // be processed row by row from the bottom to the top. Here, pixel are stored,
    // that the origin is in the lower-left corner.

    vector<uint8_t> **imData = new vector<uint8_t> *[header->height];
    for(uint16_t h=0; h<header->height; h++)
        imData[h] = new vector<uint8_t>[header->width];
    //vector<uint8_t> imData[header.height][header.width];

    uint16_t h=0, w=0;
    unsigned long long i;
    for(i=0; i<imSize; i+=bytesPerPoint) {

        vector<uint8_t> pixel;

        uint8_t offset;
        for(offset=0; offset<bytesPerPoint; offset++) {         // Depending on either 24- or 32-Bits per pixel,
            pixel.push_back(imRawData[i+offset]);               // 3 or 4 bytes are read into the vector, which
        }                                                       // represents the colors of a pixel.

        imData[h][(header->width-1)-w] = pixel;

        w++;
        if(w == header->width) {
            w = 0;
            h++;
        }
    }


    delete[] imRawData;

    // Further Meta-Data following the image data are ignored.

    myFile->close();

    return imData;
}



void TgaImage::printTGAHeader() {

    cout << "Image-ID length:\t"    << (short) header->imageIDlength << endl;
    cout << "Color-Pallete type:\t" << (short) header->colormapType << endl;
    cout << "Imagetype:\t\t"        << (short) header->imageType << endl;
    cout << "Pallette-Begin:\t\t"   << header->colormapBegin << endl;
    cout << "Pallette-Length:\t"    << header->colormapLength << endl;
    cout << "Size of colormap-entry:\t"<< (short) header->sizeOfEntryInPallette << endl;
    cout << "x-Origin:\t\t"         << header->xOrigin << endl;
    cout << "y-Origin:\t\t"         << header->yOrigin << endl;
    cout << "Image width:\t\t"      << header->width << endl;
    cout << "Image height:\t\t"     << header->height << endl;
    cout << "Bits per point:\t\t"   << (short) header->bitsPerPoint << endl;

}
