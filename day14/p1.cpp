/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SIZE 500

int map_x, map_y;
int timer = 0;
int result = 0;

int fire_x, fire_y;
int safe_x, safe_y;
int start_x, start_y;
int arr[SIZE][SIZE];
int fire_stack[SIZE+10000];
int fire_top = -1;

int my_queue[SIZE+10000];
int rear = 0, front = 0;

int my_abs(int n){
	if(n < 0){
		return n * -1;
	}
	return n;
}

bool empty(){
	return fire_top == -1;
}

void push(int x, int y){
	fire_stack[++fire_top] = x*1000+y;
}


int pop(){
	return fire_stack[fire_top--];
}


bool my_queue_empty(){
	return rear == front;
}

void en_queue(int x, int y){
	my_queue[++rear] = x*1000+y;
}

int de_queue(){
	return my_queue[++front];
}

void init(){

	timer = 0;
	fire_top = -1;

	rear = 0;
	front = 0;
	result = 0;

	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			arr[i][j] = -1;
		}
	}

	for(int i = 1; i <= map_x; i++){
		for(int j = 1; j <= map_y; j++){
			arr[i][j] = 0;
		}
	}
}

void print_map(){
	for(int i = 0; i <= map_x+1; i++){
		for(int j = 0; j <= map_y+1; j++){
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

bool isSafety(int x, int y){
	return (x == safe_x && y == safe_y);
}

void func(int x, int y, int t){

		arr[x][y] = t;
		// print_map();
		// printf("\n");

		if(x == safe_x && y == safe_y){
			result = t;
		}

		if((t+1 < my_abs(arr[x+1][y]) || arr[x+1][y] == 0) && (x+1 >= 1 && x+1 <= map_x)){
			arr[x+1][y] = t+1;
			en_queue(x+1,y);
		}
		if((t+1 < my_abs(arr[x-1][y]) || arr[x-1][y] == 0) && (x-1 >= 1 && x-1 <= map_x)){
			arr[x-1][y] = t+1;
			en_queue(x-1,y);
		}
		if((t+1 < my_abs(arr[x][y+1]) || arr[x][y+1] == 0) && (y+1 >= 1 && y+1 <= map_y)){
			arr[x][y+1] = t+1;
			en_queue(x,y+1);
		}
		if((t+1 < my_abs(arr[x][y-1]) || arr[x][y-1] == 0) && (y-1 >= 1 && y-1 <= map_y)){
			arr[x][y-1] = t+1;
			en_queue(x,y-1);
		}

		if(!my_queue_empty()){
			int tmp = de_queue();
			int tmp_x = tmp/1000;
			int tmp_y = tmp%1000;
			func(tmp_x, tmp_y, arr[tmp_x][tmp_y]);
		}

	
	

}


void fire(int x, int y, int t){

		arr[x][y] = t;

		if(arr[x+1][y] == 0 && (x+1 >= 1 && x+1 <= map_x) && !isSafety(x+1, y)){
			arr[x+1][y] = t-1;
			en_queue(x+1,y);
		}
		if(arr[x-1][y] == 0 && (x-1 >= 1 && x-1 <= map_x) && !isSafety(x-1, y)){
			arr[x-1][y] = t-1;
			en_queue(x-1,y);
		}
		if(arr[x][y+1] == 0 && (y+1 >= 1 && y+1 <= map_y) && !isSafety(x, y+1)){
			arr[x][y+1] = t-1;
			en_queue(x,y+1);
		}
		if(arr[x][y-1] == 0 && (y-1 >= 1 && y-1 <= map_y) && !isSafety(x, y-1)){
			arr[x][y-1] = t-1;
			en_queue(x,y-1);
		}

		if(!my_queue_empty()){
			int tmp = de_queue();
			int tmp_x = tmp/1000;
			int tmp_y = tmp%1000;
			fire(tmp_x, tmp_y, arr[tmp_x][tmp_y]);
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

		scanf("%d %d", &map_x, &map_y);

		init();


		for(int i = 1; i <= map_x; i++){
			char input[100];
			scanf("%s", input);
			for(int j = 1; j <= map_y; j++){
				char tmp = input[j-1];

				if(tmp == '.'){
					arr[i][j] = 0;
				}
				else if(tmp == '*'){
					arr[i][j] = -1;
					push(i,j);
				}
				else if(tmp == 'X'){
					arr[i][j] = -1;
				}
				else if(tmp == 'D'){
					// arr[i][j] = 9;
					safe_x = i;
					safe_y = j;
				}
				else if(tmp == 'S'){
					start_x = i;
					start_y = j;
				}
			}
		}

		while(!empty()){
			int tmp = pop();
			int tmp_x = tmp/1000;
			int tmp_y = tmp%1000;
			en_queue(tmp_x, tmp_y);
		}

		if(!my_queue_empty()){
			int tmp = de_queue();
			int tmp_x = tmp/1000;
			int tmp_y = tmp%1000;
			fire(tmp_x, tmp_y, arr[tmp_x][tmp_y]);
		}

		rear = 0;
		front = 0;

		// printf("fire : \n");
		// print_map();
		// printf("\n");
		func(start_x, start_y, 1);
		if(result == 0){
			printf("impossible\n");
		}
		else{
			printf("%d\n", result-1);

		}


		// print_map();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}