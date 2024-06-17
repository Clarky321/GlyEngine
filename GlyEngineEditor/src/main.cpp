#include <raylib.h>
#include <raymath.h>
#include <imgui.h>

#include <backends/imgui_impl_opengl3.h>
#include <imgui_impl_raylib.h>
#include <tinyfiledialogs.h>

const int screenWidth = 1200;
const int screenHeight = 800;

int main()
{
    InitWindow(screenWidth, screenHeight, "2D Top-Down Engine");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    SetTargetFPS(60);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplRaylib_Init();
    ImGui_ImplOpenGL3_Init();

    while (!WindowShouldClose())
    {
        ImGui_ImplRaylib_NewFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        EndDrawing();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplRaylib_Shutdown();
    ImGui::DestroyContext();

    CloseWindow();

    return 0;
}