#include <stdio.h>
#define MAX 100
/*Author: Ahmed Nuur 
  Date: January 30, 2019
  Student Number: 105031864
*/


/*This function takes an input from the user and gets the values for the square matrix
  This function uses numOfRows, and a matrix using numOfRows as the size
  The function stores the values the user input for each spot in the matrix
*/
void setMatrixData(int numOfRows, int mat[][numOfRows]); //prototype

void setMatrixData(int numOfRows, int mat[][numOfRows]){

for (int i = 0; i < numOfRows; i++){
  for(int j = 0; j < numOfRows; j++){
    printf("Enter a value for (%d,%d): ", i, j);
    scanf("%d", &mat[i][j]);        //stores the user input to the appropriate position
  }
}
}

/*This function takes the inputs from setMatrixData and displays it 
  This function uses the variable numOfRows and the matrix mat
  This function prints the matrix and displays it to the user
*/
void printMatrixData(int numOfRows, int mat[][numOfRows]); //prototype

void printMatrixData(int numOfRows, int mat[][numOfRows]){

for(int i = 0; i < numOfRows; i++){
  for(int j = 0; j < numOfRows; j++){
    printf("%d ", mat[i][j]);     //prints each input from the user in the appropriate position
  }
  puts("");     //starts new row
}
}


/*This function takes the users input's and computes whether or not the matrix is a magic square, but only if the matrix is a distinct square
  This function uses the variable numOfRows and the matrix mat
  This function returns 1 if the matrix is a magic square and otherwise returns 0 
*/
int isMagicSquare(int numOfRows, int mat[][numOfRows]); //prototype

int isMagicSquare(int numOfRows, int mat[][numOfRows]){

int sumDiag = 0;
int sumRow = 0;
int sumCol = 0;
for(int i = 0; i < numOfRows; i++){
  sumRow = 0;     //consantly resetting to only do individual rows and columns not collectively
  sumCol = 0;
  for(int j = 0; j < numOfRows; j++){
    sumRow += mat[i][j];    //sums each value in each row and column
    sumCol += mat[j][i];
  }
}

for(int i = 0; i < numOfRows; i++){
  sumDiag += mat[i][i];
}
if (sumRow == sumCol && sumRow == sumDiag){
  return 1; // if the matrix is a magic square
}
else
  return 0; //if the matrix is not a magic square
}

/*This function takes the inputs from the user and checks whether every value entered is different
  This fucntion uses the inputs numOfRows and the matrix mat
  This function returns 1 if the matrix is a distinct square and returns 0 otherwise
*/
int isDistinctSquare(int numOfRows, int mat[][numOfRows]); //prototype

int isDistinctSquare(int numOfRows, int mat[][numOfRows]){

for(int i = 0; i < numOfRows; ++i){
  for(int j = 0; j < numOfRows; ++j){
    for(int k = 0; k < numOfRows; ++k){ //checks the matrix again
      for (int h = 0; h < numOfRows; ++h){  //checks the matrix again
        if (mat[i][j] == mat[k][h] && mat[j][i] == mat[h][k] && (i != k || j != h)){  //Makes sure it's not looking at the number in the same position
          return 0;
        }
      }
    }
  }
}
return 1; // if the matrix has no duplicates all values are unique
}
/*This function takes the input from the user and sorts the elements in ascending order only in the individual rows
  This function uses the variable numOfRows and it uses the matrix mat
  This function prints the newly sorted matrix
*/
void SortRowWise(int numOfRows, int mat[][numOfRows]); //prototype

void SortRowWise(int numOfRows, int mat[][numOfRows]){
printf("\n");
printf("The Sorted Matrix Looks Like: \n");
for(int i = 0; i < numOfRows; i++){
  int temp = 0;
  for (int j = 0; j < numOfRows; j++){
    for(int k = j+1; k < numOfRows; k++){
      if (mat[i][j] > mat[i][k]){
        temp = mat[i][j];     
        mat[i][j] = mat[i][k];  //swaps the numbers
        mat[i][k] = temp;
      }
    } 
    printf("%d ", mat[i][j]);   //prints every value in each row
  }
  puts("");   //stats a new row
}
}

/*This function takes the input from the user and it swaps the position of the row and column
  This function uses the variable numOfRows, the matrix mat and the new matrix tran
  This function prints the transpose of the matrix mat
*/
void GetTranspose(int numOfRows, int mat[][numOfRows], int tran[][numOfRows]); //prototype

void GetTranspose(int numOfRows, int mat[][numOfRows], int tran[][numOfRows]){
printf("The transpose of the matrix is:\n");
for(int i = 0; i < numOfRows; i++){
  for(int j = 0; j < numOfRows; j++){
    tran[j][i] = mat[j][i];   //swaps the position of row and column
    printf("%d ", tran[j][i]);    //prints every value in each row
  }
  puts("");   //starts a new row
}
}

int main()
{
int numOfRows;
printf("Set the size of your square matrix: ");
scanf("%d", &numOfRows);

int matrix[numOfRows][numOfRows];
int matrix2[numOfRows][numOfRows];    //this matrix is for the transpose

setMatrixData(numOfRows, matrix);

printMatrixData(numOfRows, matrix);

isMagicSquare(numOfRows, matrix);

isDistinctSquare(numOfRows, matrix);

if (isDistinctSquare(numOfRows,matrix) == 1){
  printf("This is a distict matrix\n");
  isMagicSquare(numOfRows, matrix);     //only runs isMagicSquare if matrix is distinct matrix
}
else{
  printf("This is not a distinct matrix\n");
}

if (isMagicSquare(numOfRows,matrix) == 1){
  printf("This is a magic square\n");
}
else{
  printf("This is not a magic square\n");
}

GetTranspose(numOfRows, matrix, matrix2);

SortRowWise(numOfRows, matrix);
}