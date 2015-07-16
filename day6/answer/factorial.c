#include <stdio.h>

int factorial(int n);

int main(void) {
	int n;
	int result;

	scanf("%d", &n);
	result = factorial(n);
	printf("%d\n", result);
	return 0;
}

/*int factorial(int n) {
	return n > 1 ? n*factorial(n-1) : 1;
}*/

int factorial(int n) {
	int middle_result = 1;
	while(n != 1) {
		middle_result *= n;
		n--;
	}
	return middle_result;
}