
#include <stdio.h>
#define bag_max_weight 20
#define num_items 5


int knapSack (int weights[], int values[] , int selected_bool[]) {
    int mat[num_items+1][bag_max_weight+1]={{0}};
    for (int i = 1; i < num_items+1; i++) {
        for (int w = 1; w < bag_max_weight+1; w++) {
            if (weights[i - 1] <= w) {
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
    int susu=mat[5][20];
    for (size_t i = 5; i > 0 && susu>0 ; i--)
    {
       int was_added = susu != mat[i-1][w];
       if(was_added){
        selected_bool[i-1]=1;
        susu-=values[i-1];
        w-=weights[i-1];
       }
       
    }
    
    


    }

    return mat[5][20];
}


int main(){
char items[num_items];
int values[num_items];
int weight[num_items];
int result[num_items]={0};


    for (int i = 0; i < 4; i++)
      {

         scanf("%c",&items[i]);
         scanf("%d",&values[i]);
         scanf("%d ",&weight[i]);

    }

         scanf("%c",&items[4]);
         scanf("%d",&values[4]);
         scanf("%d",&weight[4]);


    int solution = knapSack(weight, values, result);
        printf("Maximum profit: %d\n", solution);

        printf("Selected items:");
          for (int i = 0; i < num_items; i++) {
                if (result[i] == 1) {
                 printf(" %c", items[i]);
              }
         }

    return 0;

}
