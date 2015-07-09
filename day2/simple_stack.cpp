#include <stdio.h>

// Simple_stack
// C++에는 STL를 이용할 수 있다. 삼성 임원평가때 사용 가능
// #include <stack>

int top = -1;
int stack[10];

int pop(){
	top--;
	return stack[top+1];
}

void push(int n){
	top++;
	stack[top] = n;
}

int main(){

	push(4);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	return 0;
}