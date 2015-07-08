#include <stdio.h>

// 문자열 입

int main(){
	char str[100][100];
	int count = 0;

	scanf("%d", &count);
	for(int i = 0; i < count; i++){
		scanf("%s", str[i]);
	}
	for(int i = 0; i < count; i++){
		printf("%s\n", str[i]);
	}

	return 0;
}