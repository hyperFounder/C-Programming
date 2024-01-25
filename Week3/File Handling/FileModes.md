### File modes

- ```r``` Open file for reading.
- - If the file does not exist, ```fopen()``` returns NULL.
- - The pointer points to the first character in the file.
- ```w```	Open for writing. 
- - If the file does not exist, it will be created.
- - If the file exists, its contents are overwritten.
- ```a``` Open for append.
- - If the file does not exist, it will be created.
- - The pointer points to the last character in the file.

#### Additional modes

- ```r+``` Open for both reading and writing.
- - If the file does not exist, ```fopen()``` returns NULL.
- ````w+```` Open for both reading and writing.
- - If the file does not exist, it will be created.
- - If the file exists, its contents are overwritten.
- ```a+``` Open for both reading and appending.
- - If the file does not exist, it will be created.