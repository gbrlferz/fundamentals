# Compiler settings
CXX = g++
CXXFLAGS = -O1 -Wall -Wno-missing-braces -Iinclude/
LDFLAGS = -Llib/ -lraylib -lopengl32 -lgdi32 -lwinmm

# Source files (add new .cpp files here)
SRC_DIR = src
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/simulation.cpp $(SRC_DIR)/grid.cpp

# Output executable
EXECUTABLE = game.exe

default: build run

build:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

run:
	./$(EXECUTABLE)

clean:
	del $(EXECUTABLE)   # Windows
