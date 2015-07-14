#include "stdio.h"

int gcd(int x, int y){
	int t = x;
	x = y;
	y = t % y;
	if(y == 0){
		return x;
	}
	return gcd(x,y);
}

int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	int g = gcd(a,b);
	printf("%d %d\n",g, (a*b)/g);

	return 0;
}