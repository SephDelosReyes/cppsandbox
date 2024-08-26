CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = my_executable
SOURCES = main.cpp  # List your source files here
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

run:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) && ./$(TARGET)
