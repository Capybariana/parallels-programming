CXX = gcc
CXXFLAGS = -fopenmp

TARGET = lab2.2

all: $(TARGET)

$(TARGET): main.c
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.c -lm

clean:
	rm -f $(TARGET)