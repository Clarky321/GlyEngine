#ifndef TILE_H
#define TILE_H

enum TileType
{
    GRASS,
    WATER,
    TREE
};

struct Tile
{
    TileType type;
    bool hasCollision;
};

#endif // TILE_H