/*

VC, GCC에서 사용

*/

#include <stdio.h>

char input[100];
int my_stack[100];
int top = -1;

int alpha[26] = {0};

void init(){
	top = -1;

	for(int i = 0; i < 26; i++){
		alpha[i] = 0;
	}
}

bool empty(){
	return top == -1;
}

void push(int n){
	my_stack[++top] = n;
}

int pop(){
	return my_stack[top--];
}


int my_strlen(char *s){
	int count = 0;
	while(s[count] != '\0'){
		count++;
	}
	return count;
}

void func(int a, int n){
	push(a);
	alpha[a]--;
	if(n == my_strlen(input)){
		for(int i = 0; i <= top; i++){
			printf("%c", my_stack[i] + 'a');
		}
		printf("\n");
	}
	else{
		for(int i = 0; i < 26; i++){
			if(alpha[i] > 0){
				func(i, n+1);
			}
		}	
	}
	

	alpha[a]++;
	pop();



}



int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%s", input);

		init();

		for(int i = 0; i < my_strlen(input); i++){
			alpha[input[i]-'a']++;
		}

		for(int i = 0; i < 26; i++){
			if(alpha[i] > 0){
				func(i,1);
			}
		}

		// for(int i = 0; i < 26; i++){
		// 	printf("%c ", i+'a');
		// }
		// printf("\n");
		// for(int i = 0; i < 26; i++){
		// 	printf("%d ", alpha[i]);
		// }
		// printf("\n");



	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}