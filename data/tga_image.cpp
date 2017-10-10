/*
 * tga_image.cpp
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
 * @param filePath                          Location of the tga image that shall be loaded.
 *
 * This constructor is supposed to load a tga image and save the informations in an
 * internal data structure. The code is splitted into two sections:
 * 1. the 18 header bits are managed
 * 2. the pixel colors are read
 * Each process is outsourced into a static method that reads the informations into
 * a dynamically allocated struct (header informations) and a vector of bytes
 * (the pixel colors).
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

    // ****************** LOG ****************************
    cout << "--------" << endl;
    cout << "Read TGA Image from: " << filePath << endl;
    // ***************************************************

    ifstream myFile(filePath);

    if(!myFile.is_open()) {
        myFile.close();
        throw runtime_error("file could not be opened");
    }

    header = readHeader(&myFile);

    if(myFile.bad()) {
        myFile.close();
        throw runtime_error("tga header could not be read");
    }

    if(header->imageIDlength != 0   ||
       header->colormapType != 0    || header->colormapBegin != 0 || header->colormapLength != 0 ||
       header->imageType != 2       || header->xOrigin != 0       || header->yOrigin != 0        ||
       !(header->bitsPerPoint == 24 || header->bitsPerPoint == 32))
    {
        myFile.close();
        throw runtime_error("image format is not supported");
    }

    // Since only TGA-files with no Image-ID and no Pallette are supported,
    // here immediatly the image data can be read.

    pixels = readPixels(&myFile, header);

    if(myFile.bad()) {
        myFile.close();
        throw runtime_error("tga pixel could not be read");
    }

    // Further Meta-Data following the image data are ignored.

    myFile.close();

    // ****************** LOG ****************************
    cout << "Read successfully read TGA Image" << endl;
    cout << "--------" << endl << endl;
    // ***************************************************

}



/**
 * @brief TgaImage::~TgaImage               Destructor clearing allocated memory.
 *
 * The destructor simple clears the dynamic arrays storing the pixel colors and
 * the tga header.
 */
TgaImage::~TgaImage() {

    delete pixels;
    delete header;

}



/**
 * @brief TgaImage::getPixels               Returns a pointer to the pixel data.
 *
 * Returns a pointer to the pixel data, stored in an vector.
 */
vector<uint8_t> *TgaImage::getPixels() {

    return pixels;

}



/**
 * @brief TgaImage::getHeader               Returns a pointer to the tga header.
 *
 * Returns a pointer to the tga header informations.
 */
tgaHeader *TgaImage::getHeader() {

    return header;

}



/**
 * @brief TgaImage::readHeader              Interprets the first 18 bytes of a tga image.
 * @param myFile                            The stream to read the informations from.
 *
 * This static method reads the first 18 bytes of a stream and returns the interpreted
 * informations as a tgaHeader struct.
 */
struct tgaHeader *TgaImage::readHeader(ifstream *myFile) {

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
 * @brief TgaImage::readPixels              Interprets the pixel colors of a tga image.
 * @param myFile                            The stream to read the informations from.
 * @param header                            Tga header containing data to read the pixel data.
 *
 * This static method reads the pixel colors following the first 18 bytes, the image ID and
 * the colormap. Note that image ID and colormap are supposed to be not existent.
 * Size and kind of the pixel colors are determined in the passed header, the informations
 * are returned as a pointer on a vector of bytes. The image data are stored 32-Bit aligned,
 * meaning a pixel has always 32 bit, even if there is originally no alpha channel.
 */
vector<uint8_t> *TgaImage::readPixels(ifstream *myFile, tgaHeader *header) {

    uint16_t bytesPerPoint = header->bitsPerPoint / 8;
    unsigned long long imSize         = static_cast<long long> (header->width) * header->height * bytesPerPoint;
    unsigned long long numberOfPixels = static_cast<long long> (header->width) * header->height;

    //
//    cout << "bpp: "     << bytesPerPoint << endl;
//    cout << "w x h: "   << header->width << " x " << header->height << endl;
//    cout << "imSize: "  << imSize << endl;
//    cout << "nPixels: " << numberOfPixels << endl;
//    logHeader(header);
    //


    vector<uint8_t> * imRawData = new vector<uint8_t> (imSize);
    myFile->read((char *) imRawData->data(), imSize);


    if(bytesPerPoint == 3) {

        unsigned long long i;
        for(i=0; i < imSize; i+=3) {

            uint8_t t0 = imRawData->at(i+0);
            uint8_t t1 = imRawData->at(i+1);
            uint8_t t2 = imRawData->at(i+2);


//            //
//            cout << (i/3)/32 << " " << (i/3)%32 << " : " << (unsigned short) t2
//                 << " " << (unsigned short) t1 << " " << (unsigned short) t0 << endl;
//            //


            (*imRawData)[i+0] = t2;
            (*imRawData)[i+1] = t1;
            (*imRawData)[i+2] = t0;

        }
        return imRawData;
    }

    else if(bytesPerPoint == 4)
        return imRawData;

    else
        throw runtime_error("format not supported");
}
