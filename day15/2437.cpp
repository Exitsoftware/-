#include "stdio.h"
#define SWAP(a,b) {int t = a; a = b; b = t;};

int count;
int min;
int arr[1010] = {0};
int d[100100] = {0};

void func(int index, int res){
	// printf("res = %d\n", res);
	d[res] = 1;
	for(int i = index+1; i < count; i++){
			func(i, res+arr[i]);		
	}
}
// void init(){
// 	for(int i = 0; i < 100100; i++){
// 		d[i] = 0;
// 	}
// 	for(int i = 0; i < 1010; i++){
// 		arr[i] = 0;
// 	}
// }
int main(){

	scanf("%d", &count);
	// init();

	for(int i = 0; i < count; i++){
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < count-1; i++){
		for(int j = 0; j < count-1-i; j++){
			if(arr[j] > arr[j+1]){
				SWAP(arr[j], arr[j+1]);
			}
		}
	}

	// for(int i = 0; i < count; i++){
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");

	for(int i = 0; i < count; i++){
		func(i,arr[i]);
	}

	// for(int i = 0; i < 50; i++){
	// 	printf("i = %d ,%d\n",i, d[i]);
	// }
	// printf("\n");

	int i = 1;
	while(1){
		// printf("%d\n", i);
		if(d[i] != 1){
			break;
		}
		i++;
	}
	printf("%d\n", i);
	return 0;
}