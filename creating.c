#include <stdio.h>
#include <stdlib.h>
// creating array-------------------------------------------
//  int main()
//  {
//      int A[5] = {2, 4, 6, 8, 10};
//      int *p;
//      int i;
//      p = malloc(5 * sizeof(int));
//      p[0] = 3;
//      p[1] = 5;
//      p[2] = 7;
//      p[3] = 9;
//      p[4] = 11;
//      for (i = 0; i < 5; i++)
//      {
//          printf("%d ", A[i]);
//      }
//      printf("\n");
//      for (i = 0; i < 5; i++)
//      {
//          printf("%d ", p[i]);
//      }
//      return 0;
//  }

// increasing array size-------------------------------------
// int main()
// {
//     int *p, *q;
//     int i;
//     p = (int *)malloc(5 * sizeof(int));
//     p[0] = 3;
//     p[1] = 5;
//     p[2] = 7;
//     p[3] = 9;
//     p[4] = 11;
//     q = (int *)malloc(10 * sizeof(int));
//     for (i = 0; i < 5; i++)
//     {
//         q[i] = p[i];
//     }
//     free(p);
//     p = q;
//     q = NULL;
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d ", p[i]);
//     }
//     return 0;
// }

// 2d arrays------------------------------------------------
int main()
{
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};
    int *B[3];
    int **C;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    C = (int **)malloc(3 * sizeof(int));
    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
