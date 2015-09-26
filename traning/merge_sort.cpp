#include <stdio.h>

// using namespace std;

void merge(int *arr, int start, int mid, int last, int *arr_buf) {
   int i0 = start; 
   int i1 = mid + 1;
   for (int i = start; i <= last; i++) {
      if (i0 <= mid && (arr[i0] < arr[i1] || i1 > last))
         arr_buf[i] = arr[i0++];
      else
         arr_buf[i] = arr[i1++];
   }
}


void merge_sort(int *arr, int start, int last, int *arr_buf) {
   if (start == last) return;
   int mid = (start + last) / 2;
   merge_sort(arr, start, mid, arr_buf);
   merge_sort(arr, mid + 1, last, arr_buf);
   merge(arr, start, mid, last, arr_buf);


   for (int i = start; i <= last; i++)
      arr[i] = arr_buf[i];
}



// void merge_sort(int *arr, int start, last, int *buf){
// 	if(start == last) return;
// 	int mid = (start + last) / 2;
// 	merge_sort(arr, start, mid, buf);
// 	merge_sort(arr, mid+1, last, buf);
// 	merge(arr, start, mid, last, buf);

// }

// void merge(int *arr, int start, int mid, int last, int *buf){
// 	int i0 = start;
// 	int i1 = mid+1;
// 	for(int i = 0; i <= last; i++){
// 		if(i0 <= mid && (arr[i0] < arr[i1] || i1 > last))
// 			buf[i] = arr[i0++];
// 		else
// 			buf[i] = arr[i1++];
// 	}
// }

void arr_print(int *arr){
	for(int i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {

   int arr[10] = { 2,1,8,9,3,6,55,4,40 };
   int brr[10];
   merge_sort(arr, 0, 9, brr);
   arr_print(brr);
	// int len;
	// int arr[1000000];
	// int brr[1000000];
	// scanf("%d", &len);

	// for(int i = 0; i < len; i++){
	// 	scanf("%d", &arr[i]);
	// }

	// merge_sort(arr,0, len-1, brr);
	// for(int i = 0; i < len; i++){
	// 	printf("%d\n", brr[i]);
	// }

}