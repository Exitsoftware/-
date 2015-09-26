#include "stdio.h"

char input[1000];
int alpha[26];
int len;

int stack[1000];
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

int strlen(char *s){
	int count = 0;
	while(s[count] != '\0'){
		count++;
	}
	return count;
}

void func(int index, int n){
	// printf("?\n");
	// used[index] = 1;
	push(index+'a');
	alpha[index]--;

	if(n == len){
		for(int i = 0; i <= top; i++){
			printf("%c", stack[i]);
		}
		printf("\n");
		
		// return;
	}
	else{
		for(int i = 0; i < 26; i++){
			if(alpha[i] != 0){
				func(i, n+1);
			}
		}	
	}
	alpha[index]++;
	pop();
	// used[index] = 0;
	

}

int main(){
	scanf("%s", input);
	len = strlen(input);
	for(int i = 0; i < len; i++){
		int index = input[i] - 'a';
		alpha[index]++;
	}
	// for(int i = 0; i < 26; i++){
	// 	printf("%d ", alpha[i]);
	// }
	// printf("\n");
	for(int i = 0; i < 26; i++){
		if(alpha[i] > 0){
			// push(i+'a');
			func(i, 1);
			// pop();	
		}
	}

	return 0;
}