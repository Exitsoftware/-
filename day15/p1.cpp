/*

VC, GCC에서 사용

*/

#include <stdio.h>

char input[90001000];
int arr[26] = {0};

int my_stack[1000010] = {0};
int top = -1;

bool empty(){
	return top == -1;
}

void push(int n){
	my_stack[++top] = n;
}

int pop(){
	return my_stack[top--];
}

void init(){
	top = -1;
	for(int i = 0; i < 26; i++){
		arr[i] = 0;
	}
	for(int i = 0; i < 1000010; i++){
		my_stack[i] = 0;
	}
}

int my_strlen(char* s){
	int count = 0;
	while(s[count] != '\0'){
		count++;
	}
	return count;
}


bool isprime(int n){
	for(int i = 2; i < n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		init();

		scanf("%s", input);
		int len = my_strlen(input);

		for(int i = 0; i < len; i++){
			int tmp = input[i];
			arr[tmp-'A']++;
		}

		// for(int i = 0; i < 26; i++){
		// 	printf("%2c ", i+'A');
		// }
		// printf("\n");
		// for(int i = 0; i < 26; i++){
		// 	printf("%2d ", arr[i]);
		// }
		// printf("\n");

		// int index = -1;

		for(int i = 0; i < 26; i++){
			if(arr[i] == 0 || arr[i] == 1){
				continue;
			}

			if(isprime(arr[i])){
				push(i);
			}

		}

		if(empty()){
			printf("NONE\n");
			continue;
		}
		else{
			for(int i = 0; i <= top; i++){
				printf("%c", my_stack[i] + 'A');
			}
			printf("\n");
			continue;
		}

		init();

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}