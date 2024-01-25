### CMake and MakeFiles

- CMake is cross-platform free and open-source software for build automation, testing, packaging and installation of software by using a compiler-independent method.
- Makefiles are a simple way to organize code compilation.
  - They control the compilation of large program systems.
  - Actions of make are controlled by the Makefile

### Makefile Structure

- Declarations: Assignment of values to variables. Example:
```text
CFLAGS = -Wall -Werror -g -fPIC // -g Generates debugging information.
TARGETS = libinput.so
```
- Targets: The file or action that needs to be built or executed. 
  - If the file target does not exist, of if the dependencies are newer than the target, then the commands are executed
```text
target: dependencies
  commands
```
- If you want to call make in a directory (let's say in the src directory), you can use the ```-C``` option:
```text
make -C src
```
---
### MakeFile Example
```makefile
CFLAGS=-Wall -Werror -g  -fPIC
TARGETS=libinput.so

all: $(TARGETS)

libinput.so: input.o
	$(CC) $(CFLAGS) -shared  -o $@ input.o 

%.o: %.c // Compile any .c file into an object file.
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGETS) *.o
```
- ```all: ``` The default target. When you run ```make``` without specifying a target, it builds the default target.
- ```all: $(TARGETS)```: Uses the variable ```TARGETS```.
- ```$(CC)``` usually means the ```gcc```
- ```%.o: %.c:``` A generic rule for building object files ```(*.o)``` from C source files ```(*.c)```. Object files depend on c files.
- ```$@ ``` represents the target name.
- ```$<``` refers to the first dependency
- ```clean:``` This target is used to clean up the directory and temporary files created. 
