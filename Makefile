CXX = g++
CXXFLAGS = -g -O2 -Wall -std=c++17
TARGET = a

SRC = src
OBJ = obj
INC = include
LIB = lib
PCK = -l sfml-graphics -l sfml-window -l sfml-system

SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(SRCS:$(SRC)/%.cpp=$(OBJ)/%.o)

.PHONY: all clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -L $(LIB) $(PCK)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INC) -c $< -o $@

clean:
	del /f obj\\*.o
	del /f a.exe