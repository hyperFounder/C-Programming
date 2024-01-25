### Garbagge collection

- Garbage collection automatically frees up memory that is no longer referenced.

### Memory Leaks

- If memory allocated using ```malloc()``` is not ```free()-ed``` from the **Heap**, then the system will “leak memory”
- They happen when blocks of memory are allocated, but not returned to the Heap.
#### Consequences
- Memory leaks slowdown system performance by reducing the amount of available memory.
- Memory leaks continue to waste memory over time, eventually consuming all RAM resources.
- **In a Short Lived Application:** Little if any noticeable effect. Modern operating system recollects lost memory after program termination.


## Valgrind

- Valgrind Docker Container MacOS:
  - https://github.com/karekoho/valgrind-container
  - https://medium.com/@massey0ross/valgrind-in-macos-with-docker-3b0e4bbdece1

- Valgrind is a tool for memory leak detection.
- Memcheck is the default tool Valgrind uses when you don't ask it for another tool.
--- 
### Run Valgrind
- First, compile your ```c``` code using gcc
```text
[root@localhost]# valgrind ./main
```
- To check for full leaks
```c
[root@localhost]# valgrind --leak-check=full ./main
```
---
- Create a working directory container that contains Valgrind:
  - Navigate to main project folder
  - In terminal, type ```valgrind```
    - which is our alias for creating docker containers
  - Start a container: ```docker start -i container_id```
  - Exit the container: ```exit``` 

--- 
### Memory Leak Example
- The following example is a basic memory leak in C:


```c
#include <stdlib.h>
#include <stdio.h>

#define  LOOPS    10
#define  MAXSIZE  256

int main(int argc, char **argv)
{
     int count = 0;
     char *pointer = NULL;

     for(count=0; count<LOOPS; count++) {
          pointer = (char *)malloc(sizeof(char) * MAXSIZE);
     }

     free(pointer);

     return count;
}
```
- In this example, we have 10 allocations of size MAXSIZE.
- Every allocation, with the exception of the last, is lost.
- If no pointer is pointed to the allocated block, it is unrecoverable during program execution.
- A simple fix to this trivial example is to place the free() call inside of the ‘for’ loop.

```c
LEAK SUMMARY:
    definitely lost: 2304 bytes in 9 blocks.
    possibly lost: 0 bytes in 0 blocks.
```