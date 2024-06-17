#ifndef CHUNK_H
#define CHUNK_H

#include <vector>
#include <raylib.h>
#include <GlyEngineCore\tile.h>
#include <PerlinNoise.hpp>

const int CHUNK_SIZE = 32;

struct Chunk {
    std::vector<std::vector<Tile>> tiles;
    Vector2 position;
};

Chunk GenerateChunk(Vector2 position);
float GetNoiseValue(float x, float y);

#endif // CHUNK_H