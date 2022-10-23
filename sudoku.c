#include <stdio.h>

#define LENGTH 9

// 2d array to hold sudoku

int sudoku[LENGTH][LENGTH] = {
    {4, 0, 1, 2, 9, 0, 0, 7, 5}, {2, 0, 0, 3, 0, 0, 8, 0, 0},
    {0, 7, 0, 0, 8, 0, 0, 0, 6}, {0, 0, 0, 1, 0, 3, 0, 6, 2},
    {1, 0, 5, 0, 0, 0, 4, 0, 3}, {7, 3, 0, 6, 0, 8, 0, 0, 0},
    {6, 0, 0, 0, 2, 0, 0, 3, 0}, {0, 0, 7, 0, 0, 1, 0, 0, 4},
    {8, 9, 0, 0, 6, 5, 1, 0, 7}};

int square[LENGTH][LENGTH] = {
    {1, 1, 1, 2, 2, 2, 3, 3, 3}, {1, 1, 1, 2, 2, 2, 3, 3, 3},
    {1, 1, 1, 2, 2, 2, 3, 3, 3}, {4, 4, 4, 5, 5, 5, 6, 6, 6},
    {4, 4, 4, 5, 5, 5, 6, 6, 6}, {4, 4, 4, 5, 5, 5, 6, 6, 6},
    {7, 7, 7, 8, 8, 8, 9, 9, 9}, {7, 7, 7, 8, 8, 8, 9, 9, 9},
    {7, 7, 7, 8, 8, 8, 9, 9, 9},
};

int row_array[LENGTH];
int column_array[LENGTH];
int quad_array[LENGTH];

void print_sudoku();
void getRow(int row);
void getColumn(int column);

int findQuad(int row, int column);
void getQuad(int quad);

int main(int argc, char *argv[]) {
  print_sudoku();

  return 0;
}

void print_sudoku() {
  int i = 0;
  int j = 0;
  for (i = 0; i < LENGTH; ++i) {
    for (j = 0; j < LENGTH; ++j) {
      printf("%d", sudoku[i][j]);
      if (j == 2 | j == 5) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("\n");
    if (i == 2 | i == 5) {
      printf("- - - - - - - - -\n");
    }
  }
}

void getRow(int row) {
  for (int i = 0; i < LENGTH; i++) {
    row_array[i] = sudoku[row][i];
  }
}

void getColumn(int column) {
  for (int i = 0; i < LENGTH; i++) {
    column_array[i] = sudoku[i][column];
  }
}

int findQuad(int row, int column) { return square[row][column]; }

void getQuad(int quad) {
  switch (quad) {

  case 1:
    quad_array[0] = sudoku[0][0];
    quad_array[1] = sudoku[0][1];
    quad_array[2] = sudoku[0][2];
    quad_array[3] = sudoku[1][0];
    quad_array[4] = sudoku[1][1];
    quad_array[5] = sudoku[1][2];
    quad_array[6] = sudoku[2][0];
    quad_array[7] = sudoku[2][1];
    quad_array[8] = sudoku[2][2];
    break;

  case 2:
    quad_array[0] = sudoku[0][3];
    quad_array[1] = sudoku[0][4];
    quad_array[2] = sudoku[0][5];
    quad_array[3] = sudoku[1][3];
    quad_array[4] = sudoku[1][4];
    quad_array[5] = sudoku[1][5];
    quad_array[6] = sudoku[2][3];
    quad_array[7] = sudoku[2][4];
    quad_array[8] = sudoku[2][2];
    break;

  case 3:
    quad_array[0] = sudoku[0][6];
    quad_array[1] = sudoku[0][7];
    quad_array[2] = sudoku[0][8];
    quad_array[3] = sudoku[1][6];
    quad_array[4] = sudoku[1][7];
    quad_array[5] = sudoku[1][8];
    quad_array[6] = sudoku[2][6];
    quad_array[7] = sudoku[2][7];
    quad_array[8] = sudoku[2][8];
    break;

  case 4:
    quad_array[0] = sudoku[3][0];
    quad_array[1] = sudoku[3][1];
    quad_array[2] = sudoku[3][2];
    quad_array[3] = sudoku[4][0];
    quad_array[4] = sudoku[4][1];
    quad_array[5] = sudoku[4][2];
    quad_array[6] = sudoku[5][0];
    quad_array[7] = sudoku[5][1];
    quad_array[8] = sudoku[5][2];
    break;

  case 5:
    quad_array[0] = sudoku[3][3];
    quad_array[1] = sudoku[3][4];
    quad_array[2] = sudoku[3][5];
    quad_array[3] = sudoku[4][3];
    quad_array[4] = sudoku[4][4];
    quad_array[5] = sudoku[4][5];
    quad_array[6] = sudoku[5][3];
    quad_array[7] = sudoku[5][4];
    quad_array[8] = sudoku[5][5];
    break;

  case 6:
    quad_array[0] = sudoku[3][6];
    quad_array[1] = sudoku[3][7];
    quad_array[2] = sudoku[3][8];
    quad_array[3] = sudoku[4][6];
    quad_array[4] = sudoku[4][7];
    quad_array[5] = sudoku[4][8];
    quad_array[6] = sudoku[5][6];
    quad_array[7] = sudoku[5][7];
    quad_array[8] = sudoku[5][8];
    break;

  case 7:
    quad_array[0] = sudoku[6][0];
    quad_array[1] = sudoku[6][1];
    quad_array[2] = sudoku[6][2];
    quad_array[3] = sudoku[7][0];
    quad_array[4] = sudoku[7][1];
    quad_array[5] = sudoku[7][2];
    quad_array[6] = sudoku[8][0];
    quad_array[7] = sudoku[8][1];
    quad_array[8] = sudoku[8][2];
    break;

  case 8:
    quad_array[0] = sudoku[6][3];
    quad_array[1] = sudoku[6][4];
    quad_array[2] = sudoku[6][5];
    quad_array[3] = sudoku[7][3];
    quad_array[4] = sudoku[7][4];
    quad_array[5] = sudoku[7][5];
    quad_array[6] = sudoku[8][3];
    quad_array[7] = sudoku[8][4];
    quad_array[8] = sudoku[8][5];
    break;

  case 9:
    quad_array[0] = sudoku[6][6];
    quad_array[1] = sudoku[6][7];
    quad_array[2] = sudoku[6][8];
    quad_array[3] = sudoku[7][6];
    quad_array[4] = sudoku[7][7];
    quad_array[5] = sudoku[7][8];
    quad_array[6] = sudoku[8][6];
    quad_array[7] = sudoku[8][7];
    quad_array[8] = sudoku[8][8];
    break;
  }
}
