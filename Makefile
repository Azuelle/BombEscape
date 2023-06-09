# Shell path
SHELL = /bin/bash

# Output directory
OUT_DIR = ./build
# Executeable directory
BIN_DIR = ./bin
# Source code directory
SRC_DIR = ./src

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS += -Wall -MMD -MP
# Additional flags
LDFLAGS = -lcurses

# Final executable name
EXEC = bombescape
# Get all source codes
SRC = $(shell find $(SRC_DIR) -name '*.cpp')
# Object codes
OBJ = $(SRC:%.cpp=$(OUT_DIR)/%.o)
# Substitutes ".o" with ".d" for dependency files
DEP = ${OBJ:.o=.d}


all: $(BIN_DIR)/$(EXEC)

# Make the final executable
$(BIN_DIR)/$(EXEC): $(OBJ)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Make all object codes
$(OUT_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@ -c

clean:
	rm -rf $(OUT_DIR)

.PHONY: clean all


proto: test/game_prototype.cpp src/time_utils.h
	mkdir -p $(OUT_DIR)
	$(CXX) $^ -o $(OUT_DIR)/$@.out -lcurses

maptest: test/map_test.cpp src/entity.cpp src/map_gen.cpp src/playfield.cpp src/player.cpp src/gamestate.cpp src/render.cpp
	mkdir -p $(OUT_DIR)
	$(CXX) -g $^ -o $(OUT_DIR)/$@.out -lcurses

mainmenu: src/init_window.cpp src/menu.cpp test/main_menu.cpp
	mkdir -p $(OUT_DIR)
	$(CXX) -g $^ -o $(OUT_DIR)/$@.out -lncurses

hudtest: test/hud_test.cpp src/interface.cpp src/init_window.cpp src/entity.cpp src/map_gen.cpp src/playfield.cpp src/player.cpp src/gamestate.cpp src/render.cpp
	mkdir -p $(OUT_DIR)
	$(CXX) -g $^ -o $(OUT_DIR)/$@.out -lncurses

# Include all G++-generated makefiles
-include ${DEP}
