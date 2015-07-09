#include <stdio.h>

int queue[10000];
int front = 0, rear = 0;

void enqueue(int n){
	queue[rear++] = n;
}

int dequeue(){
	front++;
	return queue[front-1];
}

int main(){
	return 0;
}