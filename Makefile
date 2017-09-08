HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))

INCLUDE = -I./file -I./log4z
LIBPATH = -L./file -lconfigini -L./log4z/lib -llog4z -lpthread
CXXFLAGS = -g -Wall -std=c++0x

TARGET = attr_sort

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ $(CXXFLAGS) $^ -o $@ $(LIBPATH)

%.o: %.cpp
	g++ $(CXXFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean
clean:
	-rm *.o
	-rm $(TARGET)

