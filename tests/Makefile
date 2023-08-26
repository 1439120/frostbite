CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= ../bin
SRC		:= ../src
INCLUDE	:= ../include
LIB		:= ../lib
DOCTEST := /home/nkosana/Documents/doctest-master/doctest/

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= tests


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): ./*.cpp $(filter-out ../src/main.cpp, $(wildcard ../src/*.cpp))
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(DOCTEST) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/* *.out
