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
		int a,b;
		scanf("%d %d",&a, &b);
		printf("%d ", (a/6) * (b/6));

		// a %= 6;
		// b %= 6;
		if(a % 6 != 0 && b % 6 != 0){
			printf("%d\n", a/6 + b/6 + 1);
		}
		else if(a % 6 != 0){
			printf("%d\n", b/6);
		}
		else if(b % 6 != 0){
			printf("%d\n", a/6);
		}
		else{
			printf("0\n");
		}
		// printf("%d\n", b);

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}