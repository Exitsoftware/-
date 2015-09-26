#include "stdio.h"
#include "stdlib.h"

void arr_print(int *arr, int len){
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int *arr, int start, int mid, int last, int *bur){
	int i0 = start;
	int i1 = mid+1;
	for(int i = start; i <= last; i++){
		if(i0 <= mid && (arr[i0] <= arr[i1] || i1 > last))
			bur[i] = arr[i0++];
		else
			bur[i] = arr[i1++];
	}
}

void merge_sort(int *arr, int start, int last, int *bur){
	if(start == last) return;
	int mid = (start + last) / 2;
	merge_sort(arr, start, mid, bur);
	merge_sort(arr, mid+1, last, bur);
	merge(arr, start, mid, last, bur);

	for(int i = 0; i <= last; i++){
		arr[i] = bur[i];
	}
}

int main(){
	int arr[10] = {4,3,51,42,32,54,76,84,31,12};
	int bur[10];

	merge_sort(arr, 0, 9, bur);
	arr_print(bur, sizeof(bur)/sizeof(bur[0]));

	return 0;
}