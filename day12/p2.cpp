/*

VC, GCC에서 사용

*/

#include <stdio.h>

int len;
int arr[10010] = {0};
int result[10010] = {0};
// int up[3][10010] = {0};

void init(){
	for(int i = 0; i <= len+100; i++){
		arr[i] = 0;
		result[i] = 0;
	}
}

int min_index(int index){
	int min = 9999;
	int min_i = 0;
	for(int i = index - 3; i <= index - 1; i++){
		if(min > result[i]){
			min = result[i];
			min_i = i;
		}
	}
	return min_i;
}
// void func(){

// 	for(int i = 0; i <= len; i++){
// 		printf("i = %d\n", i);
// 		int tmp = min_index(i);
// 		result += arr[tmp];
// 		printf("index %d value = %d\n", tmp, arr[tmp]);
// 		i = tmp -1;
// 	}
// }

void func(){

	result[0] = arr[0];
	result[1] = arr[1];
	result[2] = arr[2];

	for(int i = 3; i <= len+1; i++){
		// int tmp_index = min_index(i);
		// result[i] = result[tmp_index] + arr[i];

		result[i] = result[i-1];
		if(result[i] > result[i-2]) result[i] = result[i-2];
		if(result[i] > result[i-3]) result[i] = result[i-3];
		result[i] += arr[i];
	}


	// for(int i = 1; i <= len; i++){
	// 	up[0][i] = up[0][i-1] + arr[i];
	// }

	// for(int i = 2; i <= len; i++){
	// 	if(i % 2 == 0){
	// 		up[1][i] = up[1][i-2] + arr[i];		
	// 	}
	// 	else{
	// 		up[1][i] = up[1][i-1] + arr[i];
	// 	}
	// }

	// for(int i = 3; i <= len; i++){
	// 	up[2][i] = up[2][i-3] + arr[i];
	// }


}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		init();

		scanf("%d",&len);
		for(int i = 1; i <= len; i++){
			scanf("%d", &arr[i]);
		}

		func();
		// printf("%d\n", result[len]);
		// for(int i = 0; i <= len; i++){
		// 	printf("%3d ", arr[i]);
		// }
		// printf("\n");
		// for(int i = 0; i <= len+1; i++){
		// 	printf("%3d ", result[i]);
		// }
		// printf("\n");
		printf("%d\n", result[len+1]);


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}