/*

VC, GCC에서 사용

*/

#include <stdio.h>

long factorial(int n){
	if(n == 1){
		return n;
	}

	return n * factorial(n-1);
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		int num;
		scanf("%d", &num);
		printf("%ld\n", factorial(num));

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}