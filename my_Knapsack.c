
#include <stdio.h>

int items[5];
int values[5];
int weight[5];


int main(){


    for (int i = 0; i <5 ; i++)
      {

         scanf("%c",items[i]);
         scanf("%d",values[i]);
         scanf("%d",weight[i]);

    }
    int result = knapsack(capacity, weights, values, n)
    printf("Maximum value that can be obtained is: %d\n", result);

    return 0;

}


int knapsack(int capacity, int weights[], int values[]) {
    int dp[6][21];

    for (int i = 0; i < 6; i++) {
        for (int w = 0; w < 21; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[5][20];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
