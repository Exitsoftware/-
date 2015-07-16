/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define MAXBIT 40

void init(char bitArr[]);
void initBitArr(char bitArr[]);

void printBitPattern(int totalIndex, int currentIndex, int totalNCount, int currentNCount, char bitArr[]) {
	if (totalIndex == currentIndex) {
		if (currentNCount == totalNCount) {
			printf("%s\n", bitArr);
			return;
		}
		return;
	}
	if (currentNCount < totalNCount) {
		bitArr[currentIndex] = '1';
		printBitPattern(totalIndex, currentIndex+1, totalNCount, currentNCount+1, bitArr);
	}
	bitArr[currentIndex] = '0';
	printBitPattern(totalIndex, currentIndex+1, totalNCount, currentNCount, bitArr);
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	int n;
	int k;
	char bitArr[MAXBIT];

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		printf("#testcase%d\n",itr+1);
		init(bitArr);
		scanf("%d %d", &n, &k);
		printBitPattern(n, 0, k, 0, bitArr);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void init(char bitArr[]) {
	initBitArr(bitArr);
}

void initBitArr(char bitArr[]) {
	int i;
	for (i=0; i<MAXBIT; i++) {
		bitArr[i] = 0;
	}
}
