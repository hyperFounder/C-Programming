### File Handling and Error Handling 
```c
- fopen()	Used to open an existing file or to create a new file
- fprintf()	Used to write data in existing file	
- fscanf()	Used to read data from the file	
- fputc()	Used to write characters in a file	
- fputs()       Used to write a string to a file
- fgetc()	Used to read characters from a file
- fclose()	Used to close existing file	
- fseek()	puts the file pointer to the specified place	
- fputw()	Used to write integral value in the file	
- fgetw()	Used to read integral value from the file	
- ftell()	It will return the current position of the file pointer in the file	f
- rewind()	the file pointer is set to the start of the file
```
### Opening and Closing a file

- For opening a file, fopen() function is used with the required access modes.
```c
FILE *fp; // variable fp is a pointer to type FILE
fp = fopen("filename", "mode");
```
- ```fopen()``` returns ```NULL``` if it is unable to open the specified file.
- An opened file is closed by ```fclose(fp)```


## Reading or writing files
##### ```fprintf()``` and ```fscanf()``` 
- Both methods can be used for reading/writing to files. 
- Both are just the file versions of ```printf()``` and ```scanf()```. 
- The only difference is that ```fprintf()``` and ```fscanf()``` expects a pointer to the structure FILE.

### Example - Write to a file  - ```fprintf```
- This program takes a number from the user and stores in the file ```program.txt```.
```c
int main(){
    int num;
    FILE *fptr = fopen("program.txt", "w");
    if (fptr == NULL){
        printf("Error!");
        exit(1);
    }
    printf("Enter num: ");
    scanf("%d", &num);
    fprintf(fptr, "%d", num);
    fclose(fptr);
    return 0;
}
```
### Example - Read from a file - ```fscanf```
- This program reads the integer present in ```program.txt``` file and prints it onto the screen.
```c
int main()
{
   int num;
   FILE *fptr;
   if ((fptr = fopen("program.txt","r")) == NULL){
       printf("Error!");
       exit(1);
   }
   fscanf(fptr,"%d", &num);
   printf("Value of n=%d", num);
   fclose(fptr); 
   return 0;
}
```
## Module Programming Examples
### Example I

- This is a program to copy all characters from file ```a``` to file ```b```.
- ```getc()``` read a char from a file
- ```putc()``` write a char to a file

```c
int main(){
    FILE *fp0, *fp1;
    fp0 = fopen("infile.txt", "r");
    fp1 = fopen("outfile.txt", "w");
    if (fp0 == NULL || fp1 == NULL){
        printf("Cannot open files \n");
        exit(-1);
    }
    char ch = getc(fp0); // reads one char from first file
    while (ch != EOF){
        printf("%c",ch);
        putc(ch,fp1);
        ch = getc(fp0);
    }
    fclose(fp0);
    fclose(fp1);
    return 0;
}
```
### Example II 

- This is a program to copy all characters from file ```a``` to file ```b```.

```c
int main()
{
   char *line = NULL;
   size_t n;
   FILE *fp0, *fp1;
   int res;

   fp0 = fopen("infile.txt", "r");
   fp1 = fopen("outfile.txt", "w");
   if (fp0 == NULL || fp1 == NULL){
    printf("Cannot open files\n");
    exit(1);
   }

   while ((res = getline(&line, &n, fp0)) != -1){
    fprintf(fp1, "%s", line);
   }

   fclose(fp0);
   fclose(fp1);
   return 0;
}
```


