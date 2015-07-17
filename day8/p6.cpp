/*

VC, GCC에서 사용

*/

#include <stdio.h>
int len, count;
int arr[1000000] = {0};
int max = -9999;

void func(int index){
	int sum = 0;
	for(int i = index; i < index+count; i++){
		sum += arr[i];
	}

	if(sum > max){
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
		
		max = -9999;
		scanf("%d %d",&len, &count);

		for(int i = 0; i < len+100; i++){
			arr[i] = 0;
		}

		for(int i = 0; i < len; i++){
			scanf("%d",&arr[i]);
		}
		for(int i = 0; i <= len - count; i++){
			func(i);
		}

		printf("%d\n", max);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}