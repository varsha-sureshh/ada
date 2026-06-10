#include<stdio.h>

int n,m,p[10],w[10];

void greedy_knapsack(){
    float max,profit=0;
    int k=0;

    printf("Items included is:\n");

    for(int i=0;i<n;i++){
        max=0;
        for(int j=0;j<n;j++)
            if((float)p[j]/w[j]>max){
                max=(float)p[j]/w[j];
                k=j;
            }

        if(w[k]<=m){
            printf("Item %d\n",k);
            m-=w[k];
            profit+=p[k];
            p[k]=0;
        }
        else break;
    }

    printf("Total profit is %f\n",profit);
    printf("continous knapsack also include item %d with position : %f\n",k,(float)m/w[k]);
    profit+=(float)m/w[k]*p[k];
    printf("Continous knapsack  profit is = %f\n",profit);
}

int main(){
    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter weights of items: ");
    for(int i=0;i<n;i++) scanf("%d",&w[i]);

    printf("Enter prices of items: ");
    for(int i=0;i<n;i++) scanf("%d",&p[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d",&m);

    greedy_knapsack();
}