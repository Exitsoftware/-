/*

VC, GCC에서 사용

*/

#include <stdio.h>


int graph[10000][10000] = {0};
int change[10000] = {0};

int queue[10000] = {0};
int visited[10000] = {0};

int front = 0, rear = 0;

int people;
int a,b;
int num;
int c = 1;

void enqueue(int n){
	queue[rear++] = n;
}

int dequeue(){
	return queue[front++];
}

bool empty(){
	return front == rear;
}

int result = -1;

void bfs(int n, int c){
	// printf("%d c = %d\n", n, c);
	change[n] = c;
	if(n == b){
		result = c;
		return;
	}
	c++;

	for(int i = 1; i <= people; i++){
		if(graph[n][i] != 0 && !visited[i]){
			change[i] = c;
			visited[i] = 1;
			enqueue(i);
		}
	}

	if(!empty()){
		int temp = dequeue();
		bfs(temp, change[temp]);
	}


}

// void dfs(int n){
// 	change[n] = c;
// 	for(int i = 1; i <= people; i++){
// 		if(graph[n][i] != 0 && !visited[i]){
// 			visited[i] = 1;
// 			c++;
// 			dfs(i);
// 		}
// 	}
// }

// int dfs2(int n){
// 	for(int i = 1; i <= people; i++){
// 		if(graph[n][i] != 0){
// 			return(dfs2(graph2[n][i]));
// 		}
// 	}
// 	printf("%d\n", n);
// 	return n;
// }

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		result = -1;
		for(int i = 0; i <= people; i++){
			visited[i] = 0;
			// change[i] = 0;
		}
		front = 0; rear = 0;
		c = 1;
		scanf("%d", &people);
		scanf("%d %d", &a, &b);
		scanf("%d", &num);
		for(int i = 0; i <= people+20; i++){
			for(int j = 0; j <= people+20; j++){
				graph[i][j] = 0;
			}
		}
		for(int i = 0; i < num; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x][y] = y;
			graph[y][x] = x;
		}

		// for(int i = 1; i <= people; i++){
		// 	for(int j = 1; j <= people; j++){
		// 		printf("%d ", graph[i][j]);
		// 	}
		// 	printf("\n");
		// }

		
		// printf("\n");
		visited[a] = 1;
		bfs(a,0);
		// for(int i = 1; i <= people; i++){
		// 	printf("%d",change[i]);
		// }
		// printf("\n");
		if(change[b] == 0){
			printf("-1\n");
		}
		else{
			printf("%d\n", change[b]);
		}
		// printf("%d\n", result);

		// for(int i = 1; i <= people; i++){
		// 	printf("%d ", result);
		// }
		// printf("\n");
		// if(a_parent < b_parent){
		// 	same_parent = a_parent;
		// }
		// else if(a_parent >= b_parent){
		// 	same_parent = b_parent;
		// }
		// printf("same %d\n", same_parent);
		// int big;
		// big = dfs2(same_parent);
		// for(int i = 1; i <= same_parent; i++){
		// 	for(int j = 1; j <= people; j++){
		// 		if(graph[i][j] == same_parent){
		// 			same_parent = i;
		// 			break;
		// 		}
		// 	}
		// }
		// // else if(a_parent == b_parent){
		// // 	printf("2\n");
		// // }
		// printf("same %d\n", big);

		// if(a == b_parent || b == a_parent){
		// 	printf("1\n");
		// }
		// else{
		// 	bfs(big,1);

		// // if(a_parent != b_parent){
		// // 	bfs(same_parent,1);
		// // }
		// // else{
		// // 	bfs(a_parent,1);
		// // }

		// // bfs(same_parent,1);
		// // dfs(1);
		// 	// printf("\n");
		// 	// for(int i = 1; i <= people; i++){
		// 	// 	printf("%d ", change[i]);
		// 	// }
		// 	// printf("\n");
		// 	if(change[a] == 0 || change[b] == 0){
		// 		printf("-1\n");
		// 	}
		// 	else{
		// 		int temp = (change[a]-1) + (change[b]-1);
		// 	// if(temp < 0){
		// 	// 	temp = temp * (-1);
		// 	// }
		// 		printf("%d\n", temp);
		// 	}


		/*

		알고리즘이 들어가는 부분

		*/
	}
// }

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}