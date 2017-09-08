HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))

CXXFLAGS = -g -Wall -std=c++0x -c -fPIC
TARGET = libconfigini.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	 ar rcs $@ $^

%.o: %.cpp 
	g++ $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	-rm *.o
	-rm $(TARGET)
