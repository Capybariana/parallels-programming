CXX = g++
CXXFLAGS = -std=c++17 -Wall

ifdef USE_DOUBLE
CXXFLAGS += -DUSE_DOUBLE
endif

lab1: lab1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< -lm

clean:
	rm -f lab1