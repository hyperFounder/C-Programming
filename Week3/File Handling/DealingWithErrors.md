## Typical File Errors

- Tries to read beyond ```EOF```
- Opens with invalid filename
- Tries to read a file that has not been opened
- Uses a wrong mode of operation on file:
```c
#include <stdio.h>

fp = fopen("file.txt", "r");
fprintf(fp, "%d", i); // Is Wrong!!!
```

## Dealing with errors...

- We don't have any direct support of error handling in C language but there are some functional methods used to handle errors while performing file operations: 
- ```perror(), strerror(), ferror(), feof(), clearerr() and Exit status.``` 

### ```perror() messages```
- It stands for print error and when called by the user, it displays a message describing about the most recent error that occured in the code.

```c
int main(){
    FILE* fp;
    fp = fopen("test.txt","r");
    
    if(fp==NULL){ //Error handling
        perror("Message from perror"); // No such file or directory
        return -1;
    }
    fclose(fp);
    return 0;
}
```

### ```ferror(fp)```

- This function basically checks for error in the file stream. 
- It returns zero value if there is no error or else, it returns a positive non-zero value in case of error.
- In the following code, we are trying to read data, despite of writing mode opened, which results in an error
```c
#include <stdio.h>
 
int main(){
   FILE *fp;
   fp = fopen("test.txt","w");

   char ch = getc(fp); //Trying to read data
   if(ferror(fp)){ // Error
      perror("Error Message from perror");
   }
   fclose(fp);
   return(0);
}
```

### ```feof(fp)```
- It returns a non-zero value when EOF is reached, else returns zero
```c
fp = fopen("file.txt", "r");

if (feof(fp)){
    printf("End of file");
}

```