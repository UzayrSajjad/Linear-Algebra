// Finding inverse of a 3 by 3 matrix

#include <stdio.h>

// Function to calculate the determinant of a 3x3 matrix
int determinant(int matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

// Function to display a matrix
void displayMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int a[3][3];
    double adj[3][3];  // Adjugate matrix
    int det;

    // Input matrix elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter the [%d][%d] element: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Display matrix
    printf("Entered matrix:\n");
    displayMatrix(a);

    // Calculate determinant
    det = determinant(a);

    printf("Determinant of the matrix is: %d\n", det);

    // Check if the determinant is zero
    if (det == 0) {
        printf("The matrix is singular, and its inverse does not exist.\n");
        return 1;
    }

    // Calculate the adjugate matrix
    adj[0][0] = a[1][1] * a[2][2] - a[1][2] * a[2][1];
    adj[0][1] = -(a[1][0] * a[2][2] - a[1][2] * a[2][0]);
    adj[0][2] = a[1][0] * a[2][1] - a[1][1] * a[2][0];
    adj[1][0] = -(a[0][1] * a[2][2] - a[0][2] * a[2][1]);
    adj[1][1] = a[0][0] * a[2][2] - a[0][2] * a[2][0];
    adj[1][2] = -(a[0][0] * a[2][1] - a[0][1] * a[2][0]);
    adj[2][0] = a[0][1] * a[1][2] - a[0][2] * a[1][1];
    adj[2][1] = -(a[0][0] * a[1][2] - a[0][2] * a[1][0]);
    adj[2][2] = a[0][0] * a[1][1] - a[0][1] * a[1][0];

    // Calculate the inverse matrix
    printf("Inverse matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%1f\t", adj[j][i] / det); // [j][i], swapping values for resulting transpose
        }
        printf("\n");
    }

    return 0;
}

