#include <string>
#include <vector>
#include <map>
#include <tuple>

#include "../data/tga_image.hpp"
#include "../data/creaTypeManager.hpp"

#include "tileManager.hpp"



TileManager::TileManager(unsigned int tile_h,  unsigned int tile_w,  unsigned int field_h, unsigned int field_w, vector<CreaType> *creatureTypeInfos) :

    tile_height(tile_h), tile_width(tile_w), field_height(field_h), field_width(field_w)
{
    loadCreatureImages(creatureTypeInfos);
    loadTerrainImages();

    unsigned int numberOfTiles_Y = field_h / tile_h;
    unsigned int numberOfTiles_X = field_w / tile_w;

    field.resize(numberOfTiles_Y);
    unsigned int i;
    for(i=0; i<field.size(); i++)
        field[i].resize(numberOfTiles_X);

}



TileManager::~TileManager() {

    unsigned int i;

    for(i=0; i < creatureImages.size(); i++)
        delete creatureImages[i].image;

    for(i=0; i < terrainImages.size(); i++)
        delete terrainImages[i].image;
}



void TileManager::loadCreatureImages(vector<CreaType> *creatureTypeInfos) {

    unsigned int i;
    for(i=0; i < creatureTypeInfos->size(); i++) {

        CreatureImage im;

        im.creature = creatureTypeInfos->at(i).name;
        im.image    = new TgaImage("ressources/creature_tiles/" + creatureTypeInfos->at(i).image);

        creatureImages.push_back(im);

    }
}



void TileManager::loadTerrainImages() {

    string terrainNames[6] = { "deep_sea", "earth", "rocks", "sand", "shallow_water", "snow" };

    unsigned short i;

    for(i=0; i < 6; i++) {

        TerrainImage im;

        im.terrain = terrainNames[i];
        im.image   = new TgaImage("ressources/terrain/" + terrainNames[i] + ".tga");

        terrainImages.push_back(im);

    }
}
