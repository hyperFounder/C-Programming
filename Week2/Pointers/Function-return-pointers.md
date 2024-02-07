### Functions can return pointers
- Functions can return pointers in C
  - allows them to dynamically allocate memory and return a pointer to the allocated data.
---

- A function can return a pointer
```c
int *foo() // foo returns a pointer of type int
char *foo() // foo returns a pointer of type char
```
#### Example
- Find the maximum value and return the pointer.
```c
int *max(int *a, int *b){
    if (*a > *b){
        return a;
    }
    return b;
}
```
- Our main function...
```c
int main(){
    int a=4, b=5;
    int *c = max(&a, &b);
    printf("Max value = %d", *c); // Max value = 5
    return 0;
}
```
---
- Another example...
```c
#include <stdio.h>
#include <stdlib.h>


int *createArr(int size){ // Functions can return pointers
    int *arr = (int *) malloc(size * sizeof (int ));

    if (arr == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    // Initialize arr
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
    return arr;
}

int main(){
    int size = 5;
    int *ptr = createArr(size);

    // Accessing the array

    for (int i = 0; i < size; ++i) {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}

```
### Never return a pointer to a local variable.

- Returning a pointer to a local variable in C is dangerous and can lead to undefined behavior.
  -  problematic: local variables are stored on the stack

```c
#include <stdio.h>
#include <stdlib.h>

int* createLocalVariable() {
    int localVar = 42;
    int* ptr = &localVar;  // Returning a pointer to a local variable

    return ptr;
}

int main() {
    int* result = createLocalVariable();

    // Accessing the value through the returned pointer
    printf("Value at the returned pointer: %d\n", *result);

    // The local variable 'localVar' has gone out of scope
    // Accessing it through the returned pointer leads to undefined behavior
    printf("Value at the returned pointer (undefined behavior): %d\n", *result);

    return 0;
}
```
