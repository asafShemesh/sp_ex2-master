
#include <stdio.h>

char items[5];
int values[5];
int weight[5];


int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[]) {
    int mat[6][21];
    for (int i = 0; i < 6; i++) {
        for (int w = 0; w < 21; w++) {
            if (i == 0 || w == 0)
                mat[i][w] = 0;
            else if (weights[i - 1] <= w)
                mat[i][w] = max(values[i - 1] + mat[i - 1][w - weights[i - 1]], mat[i - 1][w]);
            else
                mat[i][w] = mat[i - 1][w];
        }
    }

    return mat[5][20];
}



int main(){


    for (int i = 0; i <5 ; i++)
      {

         scanf("%c",&items[i]);
         scanf("%d",&values[i]);
         scanf("%d",&weight[i]);

    }
    int result = knapsack(weight, values);
    printf("Maximum profit: %d\n", result);

    return 0;

}
