#include <stdio.h>
#define BST_SIZE 30
#define START_INDEX 1

int bst[BST_SIZE];

void init(void);

void insert(int newNumber);
int search(int targent);
void printAllNode(void);

int main(void) {
	int count;
	int num;
	int targetNum;
	int resultIndex;

	init();
	scanf("%d", &count);
	while(count) {
		scanf("%d", &num);
		insert(num);
		count--;
	}
	scanf("%d", &targetNum);
	resultIndex = search(targetNum);
	if (resultIndex==-1) {
		printf("no number\n");
	} else {
		printf("result : %d\n", resultIndex);
	}
	printAllNode();
	return 0;
}

void init(void) {
	bst[0] = -9999;
	for (int i=START_INDEX; i<BST_SIZE+1; i++) {
		bst[i] = 0;
	}
}

void insert(int newNumber) {
	for (int i=START_INDEX; i<BST_SIZE+1;) {
		if (bst[i] == 0) {
			bst[i] = newNumber;
			return;
		}
		if (bst[i] < newNumber) {
			i = i * 2 + 1;
		} else {
			i = i * 2;
		}
	}
}

int search(int targetNum) {
	for (int i=START_INDEX; i<BST_SIZE+1;) {
		if (bst[i] == targetNum){
			return i;
		}
		if (bst[i] < targetNum) {
			i = i * 2 + 1;
		} else {
			i = i * 2;
		}
	}
	return -1;
}

void printAllNode(void) {
	for(int i=START_INDEX; i<BST_SIZE+1; i++) {
		printf("%d ", bst[i]);
	}
	printf("\n");
}