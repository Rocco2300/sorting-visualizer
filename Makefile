CXX = g++
CXXFLAGS = -g -O2 -Wall -std=c++17
TARGET = a

SRC = src
OBJ = obj
INC = -Iinclude -Iinclude/imgui
LIB = lib
LIBS = -l sfml-graphics -l sfml-window -l sfml-system -l opengl32

SRCS = $(wildcard $(SRC)/*.cpp $(SRC)/imgui/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
# OBJS = $(SRCS:$(SRC)/%.cpp=$(OBJ)/%.o)

.PHONY: all install clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -L $(LIB) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

install:
	@echo Building the libraries...
	@build.bat
	@echo Moving the libraries in the correct directories...
	@install.bat

clean:
	del /f obj\\*.o
	del /f a.exe