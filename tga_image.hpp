/*
 * tgaimage.hpp
 *
 *  Created on: 02.10.2017
 *      Author: Gregor Soennichsen
 */

#ifndef TGA_IMAGE_HPP
#define TGA_IMAGE_HPP

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;



/**
 * @brief tgaHeader       The representation of a tga header.
 *
 * This struct is meant to save meta-data of specific tga images.
 */
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



/**
 * @brief TgaImage       Class to manage tga images.
 *
 * This class offers the possibility to load a tga image into
 * the main memory.
 */
class TgaImage {

    public:

        TgaImage(string filePath);
        ~TgaImage();

        void printTGAHeader();

    private:

        static struct tgaHeader * readTGAHeader(ifstream *myFile);
        static vector<uint8_t> **readTGAPixels(ifstream *myFile, tgaHeader *header);

        tgaHeader * header;
        vector<uint8_t> **pixels;

};



#endif // TGA_IMAGE_HPP
