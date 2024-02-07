#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main()
{
    char tempChar;
    int i = 0, j = 0;
    int matrix[10][10];

    do
    {
        scanf("%c", &tempChar);

        switch (tempChar)
        {
        case 'A':
        {
            function1(matrix, 10);
            break;
        }

        case 'B':
        {
            scanf("%d%d", &i, &j);
            printf("%s\n", isTherePath(matrix, i, j) ? "True" : "False");
            break;
        }

        case 'C':
        {
            scanf("%d%d", &i, &j);
            printf("%d\n", theShortestPath(matrix, i, j));
            break;
        }

        default:
            break;
        }
    } while (tempChar != 'D');

    return 0;
}