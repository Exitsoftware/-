/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SWAP(a, b){int t = a; a = b; b = t;};

int arr[10009];

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		int count = 0;
		int sum = 0;
		
		scanf("%d", &count);
		for(int i = 0; i < count; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
		}

		for(int i = 0; i < count - 1; i++){
			for(int j = 0; j < count - 1 - i; j++){
				if(arr[j] < arr[j+1]){
					SWAP(arr[j], arr[j+1]);
				}
			}
		}
		// SWAP(arr[0],arr[13]);
		int result = sum;



		// int arr1[10];
		// int arr2[10];

		// int tmep;
		
		// long sum1 = 0;
		// long sum2 = 0;
		// for(int i = 0; i < 10; i++){
		// 	arr1[i] = arr[i];
		// 	sum1 += arr1[i];
		// }
		// for(int i = 10; i < 20; i++){
		// 	arr2[i-10] = arr[i-10];
		// 	sum2 += arr2[i-10];
		// 	printf("sum2 = %ld\n", sum2);
		// }

		// printf("sum1 = %ld sum2 = %ld\n", sum1, sum2);

		// int result1 = sum1;
		// int result2 = sum2;

		// for(int i = 0; i < 8; i++){
		// 	sum1 -= arr1[i];
		// 	result1 += sum1;
		// 	printf("result1 = %d\n", result1);
		// }

		// for(int i = 0; i < 8; i++){
		// 	sum2 -= arr2[i];
		// 	result2 += sum2;
		// 	printf("arr2 = %d\n", arr2[i]);
		// 	printf("sum2 = %ld result2 = %d\n", sum2, result2);
		// }

		// printf("result = %d\n", result1 + result2);


		for(int i = 0; i < count; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		for(int i = 0; i < count - 2; i++){
			sum -= arr[i];
			result += sum;
		}

		printf("%d\n", result);


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}