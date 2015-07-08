#include <stdio.h>
#include <stdlib.h>

// 동적할당

int main(){
	int *arr;
	int i;

	arr = (int*)malloc(sizeof(int)*5);

	for (int i = 0; i < 5; ++i){
		arr[i] = 0;
		printf("%d\n", arr[i]);
	}
	free(arr);
	
	return 0;
}