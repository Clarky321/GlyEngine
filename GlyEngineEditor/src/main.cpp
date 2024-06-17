#include <raylib.h>
#include <GlyEngineCore\terrain.h>
#include <GlyEngineCore\chunk.h>
#include <GlyEngineCore\tile.h>

const int TILE_SIZE = 32;

void UpdateDrawFrame(Camera2D& camera)
{
    UpdateChunks(camera);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode2D(camera);

    for (const auto& chunkPair : chunks) {
        const Chunk& chunk = chunkPair.second;

        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                Vector2 position = { chunk.position.x * CHUNK_SIZE + x, chunk.position.y * CHUNK_SIZE + y };
                Tile tile = chunk.tiles[y][x];

                Color color;
                switch (tile.type)
                {
                case GRASS: color = GREEN; break;
                case WATER: color = DARKGREEN; break;
                case TREE: color = DARKGRAY; break;
                }

                DrawRectangle(position.x * TILE_SIZE, position.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
            }
        }
    }

    EndMode2D();

    EndDrawing();
}

int main(void) {
    // Инициализация окна
    InitWindow(800, 600, "Procedural Terrain Generation");
    SetTargetFPS(60);

    Camera2D camera = { 0 };
    camera.target = Vector2 { 0.0f, 0.0f };
    camera.offset = Vector2 { 400.0f, 300.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose()) {
        // Обновление камеры
        if (IsKeyDown(KEY_RIGHT)) camera.target.x += 10;
        if (IsKeyDown(KEY_LEFT)) camera.target.x -= 10;
        if (IsKeyDown(KEY_UP)) camera.target.y -= 10;
        if (IsKeyDown(KEY_DOWN)) camera.target.y += 10;

        UpdateDrawFrame(camera);
    }

    CloseWindow();
    return 0;
}