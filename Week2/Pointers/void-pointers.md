### Void pointers
- A void pointer in C has no associated data type. aka generic pointers
```c
void *ptr;
```
- reusability purposes: It can store the address of any type of object. They can also be type-casted to any types (but the type must be specified while dereferencing)
#### Example
```c
int main(){
    void *pv;
    int iData = 5;
    int cData = 'C';
    
    pv = &cData; // pointer to char
    printf("cData = %c\n", *(char *)pv);
    
    pv = &iData;
    printf("iData = %d", *(int *)pv);
}
```
### Arithmetic on void pointers

```c
int main(){
    int a[4] = {1,5,13,4};
    void *pv = &a[0];
    pv = (int *)pv + 1; // pv = pv + 1 is Wrong. Do not forget to type cast
    printf("Value: %d \n", *((int *)pv));
    return 0;
}
```
