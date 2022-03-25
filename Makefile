CXX = g++
CXXFLAGS = -g -O2 -Wall -std=c++17
TARGET = a

SRC = src
OBJ = obj
INC = include
LIB = lib
LIBS = -l sfml-graphics -l sfml-window -l sfml-system

SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(SRCS:$(SRC)/%.cpp=$(OBJ)/%.o)

.PHONY: all install clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -L $(LIB) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INC) -c $< -o $@

install: 
	@mkdir obj
	@mkdir lib
	@mkdir build
	@git clone --branch 2.5.1 https://github.com/SFML/SFML.git
	@cmake -G "MinGW Makefiles" -S SFML -B build
	@cd build && mingw32-make
	@move build\lib\*.a lib
	@move build\lib\*.dll .
	@move SFML\include\SFML include
	@rd /s /q build
	@rd /s /q SFML

clean:
	del /f obj\\*.o
	del /f a.exe