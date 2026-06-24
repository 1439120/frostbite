CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

# Standard dynamic linking (MSYS2 automatically handles these paths now)
LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= main.exe

# OS Detection and Command Fixes
ifeq ($(OS),Windows_NT)
    CLEAN_CMD = if exist $(BIN)\$(EXECUTABLE) del /q $(BIN)\$(EXECUTABLE)
    CLEAR_CMD = cls
    MKDIR_CMD = if not exist $(BIN) mkdir $(BIN)
    EXEC_PREFIX = $(BIN)\$(EXECUTABLE)
else
    CLEAN_CMD = rm -f $(BIN)/$(EXECUTABLE) *.out
    CLEAR_CMD = clear
    MKDIR_CMD = mkdir -p $(BIN)
    EXEC_PREFIX = ./$(BIN)/$(EXECUTABLE)
endif

all: $(BIN)/$(EXECUTABLE)

run: clean all
	$(CLEAR_CMD)
	$(EXEC_PREFIX)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(MKDIR_CMD)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-$(CLEAN_CMD)
