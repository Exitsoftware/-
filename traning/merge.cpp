#include "stdio.h"

// void merge(int arr[],int min,int mid,int max){
// 	int tmp[30];
// 	int i,j,k,m; 
// 	j=min;
// 	m=mid+1;
// 	for(i=min; j<=mid && m<=max ; i++){
// 		 if(arr[j]<=arr[m]){
// 				 tmp[i]=arr[j];
// 				 j++;
// 		 }else{
// 				 tmp[i]=arr[m];
// 				 m++;
// 		 }
// 	}
// 	if(j>mid){
// 		 for(k=m; k<=max; k++){
// 				 tmp[i]=arr[k];
// 				 i++;
// 		 }
// 	}else{
// 		 for(k=j; k<=mid; k++){
// 				tmp[i]=arr[k];
// 				i++;
// 		 }
// 	}
// 	for(k=min; k<=max; k++)
// 		 arr[k]=tmp[k];
// }

// void part(int arr[],int min,int max){
//  int mid;
//  if(min<max){
// 	 mid=(min+max)/2;
// 	 part(arr,min,mid);
// 	 part(arr,mid+1,max);
// 	 merge(arr,min,mid,max);
//  }
// }

void merge(int arr[],int min,int mid,int max){
	int tmp[30];
	int i,j,k,m; 
	j=min;
	m=mid+1;
	for(i=min; j<=mid && m<=max ; i++){
		 if(arr[j]<=arr[m]){
				 tmp[i]=arr[j];
				 j++;
		 }else{
				 tmp[i]=arr[m];
				 m++;
		 }
	}
	if(j>mid){
		 for(k=m; k<=max; k++){
				 tmp[i]=arr[k];
				 i++;
		 }
	}else{
		 for(k=j; k<=mid; k++){
				tmp[i]=arr[k];
				i++;
		 }
	}
	for(k=min; k<=max; k++)
		 arr[k]=tmp[k];
}

void part(int arr[],int min,int max){
 int mid;
 if(min<max){
	 mid=(min+max)/2;
	 part(arr,min,mid);
	 part(arr,mid+1,max);
	 merge(arr,min,mid,max);
 }
}
int main(){
	int arr[10] = {14,3,1,45,5,42,3,5,1,4};
	merge(arr, 0, 5, 10);
	return 0;
}