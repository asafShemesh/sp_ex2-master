#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX_SIZE 10
 int fakeMatrix[10][10];

int function1(int mat[MAX_SIZE][MAX_SIZE], int size)
{
    //Put the value in the matrixe
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           scanf("%d", &mat[i][j]);
        }
    }
    return 0;
}

void floydWarshall(int mat[MAX_SIZE][MAX_SIZE])
{

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
          fakeMatrix[i][j]=0;
        }
    }
//check it out
    for (int k = 0; k < 10; k++)
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if (mat[i][j] != 0 && mat[i][k] != 0 && mat[k][j] != 0)
                {
                    if(mat[i][j] > mat[i][k] + mat[k][j] || mat[i][j] == 0)
                    {
                        fakeMatrix[i][j] =  mat[i][k] + mat[k][j];
                    }   
                }
            }
        }
    }
}


int isTherePath(int mat[MAX_SIZE][MAX_SIZE], int i, int j)
{
    floydWarshall(mat);
    if (fakeMatrix[i][j] != 0)
    {
        return 1;
    }
    return 0;
}

int theShortestPath(int mat[MAX_SIZE][MAX_SIZE], int i, int j)
{
    floydWarshall(mat);
    if (fakeMatrix[i][j] != 0)
    {
        return fakeMatrix[i][j];
    }
    return -1;
}