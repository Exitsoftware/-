#include <stdio.h>
#include <stdlib.h>

// 포인터를 사용한 배열 인덱싱

int main(){
	char ch[2][2] = {{'A','B'},{'C','D'}};

	printf("%d\n", ch);
	printf("%d\n", ch[0]);
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			printf("%c\n", *(*(ch+i)+j));
			printf("%c\n", ch[i][j]);
			printf("%d\n", &ch[i][j]);

		}
	}

	return 0;
}