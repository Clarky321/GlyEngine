#ifndef TERRAIN_H
#define TERRAIN_H

#include <unordered_map>
#include <raylib.h>
#include <GlyEngineCore\chunk.h>

// Определение оператора == для Vector2
inline bool operator==(const Vector2& lhs, const Vector2& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

// Хэш-функция для Vector2 для использования в unordered_map
struct Vector2Hash {
    std::size_t operator()(const Vector2& v) const {
        return std::hash<float>()(v.x) ^ std::hash<float>()(v.y);
    }
};

// Глобальная переменная для хранения всех чанков
extern std::unordered_map<Vector2, Chunk, Vector2Hash> chunks;

// Функции для работы с террейном
void UpdateChunks(Camera2D camera);
Vector2 GetCameraPosition(Camera2D camera);

#endif // TERRAIN_H