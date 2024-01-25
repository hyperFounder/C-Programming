## Shared Libraries

- Assume we have a project structure

```text
myproject/
|-- src/
|   |-- main.c                    // Main program source file
|   |-- mathlib.c                 // Source code for math library
|-- include/
|   |-- mathlib.h                 // Header file for the math library
|-- lib/
|   |-- libmathlib.so             // Compiled shared library
```
---
### Template - Create a shared library
```bash
gcc -Wall -Werror -shared -fPIC -o lib<my_library>.so <filename1>.o ..
```

- ```-shared:``` Indicates that the output should be a shared library.
- ```-fPIC:``` Generates position-independent code, which is required for shared libraries.

---

### Source Files
- This is the source file for math library ```mathlib.c```

```c
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}
```

- This is our header file ```mathlib.h```
  - extern: functions or variables are defined in one file and used in another.
```c
extern int add(int a, int b);
extern int multiply(int a, int b);
```

- This is our ```main.c``` file

```c
#include <stdio.h>
#include "mathlib.h"

int main() {
    int num1 = 5, num2 = 3;

    printf("Addition: %d\n", add(num1, num2));
    printf("Multiplication: %d\n", multiply(num1, num2));

    return 0;
}
```
---

### Compilation Process

- First, compile the library source file ```mathlib.c``` to object file (.o)
```bash
gcc -Wall -Werror -fPIC -c mathlib.c
```
- Then, create the shared library from the object file 

```bash
gcc -Wall -Werror -fPIC -shared -o libmathlib.so mathlib.o
```
---
### Compiling Main Program

- When you use ```#include``` in programs, the compiler needs to find that file.
- C-compiler searches ```/usr/local/include``` and ```/usr/include``` for include-files
- Any other directories must be specified with ```-I``` option

### Compile the main program source file

```c
gcc -Wall -Werror -I../include -c src/main.c 
```
- This command compiles ```main.c``` into an object file ```(main.o)```.

### Link the main program with the shared library

- C-compiler searches ```/lib``` and ```/usr/lib``` for library files
- Any other directories must be specified with ```-L``` option
- - ```-l``` specifies a library to be used.

```shell
gcc -Wall -Werror -L../lib -o program main.o -lmathlib
```
- This command links the ```main.o``` object file with the ```libmathlib.so``` shared library, creating the final executable named program.
---
### Loading the Library in Memory

- Library standard locations are ```/lib``` and ```/usr/lib```
- The shared library must be in a location where it can be found during runtime. 
- One way to do this is by exporting the ```LD_LIBRARY_PATH``` environment variable.

```shell
export LD_LIBRARY_PATH=<PathToLibrary>
```
- To load several shared libraries:
```shell
export LD_LIBRARY_PATH=<PathToLibrary1>:<PathToLibrary2> ...
```
### Library Path - Standard way 

```shell
export LD_LIBRARY_PATH=../lib:$LD_LIBRARY_PATH
```
- This sets the ```LD_LIBRARY_PATH``` variable to include the ```../lib directory```, followed by ```LD_LIBRARY_PATH```.
---
### Note
- On macOS, the environment variable for specifying the library search path is ```DYLD_LIBRARY_PATH```.
---
### Run the Program

- You can now run the program

```c
./program
```