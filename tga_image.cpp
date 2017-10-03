/*
 * tgaimage.cpp
 *
 *  Created on: 02.10.2017
 *      Author: Gregor Soennichsen
 */

#include <iostream>
#include <exception>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>

#include "tga_image.hpp"

using namespace std;



/**
 * @brief TgaImage::TgaImage                Constructor that loads a tga image.
 * @param fileName                          Location of the tga image that shall be loaded.
 *
 * This constructor is supposed to load a tga image and save the informations in an
 * internal data structure. The code is splitted into two sections:
 * 1. the 18 header bits are managed
 * 2. the pixel colors are read
 * Each process is outsourced into a static method that reads the informations into
 * a dynamically allocated struct (header informations) and a static two-dimensional
 * array (the pixel colors).
 * All meta data following the pixel colors are ignored.
 *
 * There is just a specific tga format supported:
 * - there may not be an image ID or an colormap
 * - x- and yOrigin have to be each 0
 * - only 24- and 32-bits per pixel are accepted
 *
 * Not supposed tga formats and errors ocurring while reading throw corresponding
 * exceptions.
 */
TgaImage::TgaImage(string filePath) {

    ifstream myFile(filePath);

    if(!myFile.is_open())
        throw runtime_error("file could not be opened");

    header = readTGAHeader(&myFile);

    if(myFile.bad())
        throw runtime_error("tga header could not be read");

    if(header->imageIDlength!=0  || header->colormapType!=0    || header->colormapBegin!=0 ||
       header->colormapLength!=0 || header->imageType!=2       || header->xOrigin!=0 ||
       header->yOrigin!=0        || !(header->bitsPerPoint==24 || header->bitsPerPoint==32))
    {
        myFile.close();
        throw runtime_error("image format is not supported");
    }

    // Since only TGA-files with no Image-ID and no Pallette are supported,
    // here immediatly the image data can be read.

    pixels = readTGAPixels(&myFile, header);

    if(myFile.bad())
        throw runtime_error("tga pixel could not be read");

    myFile.close();
}



/**
 * @brief TgaImage::~TgaImage               Destructor clearing allocated memory.
 *
 * The destructor simple clears the dynamic arrays storing the pixel colors and
 * the tga header.
 */
TgaImage::~TgaImage() {

    for(uint16_t h=0; h<header->height; h++)
        delete[] pixels[h];
    delete[] pixels;

    delete header;

}



/**
 * @brief TgaImage::readTGAHeader           Interprets the first 18 bytes of a tga image.
 * @param myFile                            The stream to read the informations from.
 *
 * This static method reads the first 18 bytes of a stream and returns the interpreted
 * informations as a tgaHeader struct.
 */
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



/**
 * @brief TgaImage::readTGAPixels           Interprets the pixel colors of a tga image.
 * @param myFile                            The stream to read the informations from.
 * @param header                            Tga header containing data to read the pixel data.
 *
 * This static method reads the pixel colors following the first 18 bytes, the image ID and
 * the colormap. Note that image ID and colormap are supposed to be not existent.
 * Size and kind of the pixel colors are determined in the passed header, the informations
 * are returned as a pointer on a two-dimensional array of vectors.
 */
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



/**
 * @brief TgaImage::readTGAPixels           Prints the header informations of the loaded tga image..
 *
 * Gives a brief overview over all options stored in the tga header.
 */
void TgaImage::printTGAHeader() {


    cout << "--------" << endl;
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
    cout << "--------" << endl;

}
