
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addition_subtraction(int rows, int cols, int **,int **);

int main()
{
  int rows, cols, i, j;
  int number = 100;

  rows = 10;
  cols = 10;

  int array_2D[rows][cols];
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      array_2D[i][j] = number++;
    }
    }
  int *a[rows];
  for (i = 0; i < rows; i++) {
      a[i] = array_2D[i];
  }
    clock_t t;
    t = clock();

    addition_subtraction(rows, cols, a,a);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("funtion took %f seconds to execute \n", time_taken);
    return 0;


  exit(EXIT_SUCCESS);
}

void addition_subtraction(int rows, int cols, int **a, int **b)
{
  int i, j;
  int n, m;

  n = rows;
  m = cols;

  printf("\nPrint array 1 with %d rows and %d columns\n", rows, cols);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("array[%d][%d] = %d ", i, j, a[i][j]);
    }
    printf("\n");
  }
  printf("\nPrint array 2 with %d rows and %d columns\n", rows, cols);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("array[%d][%d] = %d ", i, j, b[i][j]);
    }
    printf("\n");
  }

  printf("\narray 1 and array 2 addition  \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
    {
      printf("array[%d][%d]= %d ", i, j, b[i][j]+a[i][j]);
    }
    printf("\n");
  }

    printf("\narray 1 and array 2 subtraction  \n");
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
      {
        printf("array[%d][%d]= %d ", i, j, b[i][j]-a[i][j]);
      }
      printf("\n");
    }


}
