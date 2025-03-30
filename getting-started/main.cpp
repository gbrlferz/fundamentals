#include "include/raylib.h"

int main() {

    int ballX = 400;
    int ballY = 400;
    Color green = {20, 160, 133, 255};

    InitWindow(800, 800, "My first raylib game");
    SetTargetFPS(60);

    // Game loop
    while(!WindowShouldClose()) {
        // 1. Event handling
        if (IsKeyDown(KEY_RIGHT)) { ballX += 3; };
        if (IsKeyDown(KEY_LEFT)) { ballX -= 3; };
        if (IsKeyDown(KEY_DOWN)) { ballY += 3; };
        if (IsKeyDown(KEY_UP)) { ballY -= 3; };

        // 2. Update positions

        // 3. Drawing
        BeginDrawing();

        DrawCircle(ballX, ballY, 20, WHITE);

        ClearBackground(green);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
