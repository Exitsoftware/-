/*

VC, GCC에서 사용

*/

#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);


		char str[10];
		scanf("%s", str);
		int max_count = 0;
		int count = 1;

		for(int i = 0; i < 9; i++){
			if(str[i] == str[i+1]){
				count++;
			}
			else{
				if(max_count < count){
					max_count = count;
				}
				count = 1;
			}
		}

		printf("%d\n", max_count);


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}