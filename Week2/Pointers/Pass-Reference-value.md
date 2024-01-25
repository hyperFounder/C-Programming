### Pass by Value
- C always uses 'pass by value' to pass arguments to functions, which means the code within a function cannot alter the arguments used to call the function, even if the values are changed inside the function.

### Example
- The code returns ```a=4, b=5```.
- This is because local variables use Stack "temporarily". They are only active within their functions.
```c
void swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 4, b = 5;
    swap(a,b);
    printf("a=%d \nb=%d",a,b);
    return 0;
```
### Pass by reference
- We can pass pointers to a function as arguments. This is known as pass-by-reference.
- Passing by reference literally just means passing the memory address of where a variable is stored rather than the variable's value itself.

#### Example
- To swap to integers:
```c
void swap(int *p1, int *p2){
    int temp = *p1;
    *p1=*p2;
    *p2 = temp;
}
int main(){ // int *p = &c
   int a=4, b=5;
   swap(&a,&b);
   printf("a: %d, b: %d", a, b); //a: 5, b: 4
}
```
