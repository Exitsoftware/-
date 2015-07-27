/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SIZE 200

int arr[SIZE][SIZE] = {0};
int count;
int center_x = SIZE/2;
int center_y = SIZE/2;

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d", &count);

		for(int i = 0; i < count; i++){
			int a, b;
			scanf("%d %d", &a, &b);

			arr[center_x+a][center_y+b] = 1;
		}

		for(int i = 0; i < SIZE; i++){
			for(int j = 0; j < SIZE; j++){
				if(arr[i][j] == 0){
					printf(". ");
				}
				else{
					printf("%d ", arr[i][j]);

				}
			}
			printf("\n");
		}
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}