CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
LDFLAGS = -pthread

TARGET = lab3.2
SRC = lab3.2.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
