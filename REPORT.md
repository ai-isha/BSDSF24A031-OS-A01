# OS Assignment - Feature 2 Report

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
