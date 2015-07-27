#include "stdio.h"
int count = 0;
int count2 = 0;

long fibo(int start, int n, int res, int res2){
	count++;

	if(start == 0){
		return start;
	}
	else{

		if(start == n){
			return res;
		}
		return fibo(start, n+1, res + res2, res);	
	}

}

long fibo2(int n){
	count2++;
	if(n == 1 || n == 0){
		return n;
	}
	return fibo2(n - 1) + fibo2(n - 2);
}


int main(){
	printf("꼬리재귀\n");
	printf("%ld\n", fibo(29,1,1,1));
	printf("count = %d번 연산\n", count);
	printf("재귀\n");
	printf("%ld\n", fibo2(30));
	printf("count 2 = %d번 연산\n", count2);
	return 0;
}