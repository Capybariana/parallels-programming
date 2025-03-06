CXX = gcc
CXXFLAGS = -fopenmp

TARGET = lab2.1

all: $(TARGET)

$(TARGET): main.c
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)