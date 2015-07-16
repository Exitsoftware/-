/*

VC, GCC���� ���

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
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	int n;
	int k;
	char bitArr[MAXBIT];

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for(itr=0; itr<nCount; itr++)
	{
		printf("#testcase%d\n",itr+1);
		init(bitArr);
		scanf("%d %d", &n, &k);
		printBitPattern(n, 0, k, 0, bitArr);
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

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
