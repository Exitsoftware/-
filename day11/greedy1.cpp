#include "stdio.h"

int money;
int arr[4] = {0};

void func(){
	if(money == 0){
		return;
	}
	if(money >= 25){
		money -= 25;
		arr[0]++;
	}
	else if(money >= 10){
		money -= 10;
		arr[1]++;
	}
	else if(money >= 5){
		money -= 5;
		arr[2]++;
	}
	else if(money >= 1){
		money--;
		arr[3]++;
	}

	return func();
}

int main(){
	scanf("%d",&money);
	func();
	printf("%d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", arr[0], arr[1], arr[2], arr[3]);

	return 0;
}