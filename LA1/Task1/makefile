# name of the executable file
TARGET = myprogram

# list of the source files
SOURCES = main.cpp matrix.cpp

# list of the object files
OBJECTS = $(SOURCES:.cpp=.o)

# name of the library
LIB = libmatrix.a

# header files
HEADERS = matrix.h

# flags for the C++ compiler
CXXFLAGS = -I.

# flags for the linker
LDFLAGS = -L. -lmatrix

ifeq ($(OS),Windows_NT)
    RM = del /Q
	TARGET = myprogram.exe
else
    RM = rm -f
endif

# default target
all: $(TARGET)

# how to build the executable file
$(TARGET): $(OBJECTS) $(LIB)
	g++ -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# how to build the object files
%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@

# how to build the library
$(LIB): matrix.o $(HEADERS)
	ar rcs $(LIB) matrix.o

# target for cleaning up
clean:
	$(RM) $(OBJECTS) $(LIB) $(TARGET)

# target to run the program
run: $(TARGET)
	./$(TARGET)