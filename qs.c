/*#include<stdio.h>
#include<stdlib.h>
#define size 10

void swap(int *arr,int a,int b){
	int tmp;
	tmp=arr[a];
	arr[a]=arr[b];
	arr[b]=tmp;
}

int part(int *arr,int l,int r){
	int i,j,p;
	p=arr[r];
	i=l-1;
	/*do{
		do{
			i++;
			do{
				j--;
			}
			while(arr[i]>=p);
		}
		while(arr[j]<=p);
		swap(arr,i,j);
	}
	while(i>=j);
	swap(arr,i,j);
	swap(arr,l,j);*/
	for(j=l;j<=r-1;j++){
		if(arr[j]<p){
			i++;
		    swap(arr,i,j);
		}
	}
	swap(arr,i+1,r);
	return i+1;
}

void qs(int *arr,int l,int r){
	int i,s;
	if(l<r){
		s=part(arr,l,r);
		qs(arr,l,s-1);
		qs(arr,s+1,r);
	}
}

void main(){
	int arr[size],i,n;

	printf("Enter the Size of the array: ");
	scanf("%d",&n);
	printf("Enter The Unsorted Array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	qs(arr,0,n-1);
	printf("The Sorted Array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>
#define size 10

void swap(int *arr,int a,int b){
	int tmp;
	tmp=arr[a];
	arr[a]=arr[b];
	arr[b]=tmp;
}

int part(int *arr,int l,int r){
	int i,j,p;
	p=arr[r];
	i=l-1;
	for(j=l;j<=r-1;j++){
		if(arr[j]<p){
			i++;
		    swap(arr,i,j);
		}
	}
	swap(arr,i+1,r);
	return i+1;
}

void qs(int *arr,int l,int r){
	int i,s;
	if(l<r){
		s=part(arr,l,r);
		qs(arr,l,s-1);
		qs(arr,s+1,r);
	}
}

void main(){
	int arr[size],i,n;
	//clock_t start,end;
	struct timeval tv1,tv2;
	struct rusage r_usage;
	//double cpu_time_used;
	printf("Enter the Size of the array: ");
	scanf("%d",&n);
	printf("Enter The Unsorted Array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	gettimeofday(&tv1,NULL);
	//start = clock();
	qs(arr,0,n-1);
	//end = clock();
	gettimeofday(&tv2,NULL);
	getrusage(RUSAGE_SELF,&r_usage);
	printf("The Sorted Array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nTime of function = %f microsec\n",(double)(tv2.tv_usec-tv1.tv_usec));
	printf("Memory Usage = %ld kb\n",r_usage.ru_maxrss);
	//cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	//printf("\nTime Taken: %ld Seconds\n",cpu_time_used);
	//printf("\n");
}







































































































