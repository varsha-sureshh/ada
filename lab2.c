#include<stdio.h>
int cost[10][10],n;

void prim(){
    int vt[10]={1},a,b,min,mincost=0,ne=0;

    while(ne<n-1){
        min=999;
        for(int i=0;i<n;i++)
            if(vt[i])
                for(int j=0;j<n;j++)
                    if(!vt[j]&&cost[i][j]<min)
                        min=cost[a=i][b=j];

        printf("Edge from vertex %d to vertex %d and the cost=%d\n",a,b,min);
        vt[b]=1;
        mincost+=min;
        ne++;
        cost[a][b]=cost[b][a]=999;
    }
    printf("The minimum spanning tree cost is %d\n",mincost);
}

int main(){
    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("Enter the no. of vertices\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    prim();
}