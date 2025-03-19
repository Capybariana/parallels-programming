CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
LDFLAGS = -pthread

TARGET = lab3.1

SRC = lab3.1.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean