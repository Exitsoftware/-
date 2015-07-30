/*

VC, GCC에서 사용

*/

#include <stdio.h>
int num;

int arr[3000000] = {0};
int rank[3000000] = {0};

int max;
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d", &num);
		max = -1;
		for(int i = 0; i < num; i++){
			scanf("%d", &arr[i]);
			if(max < arr[i]){
				max = arr[i];
			}
		}

		int order = 1;
		
		for(int i = max; i >= 0; i--){

		}

		for(int i = 0; i < num; i++){
			printf("%d\n", rank[i]);
		}




		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}