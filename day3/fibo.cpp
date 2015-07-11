#include <stdio.h>

int fibo(int n){
	if(n == 1 || n == 2){
		return 1;
	}
	else{
		return fibo(n - 1) + fibo (n - 2);
	}

}

int fac(int n){
	if(n == 1){
		return 1;
	}
	else{
		return n * fac(n-1);
	}
}

int main(){

	int num;
	scanf("%d",&num);
	printf("%d\n", fac(num));

	for(int i = 1; i <= num; i++){
		printf("%d ", fibo(i));
	}
	printf("\n");

	return 0;
}