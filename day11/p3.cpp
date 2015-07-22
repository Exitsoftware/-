/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include "string.h"

char arr[10][6];
char answer[8][6] = {{'0','0','0','0','0','0'}, {'0','0','1','1','1','1'}, {'0','1','0','0','1','1'}, 
{'0','1','1','1','0','0'}, {'1','0','0','1','1','0'}, {'1','0','1','0','0','1'}, {'1','1','0','1','0','1'}, 
{'1','1','1','0','1','0'}};

int stack[100] = {0};
int top = -1;

bool empty(){
	return top == -1;
}

void push(int n){
	stack[++top] = n;
}

int pop(){
	return stack[top--];
}



int func(char *words){

	if(words[0] == '0' && words[1] == '0' && words[2] == '0' && words[3] == '0' && words[4] == '0' && words[5] == '0'){
		return 'A';
	}
	if(words[0] == '0' && words[1] == '0' && words[2] == '1' && words[3] == '1' && words[4] == '1' && words[5] == '1'){
		return 'B';
	}
	if(words[0] == '0' && words[1] == '1' && words[2] == '0' && words[3] == '0' && words[4] == '1' && words[5] == '1'){
		return 'C';
	}
	if(words[0] == '0' && words[1] == '1' && words[2] == '1' && words[3] == '1' && words[4] == '0' && words[5] == '0'){
		return 'D';
	}
	if(words[0] == '1' && words[1] == '0' && words[2] == '0' && words[3] == '1' && words[4] == '1' && words[5] == '0'){
		return 'E';
	}
	if(words[0] == '1' && words[1] == '0' && words[2] == '1' && words[3] == '0' && words[4] == '0' && words[5] == '1'){
		return 'F';
	}
	if(words[0] == '1' && words[1] == '1' && words[2] == '0' && words[3] == '1' && words[4] == '0' && words[5] == '1'){
		return 'G';
	}
	if(words[0] == '1' && words[1] == '1' && words[2] == '1' && words[3] == '0' && words[4] == '1' && words[5] == '0'){
		return 'H';
	}

	return -1;

}

int recovery(char *words){
	int count;
	for(int i = 0; i < 8; i++){
		count = 0;

		for(int j = 0; j < 6; j++){
			if(words[j] == answer[i][j]){
				count++;
			}
		}

		if(count == 5){
			return i + 'A';
		}
	}

	return -1;
}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		top = -1;

		int len;
		char input[1000];
		scanf("%d", &len);
		scanf("%s", input);

		for(int i = 0; i < len; i++){
			for(int j = 0; j < 6; j++){
				arr[i][j] = input[(i*6)+j];
				// printf("%c\n", arr[i][j]);
			}
		}

		// for(int i = 0; i < len; i++){
		// 	for(int j = 0; j < 6; j++){
		// 		printf("%c", arr[i][j]);
		// 	}
		// 	printf("\n");
		// }

		bool flag = true;

		for(int i = 0; i < len; i++){
			int tmp = func(arr[i]);
			if(tmp != -1){
				push(tmp);
			}
			else{
				// printf("WRONG!\n");

				int tmp2 = recovery(arr[i]);

				if(tmp2 != -1){
					push(tmp2);
				}
				else{
					printf("%d\n", i+1);
					flag = false;
					break;
				}
			}
		}
		
		if(!flag){
			continue;
		}

		for(int i = 0; i <= top; i++){
			printf("%c", stack[i]);
		}
		printf("\n");
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}