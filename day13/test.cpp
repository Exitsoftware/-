#include "stdio.h"

int main(){
	int x,y;
	scanf("%d %d", &x, &y);

	printf("%d ", x/6 * y/6);

	if(x%6 != 0 && y%6){
		printf("%d\n", ((x%6) * (y%6)) + 1);
	}
	else if(x%6 != 0){
		printf("%d\n", y/6);
	}
	else if(y%6 != 0){
		printf("%d\n", x/6);
	}
	return 0;
}