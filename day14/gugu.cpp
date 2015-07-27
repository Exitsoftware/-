/*

VC, GCC에서 사용

*/

#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		int tmp;
		scanf("%d", &tmp);
		for(int i = 1; i <= 9; i++){
			printf("%d * %d = %d\n", tmp, i, tmp*i);
		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}