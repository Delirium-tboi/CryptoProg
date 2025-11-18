# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -O2
# Libraries
LDLIBS = -lcryptopp

# Target executable
TARGET = hash_program

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean