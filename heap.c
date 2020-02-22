#include<stdio.h>
#define size 50

struct node{
    int val;
    struct node *left;
    struct node *right;
}n;

void heap(){

}

void createtree(char* arr, int n){
    int i;
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("Error 1");
        return;
    }
    for(i=1;i<n;i++){
        tmp->val = arr[i];
        tmp = (struct node *)malloc(sizeof(struct node));
        if(tmp == NULL){
            printf("Error 1");
            return;
        }
    }
}

int main(){
    int arr[size],n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the Unsorted Array\n");
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    createtree(arr,n);
    return 0;
}