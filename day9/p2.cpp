/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <math.h>

long get_gcd(int x, int y){
	// printf("%d %d\n", x, y);
	int t = x;
	x = y;
	y = t % y;
	if(y == 0){
		return x;
	}
	return get_gcd(x, y);
}


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		long gcd, lcm;
		scanf("%ld %ld", &gcd, &lcm);

		// lcm * gcd = (a*b)
		long a, b;
		long min = -1;
		for(int i = 1; i < sqrt(lcm*gcd); i++){
			if((lcm*gcd) % i == 0){
				int tmp_gcd = get_gcd(i, (lcm * gcd) / i);
				if((min > (i + ((lcm * gcd) / i)) || min == -1) && tmp_gcd == gcd){
					a = i;
					b = (lcm * gcd) / i;
					min = a + b;
				}
			}
		}

		printf("%ld %ld\n", a, b);
		// int test;
		// test = get_gcd(a, b);
		// printf("%d %d\n", test, (a*b) / test);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}