### Random Access to a File
- File resides in Disk and read/write are slow
- Data in a file is basically a collection of bytes.
- We can directly jump to a target byte-number in a file without reading previous data using ```fseek()```
---
- Syntax: ```fseek(fp, offset, position);```
- position: 0 (beginning_of_file), 1 (current_fp_position), 2 (end_of_file)
- offset: number of locations to move from specified position

- Examples:
```text
fseek(fp, m, 0); // move to (m+1)th byte in file (from the start)
fseek(fp, -m, 1); // move back by m bytes from current fp
```
---
- ```ftell(fp)``` returns current byte position in file
- ```rewind(fp)``` resets position to start of file

### Example

- Remember, in C a ```char``` is by definition 1 byte in size.

```c
int main () {
    FILE *fp;

    fp = fopen("file.txt","w+");
    fputs("This is something", fp);

    fseek( fp, 7, 0); // move to 8th byte in file
    fputs(" C Language", fp);
    fclose(fp);

    return(0);
}
```
- The program writes "This is something" to a ```file.txt```, then moves to the ```8th``` byte in file and writes " C Language".

### Example II

```c
int main () {
    FILE *fp;

    fp = fopen("file.txt","w+");
    fputs("This is something", fp);
    fseek(fp, 7,0); // move to 8th byte in file

    fseek( fp, -1, 1); // move back 1 byte
    fputs(" C Language", fp);
    fclose(fp);

    return(0);
}
```
- Outputs: ```This i C Language```