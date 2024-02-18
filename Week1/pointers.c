#include <stdio.h>

void ptop(){
  int var = 3000;
  int *ptr = &var;
  int **pptr = &ptr;

  printf("value of var %d\n", var);
  *ptr = *ptr + 10;
  printf("value of var %d\n", var);
  printf("value at *ptr = %d\n", *ptr);
  printf("value at **pptr=%d\n", **pptr);
}

void first(){
    int num = 10;

    int *ptr = &num;

    printf("ptr: %d\n", *ptr);

    printf("Original value: %d\n", num);

    *ptr = 20;

    printf("Modified (num) value: %d", num);
}

void loopArr(){
    int arr[] = {1,2,3,4,5};
    int *ptr = &arr[0]; // int*ptr = arr
    int a = sizeof arr / sizeof (arr[0]); // 20 / 4

    for (int i =0; i<a; i++){
        printf("a: %d\t", *ptr);
        ptr++;
    }
}


void sumArr(){
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;
    int sum = 0;
    for (int i =0; i<4; i++){
        sum = sum + *(ptr + i); // sum = sum + arr[i]
    }
    printf("sum: %d", sum);
}

// Sum of each row in a 2d array

void sumArr2(){
    int rows = 3, cols = 4;
    int matrix[3][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    for (int i = 0; i<rows; i++){
        int row = 0;
        for (int j=0; j<cols; j++){
            row += matrix[i][j];
        }
        printf("sum row[%d]: %d\n", i, row);
    }
}

// Sum of each column

void sum3(){
  int matrix[2][3] = {
    {1, 4, 2},
    {3, 6, 8}
  };
  for (int j = 0; j<3; j++){
    int sum =0;
    for (int i = 0; i<2; i++){
      sum += matrix[i][j];
    }
    printf("sum column %d is %d\n", j, sum);
  }
}

// Total sum

void total(){
    int rows = 3, cols = 4;
    int matrix[3][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12}};
    int sum =0;

    for (int i=0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            sum = sum + matrix[i][j];
        }
    }
    printf("Total sum: %d", sum);
}

// Diagonal sum

void diagonal(){
    int rows, cols = 3;
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int size = 3;
    int sum =0;

    for(int i =0; i< size; i++){
        sum = sum + matrix[i][i];
    }
    printf("sum: %d", sum);
}

// Print the entire array in row major order

void rowMajor(){
    int row = 3;
    int column = 4;

    int a[3][4] = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12}
    };

    for (int i = 0; i< 3; i++){
        for (int j =0; j<4; j++){
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }
}

// Pointers to print row-major order

void rowMajor2(){
    int a[3][4] = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12}
    };
    int *ptr = a;

    for(int i = 0; i<12; i++){
        printf("%d\n", *(ptr+i));
    }
}


int main() {
    myfirst();
    return 0;
}
