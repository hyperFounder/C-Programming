### Structures

- Structure in C is a user-defined composite data type. 
- It is used to unite different data types into a single type. 
- The structure is created using the ```struct``` keyword

### Example

```c
struct Student{
    int studentId;
    char name[50];
    float grade;
};
int main(){
    struct Student a;
    a.studentId = 01;
    a.grade = 8.0;
    printf("Student id %d\n", a.studentId);
    printf("Grade is %.2f\n", a.grade);
    return 0;
}

```

### Keyword```typedef``` 

- When used with structures, ```typedef``` allows you to define a structure and simultaneously create a new type name for that structure. This can make your code more readable and concise.

- Example:
```c
#include <stdio.h>

// Define the structure
typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

int main() {
    // Declare a variable of the typedef'd struct
    Employee emp1;

    // Assign values to the struct members
    emp1.id = 1;
    snprintf(emp1.name, sizeof(emp1.name), "John");
    emp1.salary = 50000.0;

    // Access and print the values
    printf("Employee ID: %d\n", emp1.id);
    printf("Employee Name: %s\n", emp1.name);
    printf("Employee Salary: %.2f\n", emp1.salary);

    return 0;
}

```

### Pointer to a structure object (->)

- The arrow operator ```(->)``` in C is used to access members of a structure or a union through a pointer to that structure or union. 
- It provides a shorthand way of accessing members when you have a pointer to a structure, making the code more concise.
- In this example ```ptrStudent->studentId``` is equivalent to ```(*ptrStudent).studentId```
- Example:

```c
#include <stdio.h>

// Define a structure
struct Student {
    int studentId;
    char name[50];
    float grade;
};

int main() {
    // Declare a variable of type struct Student
    struct Student student1;

    // Declare a pointer to a struct Student
    struct Student *ptrStudent;

    // Assign values to the members of student1
    student1.studentId = 1;
    strcpy(student1.name, "John Doe");
    student1.grade = 85.5;

    // Assign the address of student1 to ptrStudent
    ptrStudent = &student1;

    // Access members using the arrow operator
    printf("Student ID: %d\n", ptrStudent->studentId);
    printf("Name: %s\n", ptrStudent->name);
    printf("Grade: %.2f\n", ptrStudent->grade);

    return 0;
}

```