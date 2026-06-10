#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;

        int t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}

void generate(int a[],int n){
    srand(time(0));
    for(int i=0;i<n;i++)
        a[i]=rand()%1000;
}

int main(){
    int n;
    printf("Enter no of elements: ");
    scanf("%d",&n);

    if(n<=5000){
        printf("Enter value > 5000");
        return 1;
    }

    int *a=(int*)malloc(n*sizeof(int));

    generate(a,n);

    clock_t start=clock();
    selectionSort(a,n);
    clock_t end=clock();

    printf("Time taken = %f seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    free(a);
}