CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= main

ifeq ($(OS),Windows_NT)
    # Windows native setup
    CLEAN_CMD = if exist $(BIN)\* del /q $(BIN)\*
    CLEAR_CMD = cls
    FIX_PATH = $(subst /,\\,$1)
    EXEC_PREFIX = $(BIN)\$(EXECUTABLE)
else
    # Linux/Mac setup
    CLEAN_CMD = rm -f $(BIN)/* *.out
    CLEAR_CMD = clear
    FIX_PATH = $1
    EXEC_PREFIX = ./$(BIN)/$(EXECUTABLE)
endif

all: $(BIN)/$(EXECUTABLE)

run: clean all
	$(CLEAR_CMD)
	$(EXEC_PREFIX)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-$(CLEAN_CMD)
