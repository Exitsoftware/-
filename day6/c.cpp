//모든 순열의 집합 구하기

#include "stdio.h"
#define SWAP(a,b){int t = a; a = b; b= t;};

int num;
int arr[1000];


void func(int n, int depth){
	// printf("n = %d ", n);
	// printf("depth = %d\n", depth);

	if(depth == num){
		
		for(int i = 0; i < num; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");

		return;
	}
	else{
		for(int i = n; i < num; i++){
			SWAP(arr[n], arr[i]);
			func(n+1, depth+1);
			SWAP(arr[n], arr[i]);
		}
	}

}

int main(){

	
	scanf("%d",&num);

	for(int i = 0; i < num; i++){
		arr[i] = i+1;
	}

	// for(int i = 0; i < num; i++){
	// 	func(arr[i],1);
	// 	printf("\n");
	// }
	func(0,0);

	return 0;
}