#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int k = 1;
    int row, col;
    int **first_matrix = NULL;
    int **second_matrix = NULL;
    int **result_matrix = NULL;
    /*입력받는 부분*/
    printf("Enter the size of the row of the matrix. : ");
    scanf("%d", &row);
    printf("Enter the size of the column of the matrix. : ");
    scanf("%d", &col);
    /*첫번째 행렬 메모리 할당*/
    first_matrix = (int **)malloc(row * sizeof(int *));
    for(i=0; i<row; i++)
    {
        first_matrix[i] = (int *)malloc(col * sizeof(int));
    }
    if (first_matrix == NULL)
    {
        printf("First memory allocation error.");
        exit(-1);
    }
    /*두번째 행렬 메모리 할당*/
    second_matrix = (int **)malloc(row * sizeof(int *));
    for(i=0; i<row; i++)
    {
        second_matrix[i] = (int *)malloc(col * sizeof(int));
    }
    if (second_matrix == NULL)
    {
        printf("Second memory allocation error.");
        exit(-1);
    }

    printf("%d %d", row, col);

    printf("\n Making value of first matrix automatically \n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            first_matrix[i][j] = k;
            k++;
        }
    }

    k = 1;

    printf("\n Making value of second matrix automatically \n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            second_matrix[i][j] = k;
            k++;
        }
    }
    /* 1번째 행렬 출력*/
    printf("\nThe first matrix.\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            printf("%d  ", first_matrix[i][j]);
        }
        printf("\n");
    }
    /* 2번째 행렬 출력*/
    printf("\nThe second matrix.\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            printf("%d  ", second_matrix[i][j]);
        }
        printf("\n");
    }
    /*결과 행렬 생성*/
    result_matrix = (int **)malloc(row * sizeof(int *));
    for(i=0; i<row; i++)
    {
        result_matrix[i] = (int *)malloc(col * sizeof(int));
    }
    if (result_matrix == NULL)
    {
        printf("Failed to allocate memory to result matrix.");
        exit(-1);
    }
    /* 더하는 부분*/
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            result_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
        }
    }
    /* 더했다는걸 보여주는 부분*/
    printf("\nThe result of adding two matrices.\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            printf("%d  ", result_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    /* 메모리 할당 해제*/
    for (j=0; i<row; j++)
    {
        free(first_matrix[j]);
        free(second_matrix[j]);
        free(result_matrix[j]);
    }
    free(first_matrix);
    free(second_matrix);
    free(result_matrix);

    return 0;
}