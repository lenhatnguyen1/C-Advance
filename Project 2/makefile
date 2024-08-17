# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall

# Target executable
TARGET = main

# Source and header directories
SRC_DIR = Source
HEADER_DIR = Header

# Source files
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/UI.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(HEADER_DIR) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Debug rule
debug: $(TARGET)
	gdb ./$(TARGET)
