#include "stdio.h"

int main(){
	char input[1000];
	fgets(input, sizeof(input), stdin);
	printf("%s\n", input);
	printf("%d\n", sizeof(input));
	return 0;
}