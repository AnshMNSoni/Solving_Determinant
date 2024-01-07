// Determinant n X n:

#include <stdio.h>

// To calculate determinant:

int determinant(int n, int mat[n][n])
{
    int det = 0;
    int sign = 1; //To alternate the sign i.e +1 or -1

    // if matrix of order 1:

    if (n == 1)
    {
        return mat[1][1]; 
    }

    // if matrix of order 2:

    else if (n == 2)
    {
        return mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];
    }

    // if matrix of order more than 2:
    
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int sub_matrix[n - 1][n - 1];

            for (int row = 2; row <= n; row++)
            {
                int sub_col = 1;

                for (int col = 1; col <= n; col++)
                {
                    if (col != i)
                    {
                        sub_matrix[row - 1][sub_col] = mat[row][col];
                        sub_col++;
                    }
                }
            }
            det = det + sign * mat[1][i] * determinant(n-1, sub_matrix); 
            sign = -sign;
        }

        return det;
    }
}

int main()
{
    int rows;
    printf("Enter the number of rows you want in Matrix: ");
    scanf("%d", &rows);

    int columns;
    printf("Enter the number of columns you want in Matrix: ");
    scanf("%d", &columns);

    int matrix[rows][columns];
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            printf("Enter element a%d%d = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    if (rows == columns)
    {
        printf("Determinant = %d", determinant(rows, matrix));
    }
    
    else
    {
        printf("To calculate Determinant, rows = columns (i.e Square Matrix).");
    }

    return 0;
}
