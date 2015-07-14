#include "stdio.h"

int graph[10000][10000] = {0};
int visited[10000][10000] = {0};
int count = 0;

int queue[10000];
int front = 0, rear = 0;

void enqueue(int x, int y){
	queue[rear++] = x*1000+y;
}

int dequeue(){
	return queue[front++];
}

int empty(){
	return front == rear;
}

void bfs(int x, int y, int c){
	// int count = 0;
	c++;
	visited[x][y] = 1;

	// printf("c = %d\n", c);
	if(graph[x+1][y] == 0 && !visited[x+1][y]){
		graph[x+1][y] = c;
		visited[x+1][y] = 1;
		enqueue(x+1,y);
		// bfs(x+1, y, c);
	}
	if(graph[x-1][y] == 0 && !visited[x-1][y]){
		graph[x-1][y] = c;
		visited[x-1][y] = 1;
		count++;
		enqueue(x-1,y);
		// bfs(x-1, y, c);
	}
	if(graph[x][y+1] == 0 && !visited[x][y+1]){
		graph[x][y+1] = c;
		visited[x][y+1] = 1;
		enqueue(x,y+1);
		// bfs(x, y+1, c);
	}
	if(graph[x][y-1] == 0 && !visited[x][y-1]){
		graph[x][y-1] = c;
		visited[x][y-1] = 1;
		enqueue(x,y-1);
		// bfs(x, y-1, c);
	}
	
	if(!empty()){
		int temp = dequeue();
		bfs(temp/1000, temp%1000, graph[temp/1000][temp%1000]);

	}
}


int main(){
	int num;
	scanf("%d",&num);
	for(int i = 0; i <= num+1; i++){
		for(int j = 0; j <= num+1; j++){
			// scanf("%d",&graph[i][j]);
			graph[i][j] = 99;
		}
	}
	for(int i = 1; i <= num; i++){
		for(int j = 1; j <= num; j++){
			scanf("%d",&graph[i][j]);
			if(graph[i][j] == 1)
				graph[i][j] = 99;
		}
	}
	int start_x, start_y;
	int timer;
	int result = 0;
	scanf("%d %d", &start_x, &start_y);
	scanf("%d",&timer);
	bfs(start_y, start_x, 0);

	// for(int i = 1; i <= num; i++){
	// 	for(int j = 1; j <= num; j++){

	// 		printf("%3d ", graph[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for(int i = 1; i <= num; i++){
		for(int j = 1; j<= num; j++){
			if(timer == graph[i][j]){
				result++;
			}
		}
	}
	if(result != 0){
		printf("%d\n", result);
	}
	else{
		printf("OH, MY GOD\n");
	}
	// printf("\n");

	return 0;
}