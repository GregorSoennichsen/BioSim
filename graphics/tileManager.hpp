#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include <string>
#include <vector>
#include <map>
#include <tuple>

#include "../data/tga_image.hpp"
#include "../data/creaTypeManager.hpp"

using namespace std;



struct TerrainImage {

    string terrain;
    TgaImage *image;
};



struct CreatureImage {

    string creature;
    TgaImage *image;
};


struct Tile {

    TerrainImage  *terrainImage;
    vector<CreatureImage> creatureImages;

};



class TileManager {

    public:

        TileManager(unsigned int tile_h,  unsigned int tile_w,
                    unsigned int field_h, unsigned int field_w,
                    vector<CreaType> *creatureTypeInfos);

        ~TileManager();

    private:

        // Handle Field

        unsigned int tile_height;
        unsigned int tile_width;

        unsigned int field_height;
        unsigned int field_width;

        vector<vector<Tile>> field;

        // Handle Images

        vector<CreatureImage> creatureImages;
        vector<TerrainImage>  terrainImages;

        void loadCreatureImages(vector<CreaType> *creatureTypeInfos);
        void loadTerrainImages();

};



#endif // TILEMANAGER_H
