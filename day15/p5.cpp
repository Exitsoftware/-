/*

VC, GCC에서 사용

*/

#include <stdio.h>

int size;
int graph[100][100];
int visited[100];
int min = 99999999;

void init(){
	min = 99999999;

	for(int i = 0; i < 100; i++){
		visited[i] = 0;
		for(int j = 0; j < 100; j++){
			graph[i][j] = 0;
		}
	}
}

void func(int n, int c, int res){

	visited[n] = 1;
	// printf("n = %d ", n);

	if(c == size){
		if(n == 0){
			if(min > res){
				min = res;
			}	
			// printf("\n");
		}
		return;
	}



	for(int j = 0; j < size; j++){
		if(j == 0 && c == size -1){
			func(j, c+1, res+graph[n][j]);
			return;
		}
		else if(graph[n][j] != 0 && visited[j] == 0 && n != j){
			visited[j] = 1;
			func(j, c+1, res+graph[n][j]);
			visited[j] = 0;
		}
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

		init();
		scanf("%d", &size);

		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				scanf("%d", &graph[i][j]);
			}
		}


		func(0,0,0);
		printf("%d\n", min);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}