/*
 * tga_image.hpp
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

    uint8_t   imageIDlength;
    uint8_t   colormapType;
    uint8_t   imageType;
    uint16_t  colormapBegin;
    uint16_t  colormapLength;
    uint8_t   sizeOfEntryInPallette;
    uint16_t  xOrigin;
    uint16_t  yOrigin;
    uint16_t  width;
    uint16_t  height;
    uint8_t   bitsPerPoint;
    uint8_t   attributeByte;

};



/**
 * @brief TgaImage       Class to manage tga images.
 *
 * This class offers the possibility to load a tga image into
 * the main memory.
 */
class TgaImage {

    public:

        explicit TgaImage(string filePath);
        ~TgaImage();

        vector<uint8_t> *getPixels();
        tgaHeader *getHeader();

        static inline void logHeader(tgaHeader *header) {

            cout << "imageIDlength:\t\t"        << (unsigned short) header->imageIDlength << endl;
            cout << "colormapType:\t\t"         << (unsigned short) header->colormapType << endl;
            cout << "imageType:\t\t"            << (unsigned short) header->imageType << endl;
            cout << "colormapBegin:\t\t"        << (unsigned short) header->colormapBegin << endl;
            cout << "colormapLength:\t\t"       << (unsigned short) header->colormapLength << endl;
            cout << "sizeOfEntryInPallette:\t"  << (unsigned short) header->sizeOfEntryInPallette << endl;
            cout << "xOrigin:\t\t\t"            << (unsigned short) header->xOrigin << endl;
            cout << "yOrigin:\t\t\t"            << (unsigned short) header->yOrigin << endl;
            cout << "width:\t\t\t"              << (unsigned short) header->width << endl;
            cout << "height:\t\t\t"             << (unsigned short) header->height << endl;
            cout << "bitsPerPoint:\t\t"         << (unsigned short) header->bitsPerPoint << endl;
            cout << "attributeByte:\t\t"        << (unsigned short) header->attributeByte << endl << endl;

        }

    private:

        TgaImage(const TgaImage& s);
        TgaImage& operator=(const TgaImage& s);

        static struct tgaHeader *readHeader(ifstream *myFile);
        static vector<uint8_t>  *readPixels(ifstream *myFile, tgaHeader *header);

        tgaHeader *header;
        vector<uint8_t> *pixels;

};



#endif // TGA_IMAGE_HPP
