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
		if(i0 <= mid && (arr[i0] <= arr[i1] || i1 > last)){
			buf[i] = arr[i0++];
		}
		else{
			buf[i] = arr[i1++];
		}
	}
}



void merge_sort(int *arr, int start, int last, int *buf){
	if(start ==  last) return;
	int mid = (start + last) / 2;
	merge_sort(arr, start, mid, buf);
	merge_sort(arr, mid+1, last, buf);
	merge(arr, start, mid, last, buf);
	for(int i = 0; i <= last; i++){
		arr[i] = buf[i];
	}
}

// void merge(int *arr, int start, int mid, int last, int *buf){
// 	int i0 = start;
// 	int i1 = mid+1;
// 	for(int i = start; i <= last; i++){
// 		if(i0 <= mid && (arr[i0] <= arr[i1] || i1 > last))
// 			buf[i] = arr[i0++];
// 		else
// 			buf[i] = arr[i1++];
// 	}

// }

// void merge_sort(int *arr, int start, int last, int *buf){
// 	if(start == last) return;
// 	int mid = (start + last) / 2;
// 	merge_sort(arr, start, mid, buf);
// 	merge_sort(arr, mid+1, last, buf);
// 	merge(arr, start, mid, last, buf);

// 	for(int i = 0; i <= last; i++){
// 		arr[i] = buf[i];
// 	}
// }
int main(){
	int arr[10] = {1,2,54,2,3423,432,546,13,23,54};
	int buf[10];
	merge_sort(arr,0,9,buf);
	arr_print(buf, 10);
	return 0;
}