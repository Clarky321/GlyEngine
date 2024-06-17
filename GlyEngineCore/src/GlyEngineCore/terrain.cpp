#include <GlyEngineCore\terrain.h>

// Инициализация глобальной переменной
std::unordered_map<Vector2, Chunk, Vector2Hash> chunks;

// Функция для получения позиции камеры
Vector2 GetCameraPosition(Camera2D camera) {
    return { (camera.target.x - (camera.offset.x / camera.zoom)) / CHUNK_SIZE,
            (camera.target.y - (camera.offset.y / camera.zoom)) / CHUNK_SIZE };
}

// Функция для обновления чанков в пределах видимости камеры
void UpdateChunks(Camera2D camera) {
    Vector2 cameraPos = GetCameraPosition(camera);
    Vector2 topLeftChunk = { floor(cameraPos.x / CHUNK_SIZE), floor(cameraPos.y / CHUNK_SIZE) };

    for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
            Vector2 chunkPos = { topLeftChunk.x + x, topLeftChunk.y + y };

            if (chunks.find(chunkPos) == chunks.end()) {
                chunks[chunkPos] = GenerateChunk(chunkPos);
            }
        }
    }
}