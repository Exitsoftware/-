/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SWAP(a, b){int t = a; a = b; b = t;};

int len;
int arr[100] = {0};

void func(int n, int depth){
	if(depth == len){
		for(int i = 0; i < len; i++){
			printf("%d", arr[i]);
		}
		printf("\n");
		return;
	}
	else{
		for(int i = n; i < len; i++){
			if(arr[i] == arr[n] && i != n){
				// continue;
				i++;
			}
			else{
				SWAP(arr[i], arr[n]);
				func(n+1, depth+1);
				SWAP(arr[i], arr[n]);
			}

			
			// }
			// else{
				// SWAP(arr[i], arr[n]);
				// func(n+1, depth+1);
				// SWAP(arr[i], arr[n]);
			// }
			// else{
			// 	for(int i = 0; i < len; i++){
			// 		printf("%d", arr[i]);
			// 	}
			// 	printf("\n");
			// 	return;
			// }
		}
	}
}

void func2(int index, int count){
	// printf("index = %d count = %d\n", index, count);

	if(count == 0 && index == len){
		for(int i = 0; i < len; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	else if(index < len){
		if(count > 0){
			arr[index] = 1;
			func2(index+1, count - 1);
		}

		arr[index] = 0;
		func2(index+1, count);	
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

		int count;
		scanf("%d %d", &len, &count);
		// for(int i = 0; i < count; i++){
		// 	arr[i] = 1;
		// }
		func2(0,count);
		// for(int i = 0; i < len; i++){

		// }
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}