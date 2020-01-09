#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10

int arr2[size];
int i=0;

void convert(int item){
    arr2[i]=item;
    i++;
}

void swap(int a,int b){
    int tmp;
    tmp = arr2[a];
    arr2[a] = arr2[b];
    arr2[b] = tmp;
}

void sort(int n){
    int i,j;

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr2[i]>arr2[j]){
                swap(j,i);
            }
        }
    }
}

void main(){
    char arr[size];
    int i,n=0;

    printf("Unsorted Array: ");
    scanf("%s",arr);

    while(arr[n]!='\0'){
        n++;
    }

    for(i=0;i<n;i++){
        convert(arr[i]-'0');
    }

    sort(n);

    printf("Sorted Array: ");
    for(i=0;i<n;i++){
        printf("%d",arr2[i]);
    }
    printf("\n");
}