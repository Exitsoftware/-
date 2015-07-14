#include "stdio.h"

int graph[1000][1000] = {0};
int visited[1000] = {0};
int computer_count;
int start;

void dfs(int n){
	printf("%d ", n);
	visited[n] = 1;
	for(int i = 1; i <= computer_count; i++){
		if(graph[n][i] == 1 && !visited[i]){
			dfs(i);
		}
	}
}

int main(){
	scanf("%d %d", &computer_count, &start);
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	dfs(start);
	printf("\n");

	return 0;
}