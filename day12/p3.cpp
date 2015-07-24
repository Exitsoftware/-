/*

VC, GCC에서 사용

*/

#include <stdio.h>

int strlen(char *s){
	int count = 0;
	while(s[count] != '\0'){
		count++;
	}
	return count;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		char input[10000];
		scanf("%s", input);

		for(int i = 0; i < strlen(input); i++){
			if(input[i] >= 'a'){
				printf("%c", input[i]-'a'+'A');
			}
			else if(input[i] >= 'A'){
				printf("%c", input[i]-'A'+'a');
			}
		}
		printf("\n");

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}