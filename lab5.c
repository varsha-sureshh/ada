#include<stdio.h>

int cost[10][10],n,colsum[10];

void cal_colsum(){
    for(int j=0;j<n;j++){
        colsum[j]=0;
        for(int i=0;i<n;i++)
            colsum[j]+=cost[i][j];
    }
}

void source_removal(){
    int select[10]={0};

    printf("Topological order of vertices:\n");
    for(int i=0;i<n;i++){
        cal_colsum();
        for(int j=0;j<n;j++)
            if(!colsum[j]&&!select[j]){
                printf("%d ",j);
                select[j]=1;
                for(int k=0;k<n;k++) cost[j][k]=0;
                break;
            }
    }
}

void main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    source_removal();
}