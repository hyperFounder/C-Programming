## The C-Preprocessor

- The C Preprocessor is not a part of the compiler, but is a separate step before the compilation process. 

- The C preprocessor is a macro preprocessor (allows you to define macros) that transforms your program before it is compiled. All preprocessing directives begin with a ```#``` symbol.

### Preprocessing directives
#### Header Files
- A header file is a file with extension .h which contains C function declarations and macro definitions to be shared between several source files.
---
- ```#include``` <filename> is used to insert the contents of the specified file into your source code. Example
```c
#include <stdio.h> standard library headers.
#include "my_header.h" headers specific to your project.
```

- ```#define PI 3.14159``` is used to create a macro that replaces PI by 3.14159
- ```#if <expression>``` include following text only if ```<expression>``` is true. Example

```c
#if DEBUG_MODE == 1  // Example: Conditional inclusion based on a constant
printf("Debug mode is enabled.\n");
#endif
```
- ```#defined(<name>)``` returns 1 if ```<name>``` has been declared by ```#define <name>```, and 0 otherwise.


