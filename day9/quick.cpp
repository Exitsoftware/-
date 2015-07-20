#include "stdio.h"
#define SIZE 10
#define SWAP(a,b){int t = a, a = b; b = t;};

void qsort(int arr[], int len){

	int pivot;
	int i,j;
	if(n > 1){

		pivot = arr[len-1];
		i = 0;
		j = len - 2;

		while(1){
			while(arr[i] < pivot) i++;
			while(arr[j] > pivot) j--;
			if(i >= j) break;
			SWAP(arr[i],arr[j]);
		}

		

	}
}

int main(){

	int arr[SIZE];
	int i;

	qsort();
	return 0;
}