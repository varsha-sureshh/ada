#include<stdio.h>
#include<conio.h>

int s[10],set[10],n,d,count=0,flag=0;

void display(int c){
    printf("\t{");
    for(int i=0;i<c;i++) printf("%d,",set[i]);
    printf("}");
}

int subset(int sum,int i){
    if(sum==d){
        flag=1;
        display(count);
        return 0;
    }
    if(sum>d||i>=n) return 0;

    set[count++]=s[i];
    subset(sum+s[i],i+1);
    count--;
    subset(sum,i+1);
}

void main(){
    printf("ENTER THE NUMBER OF THE ELEMENTS IN THE SET : ");
    scanf("%d",&n);

    printf("ENTER THE SET OF VALUES : ");
    for(int i=0;i<n;i++) scanf("%d",&s[i]);

    printf("ENTER THE SUM : ");
    scanf("%d",&d);

    printf("THE PROGRAM OUTPUT IS: ");
    subset(0,0);

    if(!flag) printf("There is no solution");
}