CXX = g++
CXXFLAGS = -fopenmp -std=c++17 -O2

FILENAME = main.cpp
TARGET = lab2.3

all: $(TARGET)

$(TARGET): $(FILENAME)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(FILENAME)

clean:
	rm -f $(TARGET)