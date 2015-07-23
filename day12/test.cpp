/*

VC, GCC에서 사용

*/

#include <stdio.h>
int get_gcd(int a, int b){
	int t = a;
	a = b;
	b = t % b;
	
	if(b == 0){
		return a;
	}
	return get_gcd(a,b);
}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		int a,b;
		scanf("%d %d", &a, &b);
		
		int gcd = get_gcd(a,b);
		printf("%d",gcd);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}