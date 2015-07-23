/*

VC, GCC에서 사용

*/

#include <stdio.h>

int arr[10000] = {0};

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		int len;
		scanf("%d", &len);

		for(int i = 0; i < len; i++){
			scanf("%d", &arr[i]);
		}

		int result = 0;
		int max = 0;

		for(int i = 0; i < len; i++){
			if(arr[i] > 0){
				result += arr[i];
			}
			else if(arr[i] < 0){

				int sum = arr[i];
				for(int j = i+1; j < len; j++){
					sum += arr[j];
					if(arr[j] < 0){
						break;
					}
				}

				if(sum < 0 || result <= 0){

					if(max < result){
						max = result;
					}
					result = 0;
				}
				else{
					result += arr[i];
				}
			}
			// printf("result = %d\n", result);
		}

		if(max < result){
			max = result;
		}


		printf("%d\n", max);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}