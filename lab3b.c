#include<stdio.h>

void warshall(int a[][10],int n){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
}

int main(){
    int n,adj[10][10];

    printf("Enter no of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);

    warshall(adj,n);

    printf("Transitive closure:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}