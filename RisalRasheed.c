//Programming Language C
#include<stdio.h>
#include<stdlib.h>
//Funtion to Display
void displayMatrix(int* matrix, int N) {

  for(int i = 0; i<N; i++) {
    for(int j = 0 ; j<N ; j++)
      printf(" %d",*(matrix + N*i + j));
    printf("\n");
  }
}
//Function to find Transpose
void transposeMatrix(int* Matrix, int N, int L) {

  int temp;

  for(int i = 0; i<L; i++) {
    for(int j = 0; j<i; j++) {
      temp = *(Matrix + i*N + j);
      *(Matrix+ i*N + j) = *(Matrix + j*N + i);
      *(Matrix + j*N + i) = temp;
    }
  }
}

void main() {

  short int N,count = 0;
  int *matrix, *reqfirstrow;
  //reqfirstrow is the first row of the correct matrix
  scanf("%hi", &N);

  matrix = (int*)malloc(sizeof(int)*(N*N));
  reqfirstrow = (int*)malloc(sizeof(int)*N);

  for(int i = 0; i<N; i++) {
    //initialising required first row
    *(reqfirstrow+i) = i+1;
    //Reading the matrix from user
    for(int j = 0; j<N; j++)
      scanf("%d",(matrix+N*i+j));
  }

  for(int i = N-1; i>=0; i--) {
    //Checking for positions of required Transpose
    if(*(reqfirstrow+i) != *(matrix+i)) {
      transposeMatrix(matrix,N,i+1);
      count++;
    }
  }

  printf("%d",count);

}
