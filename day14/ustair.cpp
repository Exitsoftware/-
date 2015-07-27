
// http://59.23.113.171/30stair/ustair/ustair.php?pname=ustair

#include "stdio.h"

int len;
int arr[10010] = {0};
int d[2][10010] = {0};


int get_max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

void func(int n){
	if(n == len){
		return;
	}

	if(n == 0 || n == 1){
		return func(n+1);
	}

	int max = get_max(d[0][n-2], d[1][n-2]);
	d[0][n] = max + arr[n];
	d[1][n] = d[0][n-1] + arr[n];

	return func(n+1);


}
int main(){

	scanf("%d", &len);
	for(int i = 0; i < len; i++){
		scanf("%d", &arr[i]);
	}

	d[0][0] = arr[0];
	d[0][1] = arr[1];
	d[1][1] = arr[0] + arr[1];

	// for(int i = 2; i < len; i++){
	// 	int max = get_max(d[0][i-2], d[1][i-2]);
	// 	d[0][i] = max + arr[i];
	// 	d[1][i] = d[0][i-1] + arr[i];
	// }
	func(0);
	int result = get_max(d[0][len-1], d[1][len-1]);
	printf("%d\n", result);


	return 0;
}