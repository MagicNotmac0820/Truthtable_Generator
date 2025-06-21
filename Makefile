BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./obj
INCLUDE = ./include
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(BIN_DIR)/example
.PHONY: clean
.PHONY: execute

CC = g++
CXXFLAGS = -fdiagnostics-color=always -std=c++23 -g3 -ggdb -Wall -Wextra

$(BIN_DIR):
	mkdir -p $@
$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR)/example: $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)/truthtable_gen.h | $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -I $(INCLUDE) -o $@

clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*.o
execute: $(BIN_DIR)/example
	$<