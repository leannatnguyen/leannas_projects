#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MATRIX_ROWS = 5;
const int MATRIX_COLS = 4;

void print_matrix(int mat[MATRIX_ROWS][MATRIX_COLS]){
     for (int row = 0; row < MATRIX_ROWS; row++){
        printf("%d:\t", row);
        for (int col = 0; col < MATRIX_COLS; col++){
            printf("%x ", mat[row][col]);
        }
        printf("\n");
    }
}


int main(int argc, char **argv){
    int matrix[MATRIX_ROWS][MATRIX_COLS]; //local variable

    matrix[0][3] = 12;

    for (int row = 0; row < MATRIX_ROWS; row++){
        for (int col = 0; col < MATRIX_COLS; col++){
            matrix[row][col] = ((row << 16) | col); //shift row to the left by 16 and OR with col #
        }
    }
    printf("sizeof(matrix) = %lu\n", sizeof(matrix));
    print_matrix(matrix);
    return 0;
}