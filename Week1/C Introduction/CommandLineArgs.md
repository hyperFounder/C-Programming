### Command Line Arguments

```c
int main(int argc, char *argv[])
```

- argc (argument count) stores the number of command line arguments. 

- argv (argument vector) is an array of char pointers listing all the arguments. 
- + Example argv[0] is the name of the program, argv[1] is the first command-line argument.

#### Example

```c
#include <stdio.h>

int main(int argc, char *argv[]){
    int i;
    printf("You have entered %d arguments: \n",  argc);

    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}
```

#### Example 2

- Look at the example...

```c
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1416

int main(int argc, char *argv[]){

    char *a = argv[1]; // diameter as a string
    int diameter = atoi(a); // converts string to int
    float radius = diameter / 2;
    float area = PI * radius * radius;
    float circumference = 2 * PI * radius;
    if (argc == 2){
        printf("You have entered %d\n", diameter);
        printf("Circle with diameter %d has area of %f and circumference of %f\n", diameter, area, circumference);
    }
    return 0;
}
```
