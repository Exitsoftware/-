#include "stdio.h"

void merge(int *arr, int start, int mid, int end, int *bur){
	int i0 = start;
	int i1 = mid+1;
	for(int i = start; i <= end; i++){
		if(i0 <= mid && (arr[i0] <= arr[i1] || i1 > end)){
			bur[i] = arr[i0++];
		}
		else{
			bur[i] = arr[i1++];
		}
	}
}

void merge_sort(int *arr, int start, int end, int *bur){
	if(start == end) return;
	int mid = (start + end) / 2;
	merge_sort(arr, start, mid, bur);
	merge_sort(arr, mid+1, end, bur);
	merge(arr, start, mid, end, bur);
	for(int i = 0; i <= end; i++){
		arr[i] = bur[i];
	}
}

int main(){
	return 0;
}