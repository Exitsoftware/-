/*

VC, GCC에서 사용

*/

#include <stdio.h>
int graph[10000][10000] = {0};
int visited[10000] = {0};
int change[10000] = {0};

int queue[10000] = {0};
int front = 0, rear = 0;

int a,b, num;
int result = -1;
int people;

bool isempty(){
	return front == rear;
}

void enqueue(int n){
	queue[rear++] = n;
}

int dequeue(){
	return queue[front++];
}

void bfs(int n, int c){
	change[n] = c;
	if(n == b){
		result = c;
		return;
	}
	for(int i = 1; i <= people; i++){
		if(graph[n][i] != 0 && !visited[i]){
			visited[i] = 1;
			change[i] = c + 1;
			enqueue(i);
		}
	}

	if(!isempty()){
		int temp = dequeue();
		bfs(temp, change[temp]);
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
		scanf("%d", &people);
		scanf("%d %d", &a, &b);
		scanf("%d", &num);
		front = 0; rear = 0;
		result = -1;
		for(int i = 0; i <= people+1; i++){
			change[i] = 0;
			queue[i] = 0;
			visited[i] = 0;
			for(int j = 0; j < people+1; j++){
				graph[i][j] = 0;
			}
		}
		// for(int i = 0; i <= people+20; i++){
		// 	for(int j = 0; j <= people+20; j++){
		// 		graph[i][j] = 0;
		// 	}
		// }
		for(int i = 0; i < num; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x][y] = y;
			graph[y][x] = x;
		}

		bfs(a,0);
		printf("%d\n", result);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}