/*

VC, GCC에서 사용

*/

#include <stdio.h>

int max = 0;
int arr[10][10] = {0};

void func(int x, int y){
	int sum = 0;
	sum += arr[x][y];
	sum += arr[x+1][y];
	sum += arr[x-1][y];
	sum += arr[x][y+1];
	sum += arr[x][y-1];

	if(max < sum){
		max = sum;
	}
}


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		max = 0;
		for(int i = 1; i <= 6; i++){
			for(int j = 1; j <= 6; j++){
				scanf("%d", &arr[i][j]);
			}
		}

		for(int i = 1; i <= 6; i++){
			for(int j = 1; j <= 6; j++){
				func(i,j);
			}
		}

		printf("%d\n", max);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}