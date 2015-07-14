#include "stdio.h"

void dfs(int v){
	visited[v] = true;
	printf("%d ", v);

	for(int i = 0; i <= n; i++){
		if(graph[v][i] == 1 && !visited[i]){
			dfs[i];
		}
	}
}