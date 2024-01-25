### Standard Input/Output Functions in C 

- ```getchar()``` reads characters from the standard input
- ```putchar()``` writes a character to standard output
- ```getline()``` is used to read a line of text from standard input

#### Running examples

- ```getchar()``` and ```putchar()```
```c
int main(){
    printf("Enter a character: ");
    char c = getchar();
    printf("Character entered: ");
    putchar(c);
    return 0;
}
```
#### Note
- ```size_t``` is an unsigned integer data type which can assign only 0 and greater than 0 integer values.

- ```getline()```
```c
int main(){
    char *str = NULL;
    size_t n;
    printf("Enter a string: ");
    int res = getline(&str, &n, stdin);
    if (res != -1){
        printf("%s",str);
    }
    return 0;
}
```