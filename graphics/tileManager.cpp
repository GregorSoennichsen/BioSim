#include <QImage>
#include <QOpenGLTexture>

#include <iostream>
#include <string>
#include <vector>

#include "../ressourcesloc.hpp"
#include "../data/creaTypeManager.hpp"

#include "tileManager.hpp"



TileManager::TileManager(unsigned int tile_h,  unsigned int tile_w,  unsigned int field_h, unsigned int field_w, vector<CreaType> *creatureTypeInfos) :

    tile_height(tile_h),
    tile_width(tile_w),

    field_height(field_h),
    field_width(field_w),

    numberOfTiles_Y(field_h / tile_h + 1),
    numberOfTiles_X(field_w / tile_w + 1),

    scroll_right(0.0),
    scroll_bottom(0.0),

    creatureTypeInfos(creatureTypeInfos)
{
}



void TileManager::init() {

    loadCreatureImages(creatureTypeInfos);
    loadTerrainImages();

    field.resize(numberOfTiles_Y);
    unsigned int i;
    for(i=0; i<field.size(); i++)
        field[i].resize(numberOfTiles_X);

    generateField();
}



TileManager::~TileManager() {

    unsigned int i;

    for(i=0; i < creatureImages.size(); i++) {
        delete creatureImages[i].tgaImage;
        delete creatureImages[i].texture;
    }

    for(i=0; i < terrainImages.size(); i++) {
        delete terrainImages[i].tgaImage;
        delete terrainImages[i].texture;
    }
}



Tile *TileManager::getTileAt(int x, int y) {
    return &(field[y][x]);
}



float TileManager::rasterTOopengl_X(int x, float p) {
    return ( (2 * (x * tile_width + p - scroll_right)) / static_cast<float> (field_width) ) - 1;
}



float TileManager::rasterTOopengl_Y(int y, float p) {
    return ( (2 * (y * tile_height + p - scroll_bottom)) / static_cast<float> (field_height) ) - 1;
}



void TileManager::multVertexData(float data[], float xLef, float xRig, float yTop, float yBot) {

    data[0] *= xLef;
    data[1] *= yTop;

    data[5] *= xLef;
    data[6] *= yBot;

    data[10] *= xRig;
    data[11] *= yBot;

    data[15] *= xRig;
    data[16] *= yTop;
}



void TileManager::generateField() {

    unsigned int y, x;
    for(y=0; y<numberOfTiles_Y; y++) {
        for(x=0; x<numberOfTiles_X; x++) {

            field[y][x].terrainImage = &(terrainImages[(x+y*y*x)%4]);

            multVertexData(field[y][x].quadData,
                           rasterTOopengl_Y(y,   1.0),
                           rasterTOopengl_Y(y+1, 0.0),
                           rasterTOopengl_X(x,   1.0),
                           rasterTOopengl_X(x+1, 0.0));

        }
    }
}



void TileManager::loadCreatureImages(vector<CreaType> *creatureTypeInfos) {

    unsigned int i;
    for(i=0; i < creatureTypeInfos->size(); i++) {

        CreatureImage im;

        im.creature = creatureTypeInfos->at(i).name;
        im.tgaImage = new TgaImage(RESSOURCESLOC + "creature_tiles/" + creatureTypeInfos->at(i).image);

        uchar *buf  = im.tgaImage->getPixels()->data();
        int w = (int) im.tgaImage->getHeader()->width;
        int h = (int) im.tgaImage->getHeader()->height;

        im.texture = new QOpenGLTexture( QImage(buf, w, h, QImage::Format_RGB888) );
        im.texture->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);

        creatureImages.push_back(im);

    }
}



void TileManager::loadTerrainImages() {         // "deep_sea", "sand",

    string terrainNames[6] = { "earth", "rocks", "shallow_water", "snow" };

    unsigned short i;

    for(i=0; i < 4; i++) {

        TerrainImage im;

        im.terrain  = terrainNames[i];
        im.tgaImage = new TgaImage(RESSOURCESLOC + "terrain/" + terrainNames[i] + ".tga");

        uchar *buf  = im.tgaImage->getPixels()->data();
        int w = (int) im.tgaImage->getHeader()->width;
        int h = (int) im.tgaImage->getHeader()->height;

        im.texture = new QOpenGLTexture( QImage(buf, w, h, QImage::Format_RGB888) );
        im.texture->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);

        terrainImages.push_back(im);

    }
}
