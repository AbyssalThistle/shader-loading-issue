#include "raylib.h"

#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame(void)
{

	BeginDrawing();

	ClearBackground(RAYWHITE);

	EndDrawing();
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "[rlgl] - shader loading issue");

#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);

	LoadShader(0, "src/model_fog.fs");

    while (!WindowShouldClose())
    {
		UpdateDrawFrame();
    }
#endif
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
