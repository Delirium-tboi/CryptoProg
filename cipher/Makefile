CXX = g++
CXXFLAGS = -std=c++11 -Wall
LIBS = -lcryptopp
SOURCES = main.cpp cipher.cpp
HEADERS = cipher.h
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = encryptor

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
