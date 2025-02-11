# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Source files
SRCS = main.c paciente.c menu.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o) # `main.o` and `paciente.o`

# Executable name
TARGET = t1

# Compile source files into object files
%.o: %.c # matches `main.o` and `my_string.o`
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create the executable
$(TARGET): $(OBJS) # matches `my_program`
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Phony targets (not files) to avoid conflicts with files of the same name
.PHONY: all compile run clean # `make` will always run these targets

# Explicit compile target (produces the target program)
compile: $(TARGET)

# Default target (compile and run)
all: compile run

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)