/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define MAX_K 10

char A[MAX_K];
int frontNumSet[MAX_K+1];
int backNumSet[MAX_K+1];
int bracketCount;
int numCount;
int isFind;

void init(void);
void initA(void);
void inputFromUser(void);

void swap(int arr[], int a, int b);
void findCorrectNumSet(int arr[], int start, int fin);

int markChecker(int numSet[]);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		init();
		isFind = 0;
		findCorrectNumSet(backNumSet, 0, numCount);
		isFind = 0;
		findCorrectNumSet(frontNumSet, 0, numCount);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void init(void) {
	bracketCount = 0;
	initA();
	inputFromUser();
}

void initA(void) {
	int i;
	
	for (i=0; i<MAX_K; i++) {
		A[i] = 0;
		frontNumSet[i] = -1;
		backNumSet[i] = -1;
	}
}

void inputFromUser(void) {
	int i;
	scanf("%d", &bracketCount);

	for (i=0; i<bracketCount; i++) {
		scanf(" %c", &A[i]);
	}
	numCount = bracketCount+1;
	for (i=0; i<numCount; i++) {
		frontNumSet[i] = i;
		backNumSet[i] = 9-i;
	}
}

void swap(int arr[], int a, int b) {
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void findCorrectNumSet(int arr[], int start, int fin) {
	int i;
	if (start == fin) {
		markChecker(arr);
	} else {
		for (i=start; i<fin; i++) {
			swap(arr, start, i);
			findCorrectNumSet(arr, start+1, fin);
			swap(arr, start, i);
		}
	}
}

int markChecker(int numSet[]) {
	int i,j;
	for (i=0; i<bracketCount; i++) {
		if (A[i] == '<') {
			if (!(numSet[i] < numSet[i+1])) {
				return isFind;
			}
		} else if (A[i] == '>') {
			if (!(numSet[i] > numSet[i+1])) {
				return isFind;
			}
		}
	}
	if(isFind == 0) {
		for(j=0; j<numCount; j++) {
			printf("%d", numSet[j]);
		}
		printf("\n");
	}
	isFind = 1;
	return isFind;
}