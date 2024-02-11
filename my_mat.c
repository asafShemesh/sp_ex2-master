#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX_SIZE 10
int fakeMatrix[MAX_SIZE][MAX_SIZE];

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

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
          fakeMatrix[i][j]=mat[i][j];
        }
    }
//check it out
    for (int k = 0; k < MAX_SIZE; k++)
    {
        for(int i = 0; i < MAX_SIZE; i++)
        {
            for(int j = 0; j < MAX_SIZE; j++)
            {
                if ( fakeMatrix[i][k] != 0 && fakeMatrix[k][j] != 0)
                {
                    if(fakeMatrix[i][j] > fakeMatrix[i][k] + fakeMatrix[k][j] || fakeMatrix[i][j] == 0)
                    {
                        fakeMatrix[i][j] =  fakeMatrix[i][k] + fakeMatrix[k][j];
                    }   
                }
            }
        }
    }
}


int isTherePath(int mat[MAX_SIZE][MAX_SIZE], int i, int j)
{
    floydWarshall(mat);
    if (fakeMatrix[i][j] != 0 && i!=j)
    {
        return 1;
    }
    return 0;
}

int theShortestPath(int mat[MAX_SIZE][MAX_SIZE], int i, int j)
{
    floydWarshall(mat);
    if (fakeMatrix[i][j] != 0 && i!=j)
    {
        return fakeMatrix[i][j];
    }
    return -1;
}