// Finding determinant of a 3 by 3 matrix

#include <stdio.h>

int main() {

    double a[3][3];
    int i, j;
    double det = 0;

    // Input matrix elements
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter the [%d][%d] element: ", i, j);
            scanf("%lf", &a[i][j]);  // Use %lf for double input
        }
    }

    // Display matrix
    printf("Entered matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%lf\t", a[i][j]);  // Use %lf for double output
        }
        printf("\n");
    }

    // Calculate determinant
    det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
          a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
          a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

    printf("Determinant of the matrix is: %lf", det);

    return 0;
}
