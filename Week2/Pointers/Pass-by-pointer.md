### Pass by Pointer

- In pass by pointer, a pointer is passed as an argument to a function.
- The function can access and modify the data at that memory address, leading to changes in the original variable.

- Example

```c
#include <stdio.h>
void increment(int *ptr){
    *ptr = *ptr + 1;
}
int main(){
    int value = 5;
    int *ptr = &value;

    increment(ptr);

    printf("Modified value: %d\n", value);
}
```
### Pass by value vs Pass by Pointer

- Pass by value: Copies objects from one stack frame to another
- Pas by pointer: Copies only the pointer
  - It can access and modify the data at that memory address, leading to changes in the original variable.
- Thus, pass by pointer is more efficient for large data objects.
