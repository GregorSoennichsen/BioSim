/*
 * tgaloader.hpp
 *
 *  Created on: 26.09.2017
 *      Author: Gregor Soennichsen
 */

#ifndef TGALOADER_HPP
#define TGALOADER_HPP

#include <string>
#include <fstream>
#include <vector>


using namespace std;




typedef vector<uint8_t> pixelRGB;
typedef vector<uint8_t> pixelRGBA;



// TODO: Change types to standard-width uint types from "http://www.cplusplus.com/reference/cstdint/"
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

void loadTGA(string filePath);
struct tgaHeader readTGAHeader(ifstream *myFile);
void printTGAHeader(struct tgaHeader *header);


#endif // TGALOADER_HPP
