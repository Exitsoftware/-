/*

VC, GCC에서 사용

*/

#include <stdio.h>

int arr[10010] = {0};
int dynamic[2][10010] = {0};
int stairs[10000] = { 0 };
int score[2][10000] = { 0 };

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		int num;
		scanf("%d",&num);
		for(int i = 0; i < num; i++){
			scanf("%d", &arr[i]);
		}

		dynamic[0][0] = arr[0];
		dynamic[0][1] = arr[1];
		dynamic[1][1] = arr[1] + arr[0];

		for(int i = 2; i < num; i++){
			int max = (dynamic[0][i-2] > dynamic[1][i-2]) ? dynamic[0][i-2] : dynamic[1][i-2];
			dynamic[0][i] = max + arr[i];
			dynamic[1][i] = dynamic[0][i-1] + arr[i];
		}

		int result = (dynamic[0][num-1] > dynamic[1][num-1])? dynamic[0][num-1] : dynamic[1][num-1];
		printf("%d\n", result);

		// int temp;
		// int num;
		// scanf("%d", &num);
		// for (int i = 0; i < num; i++)
		// {
		// 	scanf("%d", &stairs[i]);
		// }
		// score[0][0] = stairs[0];
		// score[0][1] = stairs[1];
		// score[1][1] = stairs[0] + stairs[1];

		// for (int i = 2; i < num; i++)
		// {
		// 	temp = score[1][i - 2] > score[0][i - 2] ? score[1][i - 2] : score[0][i - 2];
		// 	score[0][i] = temp + stairs[i];
		// 	score[1][i] = score[0][i-1] + stairs[i];

		// 	temp = score[0][i] > score[1][i] ? score[0][i] : score[1][i];
		// }
		// printf("%d\n", temp);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}