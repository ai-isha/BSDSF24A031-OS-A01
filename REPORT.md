# OS Assignment - Feature 3 Report

## 1. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?
In Part 2, we linked object files (`.o`) directly to build the executable. In Part 3, we introduced a new variable `LIB = lib/libmyutils.a`. We added a new rule using the `ar rcs` command to archive the `.o` files into this static library. Finally, we changed the linking rule for the executable to use `-L./lib` (specifying the library directory) and `-lmyutils` (linking our specific library) instead of listing the object files directly.

## 2. What is the purpose of the ar command? Why is ranlib often used immediately after it?
The `ar` (archiver) command is used to create, modify, and extract from archives. In C programming, it is specifically used to bundle multiple object (`.o`) files into a single static library (`.a`) file. 
`ranlib` is often used immediately after `ar` to generate an index of the contents of the archive and store it within the archive itself. This index makes the linking process much faster for the compiler, especially in large libraries. (Note: modern `ar rcs` commands automatically include this indexing step, where 's' acts as ranlib).

## 3. When you run nm on your client_static executable, are the symbols for functions like mystrlen present? What does this tell you about how static linking works?
Yes, the symbols for functions like `mystrlen` are present in the final `client_static` executable when checked with the `nm` command. 
This tells us that during static linking, the linker extracts the actual machine code for these functions from the `.a` library and copies it directly inside the final executable binary. As a result, the executable becomes completely standalone and does not need the library file to run on another computer.# OS Assignment - Feature 2 Report

## 1. Explain the linking rule in this part's Makefile: $(TARGET) :$(OBJECTS). How does it differ from a Makefile rule that links against a library?
In this rule, `$(TARGET) : $(OBJECTS)`, we are directly linking multiple individual object files (`.o` files like `main.o`, `mystrfunctions.o`, etc.) to create the final executable. 
This is different from linking against a library because when we use a library, we don't list all the `.o` files one by one. Instead, we package the `.o` files into a single archive (like `.a` or `.so`) and use compiler flags like `-L` (library path) and `-l` (library name) to tell the linker to find the required functions from that package.

## 2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?
A `git tag` is like a permanent bookmark in the project's history. It is highly useful for marking specific, stable points in the code, such as version releases (e.g., v1.0). 
* **Simple Tag (Lightweight):** It is just a pointer to a specific commit. It doesn't store any extra information.
* **Annotated Tag:** It is stored as a full object in the Git database. It contains metadata like the tagger's name, email, date, and a specific tagging message, making it the standard choice for official software releases.

## 3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?
The purpose of a GitHub Release is to package the software so that end-users can easily download and use a specific, stable version of the project. 
Attaching compiled binaries (like our `client` executable) is extremely significant because it allows users to simply download and run the program instantly. They don't need to install compilers (like `gcc`), install `make`, or know how to build the source code themselves.
