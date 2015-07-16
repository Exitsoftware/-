#include "stdio.h"
#define BST_SIZE 30
#define START_INDEX 1

int bst[BST_SIZE + 1];

void init(void);

void insert(int newNum);
int search(int target);
void printAllNode(void);

void setLeftChild(int newVal);
void setRightChild(int newVal);


int main(){
	int count;
	int num;

	init();
	scanf("%d", &count);
	while(count--){
		scanf("%d", &num);
		insert(num);
	}
	int targetNum;
	scanf("%d", &targetNum);
	int resultIndex(search(targetNum));
	if(resultIndex == -1){
		printf("No number\n");
	}
	else{
		printf("index = %d\n", resultIndex);
	}
	printAllNode();
	return 0;
}


void init(void){
	for (int i = 0; i < BST_SIZE; i++){
		bst[i] = -1;
	}
}

void insert(int newNum){
	for(int i = START_INDEX; i < BST_SIZE;){
		if(bst[i] == -1){
			bst[i] = newNum;
			return;
		}
		// if(bst[i] > newNum){
		// 	i = i * 2;
		// }
		// else{
		// 	i = i * 2 + 1;
		// }
		i = (bst[i] > newNum)? (i *= 2) : (i = i * 2 + 1);
	}
}

void printAllNode(void){
	for(int i = START_INDEX; i < BST_SIZE; i++){
		// if(bst[i] == -1) continue;
		printf("%d ", bst[i]);
	}
	printf("\n");
}

int search(int targetNum){
	for(int i = START_INDEX; i < BST_SIZE;){
		if(bst[i] == targetNum){
			return i;
		}
		if(bst[i] > targetNum){
			i *= 2;
		}
		else if(bst[i] < targetNum){
			i = i * 2 + 1;
		}
	}
	return -1;
}