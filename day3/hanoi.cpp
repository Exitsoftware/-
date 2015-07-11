#include <stdio.h>

int count = 0;

int hanoi(int fl){
	if(fl == 1){
		return 1;
	}
	else{
		return 1 + 2*hanoi(fl-1);

	}


}

int main(){
	int num;
	scanf("%d",&num);
	printf("%d\n", hanoi(num));
	return 0;
}