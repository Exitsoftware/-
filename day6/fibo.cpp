#include "stdio.h"

long fibo(int start, int n, int res, int res2){

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
	if(n == 1 || n == 0){
		return n;
	}
	return fibo2(n - 1) + fibo2(n - 2);
}

int fac(int n){
	return (n == 1 || n == 0)? 1 : n * fac(n-1);
}

int main(){
	int num;
	scanf("%d",&num);
	// printf("fac = %d\n", fac(num));
	printf("\n");
	printf("fibo = %ld\n",fibo(num, 0, 0, 1));
	printf("fibo2 = %ld\n", fibo2(num));
	printf("fibo = %ld\n",fibo(num, 0, 0, 1));

	return 0;
}