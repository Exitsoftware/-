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

		int arr[10] = {0};
		int max = 0;
		int max_i = 0;
		for(int i = 0; i < 4; i++){
			scanf("%d", &arr[i]);
			if(max < arr[i]){
				max = arr[i];
				max_i = i;
			}
		}

		printf("%d\n", max);
		printf("%d\n", max_i+1);



		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}