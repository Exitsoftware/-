/*

VC, GCC에서 사용

*/

// 삼성이와 산신령

#include <stdio.h>

int arr[30010] = {0};
int d[30010] = {0};


int get_min(int index){
	int min = 9999;
	int min_index;
	for(int i = index-2; i <= index; i++){
		if(min > arr[i]){
			min = arr[i];
			min_index = i;
		}
	}
	return min_index;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		int count;
		scanf("%d", &count);

		for(int i = 0; i < count; i++){
			scanf("%d", &arr[i]);
		}

		d[0] = 1;
		d[1] = 1;

		for(int i = 2; i < count; i++){
			d[i] = 1;
			// d[i-1] = 1;
			// d[i-2] = 1;
			int min_index = get_min(i);
			d[min_index] = 0;
			// printf("min index =%d\n", min_index);
		}

		for(int i = 0; i < count; i++){
			printf("%d ", d[i]);
		}
		printf("\n");

		int sum = 0;
		for(int i = 0; i < count; i++){
			if(d[i] == 1){
				sum += arr[i];
			}
		}
		printf("%d\n", sum);




		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}