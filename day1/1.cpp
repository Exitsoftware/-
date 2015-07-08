#include <stdio.h>

// 배열 연습
// 다양한 초기화 방법

int main(){
	int arr[5][5];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			printf("%d\n", arr[i][j]);
		}
	}
	return 0;
}