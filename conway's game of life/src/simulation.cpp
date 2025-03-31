#include "simulation.hpp"
#include <utility>
#include <vector>

void Simulation::Draw() { grid.Draw(); }

void Simulation::SetCellValue(int row, int column, int value) {
  grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column) {
  int liveNeighbors = 0;
  std::vector<std::pair<int, int>> neighborOffset = {
      {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1},
  };

  for (const auto &offset : neighborOffset) {
    int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
    int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
    liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
  }
  return liveNeighbors;
}
