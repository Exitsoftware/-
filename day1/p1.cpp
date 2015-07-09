#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		int map[9][9] = {0};
		int max = 0;
		int max_x, max_y;

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				scanf("%d", &map[i][j]);
				if(map[i][j] > max){
					max = map[i][j];
					max_x = i+1;
					max_y = j+1;
				}
			}
		}
		printf("%d\n", max);
		printf("%d %d\n", max_x, max_y);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}