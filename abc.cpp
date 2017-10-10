#include <cstdint>
#include <fstream>
#include <exception>
#include <vector>

using namespace std;


vector<uint8_t> *readTGA(string filePath);


int main() {

    vector<uint8_t> *image = readTGA("sand.tga");

}



vector<uint8_t> *readTGA(string filePath) {

    ifstream myFile(filePath);

    if(!myFile.is_open()) {
        myFile.close();
        throw runtime_error("file could not be opened");
    }


    // Read Header

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

    if(myFile.bad()) {
        myFile.close();
        throw runtime_error("tga header could not be read");
    }


    // Test if Format is supported

    if(header->imageIDlength != 0   ||
       header->colormapType != 0    || header->colormapBegin != 0 || header->colormapLength != 0 ||
       header->imageType != 2       || header->xOrigin != 0       || header->yOrigin != 0        ||
       !(header->bitsPerPoint == 24 || header->bitsPerPoint == 32))
    {
        myFile.close();
        throw runtime_error("image format is not supported");
    }


    // Since only TGA-files with no Image-ID and no Colormap are supported,
    // here immediatly the image data can be read.

    uint16_t bytesPerPoint    = header->bitsPerPoint / 8;
    unsigned long long imSize = static_cast<long long> (header->width) * header->height * bytesPerPoint;

    vector<uint8_t> * pixels = new vector<uint8_t> (imSize);
    myFile->read((char *) pixels->data(), imSize);


    unsigned long long i;
    for(i=0; i < imSize; i+=3) {

        uint8_t t0 = pixels->at(i+0);       // swap from BGR to RGB
        uint8_t t1 = pixels->at(i+1);
        uint8_t t2 = pixels->at(i+2);

        (*pixels)[i+0] = t2;
        (*pixels)[i+1] = t1;
        (*pixels)[i+2] = t0;

    }

    if(myFile.bad()) {
        myFile.close();
        throw runtime_error("tga pixel could not be read");
    }


    // Further Meta-Data following the image data are ignored.

    myFile.close();

}
