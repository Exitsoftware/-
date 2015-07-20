/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SWAP(a,b){int t = a; a = b; b = t;};

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		int num;
		int arr[10000];
		scanf("%d",&num);

		for(int i = 0; i < num; i++){
			scanf("%d",&arr[i]);
		}

		// for(int i = 0; i < num - 1; i++){
		// 	for(int j = 0; j < num - 1 - i; j++){
		// 		if(arr[j] > arr[j+1]){
		// 			SWAP(arr[j], arr[j+1]);
		// 		}
		// 	}
		// }

		for(int i = 1; i < num; i++){
			int temp = arr[i];
			int aux = i - 1;
			while(aux >= 0 && arr[aux] > temp){
				arr[aux+1] = arr[aux];
				aux--;
			}
			arr[aux+1] = temp;
		}

		for(int i = 0; i < num; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}