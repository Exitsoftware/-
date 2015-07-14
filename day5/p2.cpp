/*

VC, GCC에서 사용

*/


// 손승하 운영자는 집의 장판을 뜯어내고 타일로 바닥을 교체하려고 한다.  
// 타일은 무조건 정사각형 모양으로 밖에 생산되지 않고 한 변의 길이는 정수이다. 
// 타일의 크기를 여러가지로 하기 싫은 손승하 운영자는 모두 같은 크기의 타일로 바닥을 설치하려고 한다. 하지만, 
// 타일의 개수가 많아지면 비용이 많이 들기 때문에 타일의 개수를 최소한으로 사용하고 싶다.
// 손승하 운영자의 집은 사각형 모양이며 집의 가로와 세로의 크기가 주어질 때 필요한 최소 타일의 개수를 구하자.



// 1
// 24 30
// 
// 20

#include <stdio.h>

// int gcd(int x, int y){
// 	for(; x!=0; ){
// 		if(x>y){
// 			swap
// 		}
// 		y-=x;
// 	}
// 	r y
// }



long int get_gcd(int x, int y){
	int t = x;
	x = y;
	y = t % y;
	if(y == 0){
		return x;
	}
	return get_gcd(x,y);
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		int x, y;
		scanf("%d %d", &x, &y);
		long int gcd = get_gcd(x,y);
		int lcm = (x*y)/gcd;
		// printf("%d %d\n", gcd, lcm);
		printf("%ld\n", (x/gcd) * (y/gcd));



		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}