CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

SRC = src/main.cpp src/Debugger.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = smart_debugger

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)