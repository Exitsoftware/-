#include <stdio.h>
#include <stdlib.h>

// 정식 스택

struct stack{
	int top = -1;
	int data[100];

	bool empty(){
		return top == -1;
	}

	bool full(){
		return sizeof(data)-1 == top;
	}

	int pop(){
		if(!empty()){
			top--;
			return data[top+1];
		}
	}

	void push(int n){
		if(!full()){
			top++;
			data[top] = n;
		}
	}
};

int main(){

	stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	printf("%d\n", s.pop());
	printf("%d\n", s.pop());
	printf("%d\n", s.pop());
	return 0;
}