/*

VC, GCC에서 사용

*/

#include <stdio.h>

int len;
int result = 0;
int arr[10010] = {0};
int result[10010] = {0};
// int up[3][10010] = {0};


int min_index(int index){
	int min = 9999;
	int min_i = 0;
	for(int i = index + 1; i <= index + 3; i++){
		if(min > arr[i]){
			min = arr[i];
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

	for(int i = 1; i <= len; i++){
		up[0][i] = up[0][i-1] + arr[i];
	}

	for(int i = 2; i <= len; i++){
		if(i % 2 == 0){
			up[1][i] = up[1][i-2] + arr[i];		
		}
		else{
			up[1][i] = up[1][i-1] + arr[i];
		}
	}

	for(int i = 3; i <= len; i++){
		up[2][i] = up[2][i-3] + arr[i];
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
		result = 0;
		scanf("%d",&len);
		for(int i = 1; i <= len; i++){
			scanf("%d", &arr[i]);
		}

		func();

		for(int i = 0; i < 3; i++){
			for(int j = 1; j <= len; j++){
				printf("%3d ", up[i][j]);
			}
			printf("\n");
		}
		printf("%d\n", result);

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}