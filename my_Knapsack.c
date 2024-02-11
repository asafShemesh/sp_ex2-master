
#include <stdio.h>


int knapsack(int weights[], int values[], int result[]) {
    int mat[6][21]={{0}};
    for (int i = 0; i < 6; i++) {
        for (int w = 0; w < 21; w++) {
            if (i == 0 || w == 0)
                mat[i][w] = 0;
            else if (weights[i - 1] <= w) {
                int include = values[i - 1] + mat[i - 1][w - weights[i - 1]];
                int exclude = mat[i - 1][w];

                if (include > exclude) {
                    mat[i][w] = include;
                } else {
                    mat[i][w] = exclude;
                }
            } else {
                mat[i][w] = mat[i - 1][w];
            }
        }
    int w=20;
    int sum=mat[5][20];
    for (size_t i = 5; i > 0 && sum>0 ; i--)
    {
       int was_added = sum != mat[i-1][w];
       if(was_added){
        result[i-1]=1;
        sum-=values[i-1];
        w-=weights[i-1];
       }
       
    }
    
    


    }

    return mat[5][20];
}


int main(){
char items[5];
int values[5];
int weight[5];
int result[5]={0};


    for (int i = 0; i < 4; i++)
      {

         scanf("%c",&items[i]);
         scanf("%d",&values[i]);
         scanf("%d ",&weight[i]);

    }

         scanf("%c",&items[4]);
         scanf("%d",&values[4]);
         scanf("%d",&weight[4]);


    int solution = knapsack(weight, values, result);
        printf("Maximum profit: %d\n", solution);

        printf("Selected items: ");
          for (int i = 0; i < 5; i++) {
                if (result[i] == 1) {
                 printf("%c ", items[i]);
              }
         }

    return 0;

}
