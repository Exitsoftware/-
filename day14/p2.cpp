/*

VC, GCC에서 사용

*/

#include <stdio.h>

long long count;
long long people;
int arr[5000000];

void init(){
	for(int i = 0; i < count; i++){
		arr[i] = 0;
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
		scanf("%lld %lld", &count, &people);
		init();

		int min;

		for(int i = 0; i < count; i++){
			scanf("%d", &arr[i]);
			if(i == 0){
				min = arr[i];
			}
			if(min > arr[i]){
				min = arr[i];
			}
		}

		// printf("min %d\n",  min);

		long long result;
		long long result_min;

		for(long long i = min; i >= 0; i--){
			// printf("?\n");
			result = 0;
			// printf("i = %d\n", i);
			for(long long j = 0; j < count; j++){
				// printf("??\n");
				result += arr[j] / i;
			}
			// printf("result = %d\n", result);
			if(result >= people){
				result_min = i;
				break;
			}
		}

		printf("%lld\n", result_min);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}