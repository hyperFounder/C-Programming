#include <stdio.h>
#include <string.h>

// Reading an integer

void readingInt(){
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("You entered: %d\n", num);

}

// Strings are a 1d array of characters
// each char (1 byte) is stored in consecutive memory locations
// sscanf() -> string scanf

void string(){

    char data[] = "John Doe";
    char name[20];
    // get only first name
    int result = sscanf(data, "%s", name);
    if (result == 1){
        printf("First Name: %s\n", name);
    }
}

// Print a string using pointers

void printString(){
    char name[] = "Comp Sc"; // char *ptr = "Comp Sci"
    char *ptr = &name[0];
    while (*ptr!= '\0'){
        printf("%c", *ptr);
        ptr++;
    }
}

// Similar definition:

void printString2(){
    char *ptr = "Comp Sc"; // char name[] = "Comp Sc"
    while (*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
    }
}

// Segmentation fault...
void idk3(){
    char *ptr = "Comp Sc";
    *ptr = 'c'; // Why is this wrong? A string is stored in the read-only section of the program...
    // any attempts to modify it will cause segmentation fault
    while (*ptr != '\0'){
        printf("%c",*ptr);
        ptr++;
    } // returns Comp Sc
}

// String Library

void stringCopy(){
    char src[400];
    char dest[400];

    printf("Enter source string: ");
    scanf("%[^\n]", src);
    strcpy(dest, src);
    printf("Destination string: %s\n", dest);

    // Concat two strings

    char str[100] = "Hello ";
    strcat(str, "World");
    printf("New string: %s\n", str);

    // Length of string

    int n = strlen(str);
    printf("n = %d", n);
}

void fget(){
    char src[400];
    char dest[100];

    printf("Enter source string: ");
    fgets(src, 40, stdin);

    strcpy(dest, src);

    printf("dest str: %s", dest);
}

int main(){
    fget();
    return 0;
}
