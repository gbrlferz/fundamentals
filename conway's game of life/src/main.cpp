#include "raylib.h"
#include "simulation.hpp"

int main(void) {
  Color GREY = {29, 29, 29, 255};
  const int WINDOW_WIDTH = 750;
  const int WINDOW_HEIGHT = 750;
  const int CELL_SIZE = 25;
  int FPS = 12;

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
  SetTargetFPS(FPS);
  Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
  simulation.SetCellValue(3,4,1);

  // Simulation loop
  while (!WindowShouldClose()) {
    // 1. Event handling

    // 2. Updating state

    // 3. Drawing
    BeginDrawing();
    ClearBackground(GREY);
    simulation.Draw();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
