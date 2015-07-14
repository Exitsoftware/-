/*

VC, GCC에서 사용

*/

#include <stdio.h>
// #include "string.h"

int graph[10000][10000];
int queue[10000];
int visited[10000][10000];

int rear = 0, front = 0;

bool empty(){
	return rear == front;
}

void enqueue(int x, int y){
	queue[rear++] = x*1000+y;
}

int dequeue(){
	return queue[front++];
}

void bfs(int x, int y, int c){
	graph[x][y] = c;
	if(graph[x+1][y] == 0 && !visited[x+1][y]){
		graph[x+1][y] = c+1;
		visited[x+1][y] = 1;
		enqueue(x+1,y);
	}
	if(graph[x-1][y] == 0 && !visited[x-1][y]){
		graph[x-1][y] = c+1;
		visited[x-1][y] = 1;
		enqueue(x-1,y);
	}
	if(graph[x][y+1] == 0 && !visited[x][y+1]){
		graph[x][y+1] = c+1;
		visited[x][y+1] = 1;
		enqueue(x,y+1);
	}
	if(graph[x][y-1] == 0 && !visited[x][y-1]){
		graph[x][y-1] = c+1;
		visited[x][y-1] = 1;
		enqueue(x,y-1);
	}

	if(!empty()){
		int temp = dequeue();
		bfs(temp/1000, temp%1000, graph[temp/1000][temp%1000]);
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
		front = 0;
		rear = 0;
		int x, y;
		scanf("%d %d", &x, &y);

		for(int i = 0; i <= x+1; i++){
			for(int j = 0; j <= y+1; j++){
				graph[i][j] = -1;
			}
		}

		for(int i = 1; i <= x; i++){
			// char input[1000];
			// scanf("%s",input);
			for(int j = 1; j <= y; j++){
				int temp;
				scanf("%d",&temp);
				if(temp == 1){
					graph[i][j] = -2;
				}
				else{
					graph[i][j] = temp;
				}
			}
		}

		// for(int i = 1; i <= x; i++){
		// 	char input[1000];
		// 	scanf("%s",input);
		// 	for(int j = 0; j < y; j++){
		// 		char temp = input[j]-48;

		// 		// scanf("%d",&temp);
		// 		if(temp == 1){
		// 			graph[i][j+1] = -2;
		// 		}
		// 		else{
		// 			graph[i][j+1] = temp;
		// 		}
		// 	}
		// }
		bfs(x,1,1);
		// for(int i = 1; i <= x; i++){
		// 	for(int j = 1; j <= y; j++){
		// 		printf("%3d ", graph[i][j]);
		// 	}
		// 	printf("\n");
		// }

		printf("%d\n", graph[1][y]);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}