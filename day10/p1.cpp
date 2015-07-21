/*

VC, GCC에서 사용

*/

#include <stdio.h>


char input[10000];

int strlen(){

	int i = 0;

	while(1){
		if(input[i] == NULL){
			break;
		}
		i++;
	}

	return i;

}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		while(1){
			scanf("%s",input);
			int len = strlen();
			// printf("%d\n", len);
			if(input[0] == 'E' && input[1] == 'N' && input[2] == 'D' && len == 3){
				break;
			}



			for(int i = len-1; i >= 0; i--){
				printf("%c", input[i]);
			}
			printf("\n");


		}


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}