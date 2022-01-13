#include "raylib.h"

void UpdateDrawFrame(void)
{

	BeginDrawing();

	ClearBackground(RAYWHITE);

	EndDrawing();
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "[rlgl] - shader loading issue");
    SetTargetFPS(60);

	LoadShader(0, "src/model_fog.fs");

    while (!WindowShouldClose())
    {
		UpdateDrawFrame();
    }
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
