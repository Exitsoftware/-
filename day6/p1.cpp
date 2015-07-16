/*

VC, GCC에서 사용

*/

#include <stdio.h>

int len;
char str[100];

int result[10] = {0};
int arr[10];



int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		
		int used[10] = {0};

		for(int i = 0; i < 10; i++){
			arr[i] = i;
			result[i] = -1;
		}
		
		scanf("%d",&len);
		scanf("%s",str);

		char tmp = str[0];
		int count = 0;
		for(int i = 0; i < len; i++){

			if(str[i] == '>'){

				

			}
			else if(str[i] == '<'){

			}




			// if(str[i] == '<'){
			// 	result[i] = count++;
			// }
			// else{
			// 	// printf("before\n");
			// 	// for(int i = 0; i <= len; i++){
			// 	// 	printf("%2d ", result[i]);
			// 	// }
			// 	// printf("\n");
			// 	for(int j = 0; j < i; j++){
			// 		// printf("??\n");
			// 		result[j] +=1;
			// 	}
			// 	result[i] = ++count;

			// printf("after\n");
			// for(int i = 0; i <= len; i++){
			// 	printf("%2d ", result[i]);
			// }
			// printf("\n");
			// }
		}

		for(int i = 0; i <= len; i++){
			printf("%2d ", result[i]);
		}

		printf("\n");



		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}