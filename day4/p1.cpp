/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SWAP(a,b) {int t = a; a = b; b = t;};

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		int num;
		int type;
		int arr[10000] = {0};
		scanf("%d",&num);
		scanf("%d",&type);

		for(int i = 0; i < num; i++){
			scanf("%d",&arr[i]);
		}

		for(int i = 0; i < num - 1; i++){
			for(int j = 0; j < num -1 - i; j++){
				if(type == 0){
					if(arr[j] > arr[j+1]){
						SWAP(arr[j],arr[j+1]);
					}
				}
				else{
					if(arr[j] < arr[j+1]){
						SWAP(arr[j],arr[j+1]);
					}
				}
			}
		}
		for(int i = 0; i < num; i++){
			printf("%d\n", arr[i]);
		}
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}