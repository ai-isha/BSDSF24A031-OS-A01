# Macros / Variables
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = bin/client
OBJECTS = obj/main.o obj/mystrfunctions.o obj/myfilefunctions.o

# Default target
all: $(TARGET)

# Linking Rule
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compilation Rule
obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Rule
clean:
	rm -f obj/*.o $(TARGET)
