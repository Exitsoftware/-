#include "stdio.h"

void arr_print(int *arr, int len){
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int *arr, int start, int mid, int last, int *buf){
	int i0 = start;
	int i1 = mid+1;
	for(int i = start; i <= last; i++){
		if(i0 <= mid && (arr[i0] <= arr[i1] || i1 > last))
			buf[i] = arr[i0++];
		else
			buf[i] = arr[i1++];
	}

}

void merge_sort(int *arr, int start, int last, int *buf){
	if(start == last) return;
	int mid = (start + last) / 2;
	merge_sort(arr, start, mid, buf);
	merge_sort(arr, mid+1, last, buf);
	merge(arr, start, mid, last, buf);

	for(int i = 0; i <= last; i++){
		arr[i] = buf[i];
	}
}

int main(){

	return 0;
}