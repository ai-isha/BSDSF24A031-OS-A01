CC = gcc
# -fPIC is strictly required for shared libraries
CFLAGS = -Wall -Wextra -fPIC
TARGET_DYN = bin/client_dynamic
TARGET_STAT = bin/client_static
LIB_DYN = lib/libmyutils.so
LIB_STAT = lib/libmyutils.a
LIB_OBJS = obj/mystrfunctions.o obj/myfilefunctions.o
MAIN_OBJ = obj/main.o

# Build both static and dynamic versions
all: $(TARGET_STAT) $(TARGET_DYN)

# Link Dynamic Executable
$(TARGET_DYN) : $(MAIN_OBJ) $(LIB_DYN)
	$(CC) -o $(TARGET_DYN) $(MAIN_OBJ) -L./lib -lmyutils

# Link Static Executable
$(TARGET_STAT) : $(MAIN_OBJ) $(LIB_STAT)
	$(CC) -o $(TARGET_STAT) $(MAIN_OBJ) -L./lib -lmyutils

# Create Dynamic Library (.so)
$(LIB_DYN) : $(LIB_OBJS)
	$(CC) -shared -o $(LIB_DYN) $(LIB_OBJS)

# Create Static Library (.a)
$(LIB_STAT) : $(LIB_OBJS)
	ar rcs $(LIB_STAT) $(LIB_OBJS)

# Compile Object Files
obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o bin/client_* lib/libmyutils.*
