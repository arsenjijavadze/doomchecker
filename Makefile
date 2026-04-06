CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = src/main.cpp src/diagnostics.cpp src/civilization.cpp src/activity.cpp

TARGET = doomchecker

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
