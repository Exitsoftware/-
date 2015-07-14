#include "stdio.h"

void bfs(int v){
	for(int i = 0; i <= n; i++){
		if(graph[v][i] == 1 &&!visited[i]){
			enqueue[i];
		}
	}
	if(f <= r){
		v = dequeue();
		visited[v] = 1;
		bfs(v);
	}
}