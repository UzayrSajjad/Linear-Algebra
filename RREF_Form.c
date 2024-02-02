// Conversion of a matrix to reduced row echelon matrix 

#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to print a matrix
void printMatrix(float mat[][COLS], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.1f\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Row Echelon Form (REF) transformation
void REF(float mat[][COLS], int row, int col) {
    int pivotRow = 0; // Initialize the pivotRow to keep track of the current row with a pivot element.

    for (int pivotCol = 0; pivotCol < col; pivotCol++) {
        int nonZeroPivotRow = -1; // Initialize to -1 to indicate that no non-zero pivot row has been found yet.

        // Find the first row with a non-zero element in the current pivot column.
        for (int i = pivotRow; i < row; i++) {
            if (mat[i][pivotCol] != 0) {
                nonZeroPivotRow = i; // Update nonZeroPivotRow to the found row index.
                break;
            }
        }

        if (nonZeroPivotRow == -1) {
            continue; // If no non-zero pivot row is found, move to the next pivot column.
        }

        // Swap the current pivotRow with the non-zero pivot row.
        for (int j = 0; j < col; j++) {
            float temp = mat[pivotRow][j];
            mat[pivotRow][j] = mat[nonZeroPivotRow][j];
            mat[nonZeroPivotRow][j] = temp;
        }

        float pivotValue = mat[pivotRow][pivotCol]; // Store the pivot value for normalization.

        // Normalize the current pivot row by dividing all its elements by the pivot value.
        for (int j = 0; j < col; j++) {
            mat[pivotRow][j] /= pivotValue;
        }

        // Eliminate non-zero elements in the current pivot column above and below the pivot.
        for (int i = 0; i < row; i++) {
            if (i != pivotRow) {
                float ratio = mat[i][pivotCol];
                for (int j = 0; j < col; j++) {
                    mat[i][j] -= ratio * mat[pivotRow][j];
                }
            }
        }

        pivotRow++; // Move to the next pivotRow for the next iteration.
    }
}

// Function to perform Reduced Row Echelon Form (RREF) transformation
void RREF(float mat[][COLS], int row, int col) {
    REF(mat, row, col);

    for (int i = 0; i < row; i++) {
        int pivotCol = -1;
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 1) {
                pivotCol = j;
                break;
            }
        }

        if (pivotCol != -1) {
            // Use back-substitution to eliminate non-zero elements above the pivot in the current column.
            for (int k = 0; k < i; k++) {
                float ratio = mat[k][pivotCol];
                for (int j = 0; j < col; j++) {
                    mat[k][j] -= ratio * mat[i][j];
                }
            }
        }
    }
}

// Main function
int main() {
    float mat[ROWS][COLS];

    // Input matrix elements from the user
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter the [%d,%d] element: ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
    }

    printf("Your Matrix is: \n");
    printMatrix(mat, ROWS, COLS);

    // Perform RREF transformation
    RREF(mat, ROWS, COLS);

    printf("\nReduced Row Echelon form is:\n\n");
    printMatrix(mat, ROWS, COLS);

    return 0;
}
