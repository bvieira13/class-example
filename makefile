# Compiler
CC = gcc

# Compiler flags
CFLAGS = -O2

# Linker flags
LDFLAGS =

# Output executable name
TARGET = main.exe

# Source files
SRCS = main.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
