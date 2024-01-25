## Libraries, Linkers, Loaders

- A library is a collection of pre-compiled object files that provide functions, routines, or data that a program can use.
- A linker is a program that takes one or more object files and combines them into a single executable file
- A loader is the part of an operating system that is responsible for loading programs and libraries in main memory.

#### Object Code

- The object code contains machine code or intermediate code that represents the compiled version of the source code. They are not yet linked into the final executable. 

#### Dynamic/Shared Libraries:

- Shared Libraries are loaded by the executable (or other shared library) at runtime.
- Shared libraries have the file extension ```.so``` (on Unix-like systems) or ```.dll``` (on Windows).

## Handling Programs

- Sometimes your source code is split into several source (.c) files. 
- You can compile each source file separately via 

```bash
gcc -Wall -Werror -c file1.c
gcc -Wall -Werror -c file2.c
```
- Finally, you can link all files together via

```bash
gcc -Wall -Werror -o my_program file1.o file2.o
```
#### Note

- The ```-c``` option tells the compiler to generate an object file ```(.o file)``` for each source file. 

- ```-Wall -Werror``` means that all warning messages are enabled ```(-Wall)```, and any warnings encountered during compilation will be treated as errors ```(-Werror)```
