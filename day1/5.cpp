#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[5][10];
	int count = 0;

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 10; j++){
			count++;
			arr[i][j] = count;
		}
	}

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 10; j++){
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}