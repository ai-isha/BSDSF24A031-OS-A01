# OS Assignment - Feature 4 Report

## 1. What is Position-Independent Code (-fPIC) and why is it a fundamental requirement for creating shared libraries?
Position-Independent Code (`-fPIC`) generates machine code that executes properly regardless of where it is loaded in the system's memory. It is a fundamental requirement for shared libraries (`.so`) because a single shared library can be loaded by multiple different programs at the same time, and each program might load it at a different memory address. `-fPIC` ensures all memory references inside the library are relative, preventing conflicts.

## 2. Explain the difference in file size between your static and dynamic clients. Why does this difference exist?
The `client_static` executable is significantly larger than `client_dynamic`. This difference exists because during static linking, the actual machine code of the library functions (like `mystrlen`) is copied directly into the final `client_static` binary. In contrast, dynamic linking only stores a small reference (a pointer) to the shared library in `client_dynamic`. The actual code remains in the `.so` file and is only loaded into memory when the program runs, keeping the executable file small.

## 3. What is the LD_LIBRARY_PATH environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?
`LD_LIBRARY_PATH` is an environment variable that tells the Linux dynamic loader where to look for shared libraries outside of the standard system directories (like `/usr/lib`). It was necessary to set it because our custom `libmyutils.so` was located in our local project's `/lib` folder, which the OS does not check by default. This tells us that the operating system's dynamic loader is actively responsible for finding, resolving, and mapping external dependencies into the program's memory space just before execution begins.# OS Assignment - Feature 3 Report

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
