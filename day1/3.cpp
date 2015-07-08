#include <stdio.h>
#include <stdlib.h>

// 메모리 확인

int main(){
	char ch1 = 'A', ch2 = 'B';
	char ch[3] = {'A', 'B', 'C'};
	printf("%d\n", &ch1);
	printf("%d\n", &ch2);

	for(int i = 0; i < 3; i++){
		printf("%d\n", &ch[i]);
	}

	return 0;
}