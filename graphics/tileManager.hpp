#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include <QImage>
#include <QOpenGLTexture>

#include <string>
#include <vector>

#include "../data/tga_image.hpp"
#include "../data/creaTypeManager.hpp"

using namespace std;


// Image Types

struct TerrainImage {

    string terrain;
    TgaImage *tgaImage;
    QOpenGLTexture *texture;

};

struct CreatureImage {

    string creature;
    TgaImage *tgaImage;
    QOpenGLTexture *texture;
};



// Representation of a Tile

struct Tile {

    TerrainImage *terrainImage;
    vector<CreatureImage> creatureImages;
    float quadData[20] = {

         1, -1, -1,   0, 0,     // top left
         1, -1, -1,   1, 0,     // bottom left
         1, -1, -1,   1, 1,     // bottom right
         1, -1, -1,   0, 1      // top right

     };

};



class TileManager {

    public:

        TileManager(unsigned int tile_h,  unsigned int tile_w,
                    unsigned int field_h, unsigned int field_w,
                    vector<CreaType> *creatureTypeInfos);
        void init();

        ~TileManager();

        // Get-Methods

        Tile *getTileAt(int x, int y);
        unsigned int getFieldSize()     { return field_height * field_width; }
        unsigned int getNumberOfTiles() { return numberOfTiles_Y * numberOfTiles_X; }

        unsigned int getTileHeight() { return tile_height; }
        unsigned int getTileWidth()  { return tile_width;  }

        unsigned int getFieldHeight() { return field_height; }
        unsigned int getFieldWidth()  { return field_width;  }

        unsigned int getNumberOfTiles_Y() { return numberOfTiles_Y; }
        unsigned int getNumberOfTiles_X() { return numberOfTiles_X; }

    private:

        // Handle Field

        unsigned int tile_height;
        unsigned int tile_width;

        unsigned int field_height;
        unsigned int field_width;

        unsigned int numberOfTiles_Y;
        unsigned int numberOfTiles_X;

        float scroll_right;
        float scroll_bottom;

        vector<vector<Tile>> field;     // This matrix represents the field, where every Tile links to all
                                        // image instances it needs

        inline float rasterTOopengl_X(int x, float p);
        inline float rasterTOopengl_Y(int y, float p);
        inline void multVertexData(float data[], float xLef, float xRig, float yTop, float yBot);
        void generateField();

        // Handle Images

        vector<CreaType> *creatureTypeInfos;

        vector<CreatureImage> creatureImages; // In this vector fields
        vector<TerrainImage>  terrainImages;  // the tga- and texture-instances are located

        void loadCreatureImages(vector<CreaType> *creatureTypeInfos);
        void loadTerrainImages();

};



#endif // TILEMANAGER_H
