/*
 * tgaimage.hpp
 *
 *  Created on: 02.10.2017
 *      Author: Gregor Soennichsen
 */

#ifndef TGAIMAGE_HPP
#define TGAIMAGE_HPP

#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

using namespace std;



struct tgaHeader {

    uint8_t imageIDlength;
    uint8_t colormapType;
    uint8_t imageType;
    uint16_t colormapBegin;
    uint16_t colormapLength;
    uint8_t  sizeOfEntryInPallette;
    uint16_t xOrigin;
    uint16_t yOrigin;
    uint16_t width;
    uint16_t height;
    uint8_t bitsPerPoint;
    uint8_t attributeByte;

};


class TgaImage {

    public:

        TgaImage(string filePath);
        ~TgaImage();

        static struct tgaHeader * readTGAHeader(ifstream *myFile);
        static vector<uint8_t> **readTGAPixels(ifstream *myFile, tgaHeader *header);

        void printTGAHeader();

    private:

        tgaHeader * header;
        vector<uint8_t> **pixels;

};



#endif // TGAIMAGE_HPP
