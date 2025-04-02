#pragma once
#include "grid.hpp"

class Simulation {
public:
  Simulation(int width, int heigth, int cellSize)
      : grid(width, heigth, cellSize) {};
  void Draw();
  void SetCellValue(int row, int column, int value);
  int CountLiveNeighbors(int row, int column);

private:
  Grid grid;
};
