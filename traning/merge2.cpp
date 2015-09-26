#include "stdio.h"
#include "stdlib.h"

// void merge(int *arr, int start, int mid, int last, int *buf){
// 	int i0 = start;
// 	int i1 = mid+1;
// 	for(int i = start; i <= last; i++){
// 		if(i0 <= mid && (arr[i0] < arr[i1] || i1 > last))
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

void arr_print(int *buf){
	for(int i = 0; i < 10; i++){
		printf("%d\n", buf[i]);
	}

}


int main(){

	int arr[10] = { 2,1,8,9,3,6,55,4,40 };
	int brr[10];
	// arr_print(brr);
	merge_sort(arr, 0, 9, brr);
	arr_print(brr);


	return 0;
}