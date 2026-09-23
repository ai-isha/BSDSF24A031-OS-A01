# Macros
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = bin/client_static
LIB = lib/libmyutils.a
LIB_OBJS = obj/mystrfunctions.o obj/myfilefunctions.o
MAIN_OBJ = obj/main.o

all: $(TARGET)

# 1. Compile final executable by linking the static library
$(TARGET) : $(MAIN_OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN_OBJ) -L./lib -lmyutils

# 2. Create the Static Library using 'ar'
$(LIB) : $(LIB_OBJS)
	ar rcs $(LIB) $(LIB_OBJS)

# 3. Compile .c files to .o object files
obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o $(TARGET) $(LIB)
