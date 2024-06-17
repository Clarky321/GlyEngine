#include <GlyEngineCore\chunk.h>
#include <GlyEngineCore\tile.h>
#include <PerlinNoise.hpp>

const siv::PerlinNoise::seed_type seed = 123456u;
siv::PerlinNoise perlin(seed);

// Функция для получения значения шума
float GetNoiseValue(float x, float y) {
    return perlin.noise2D(x, y);
}

// Функция для генерации чанка на основе позиции
Chunk GenerateChunk(Vector2 position) {
    Chunk chunk;
    chunk.position = position;
    chunk.tiles.resize(CHUNK_SIZE, std::vector<Tile>(CHUNK_SIZE));

    for (int y = 0; y < CHUNK_SIZE; y++) {
        for (int x = 0; x < CHUNK_SIZE; x++) {
            Tile tile;
            float noiseValue = GetNoiseValue((position.x + x) * 0.1f, (position.y + y) * 0.1f);

            if (noiseValue < 0.3f) {
                tile.type = WATER;
                tile.hasCollision = false;
            }
            else if (noiseValue < 0.6f) {
                tile.type = GRASS;
                tile.hasCollision = false;
            }
            else {
                tile.type = TREE;
                tile.hasCollision = true;
            }
            chunk.tiles[y][x] = tile;
        }
    }

    return chunk;
}