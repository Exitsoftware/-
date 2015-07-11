/*

VC, GCC에서 사용

*/

#include <stdio.h>



void func(int n, int win, int lose, int temp, int stack[], int top){
	if(temp == 0){
		// printf("X");
		stack[top++] = 1;	
	}
	else if(temp == 1){
		// printf("O");
		stack[top++] = 2;	
	}
	if(n == win){
		// printf("O\n");

		for(int i = 0; i <= top; i++){
			if(stack[i] == 1){
				printf("X");
			}
			else if(stack[i] == 2){
				printf("O");
			}
		}
		printf("\n");	
		return;
	}

	if(lose == n-1){
		// printf("O");
		func(n, win+1, lose, 1, stack, top);
	}
	else{
		// printf("O");
		func(n, win+1, lose, 1, stack, top);
		// printf("X");



		func(n, win, lose+1, 0, stack, top);
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
		int num;
		int arr[1000];
		scanf("%d",&num);

		func(num,0,0, -1, arr, -1);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}