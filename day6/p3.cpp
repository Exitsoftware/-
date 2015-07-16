/*

VC, GCC에서 사용

*/

#include <stdio.h>

int map[110][110];
int result;

int queue[1000] = {0};
int front = 0, rear = 0;

bool empty(){
	return front == rear;
}

void enqueue(int n){
	queue[rear++] = n;
}

int dequeue(){
	return queue[front++];
}

void func(int x, int y){
	// printf("x = %d y = %d count = %d\n", x,y,count);
	int tmp = 0;
	int count = map[x][y];
	if(map[x+1][y] == -1){
		map[x+1][y] = count+1;
		tmp++;
		enqueue((x+1) * 1000 + y);
		// func(x+1, y, count+1);
	}
	if(map[x-1][y] == -1){
		map[x-1][y] = count+1;
		tmp++;
		enqueue((x-1) * 1000 + y);
		// func(x-1, y, count+1);
	}
	if(map[x][y+1] == -1){
		map[x][y+1] = count+1;
		tmp++;
		enqueue((x) * 1000 + y+1);
		// func(x, y+1, count+1);
	}
	if(map[x][y-1] == -1){
		map[x][y-1] = count+1;
		tmp++;
		enqueue((x) * 1000 + y-1);
		// func(x, y-1, count+1);
	}

	if(tmp == 0){
		result = map[x][y];
		// return;
	}

	if(!empty()){
		int get = dequeue();
		int get_x = get / 1000;
		int get_y = get % 1000;
		func(get_x, get_y);


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
		rear = 0;
		front = 0;
		int x,y;
		scanf("%d %d", &y, &x);
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				int tmp;
				scanf("%d",&tmp);
				if(tmp == 1){
					map[i][j] = -1;
				}
				else{
					map[i][j] = tmp;	
				}
			}
		}

		// for(int i = 0; i < x; i++){
		// 	for(int j = 0; j < y; j++){
		// 		printf("%3d", map[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n\n\n");

		int start_x, start_y;
		scanf("%d %d", &start_y, &start_x);

		map[start_x - 1][start_y - 1] = 1;
		func(start_x - 1, start_y - 1);

		// for(int i = 0; i < x; i++){
		// 	for(int j = 0; j < y; j++){
		// 		printf("%3d", map[i][j]);
		// 	}
		// 	printf("\n");
		// }
		printf("%d\n", result);

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}