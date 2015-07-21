/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SIZE 200

int arr[SIZE][SIZE] = {0};
int x,y;
int result = 0;
char input[1000];

int queue[10000] = {0};
int rear = 0, front = 0;
int kill = 0;
int live = 0;

bool empty(){
	return rear == front;
}

void enqueue(int n){
	queue[front++] = n;
}

int dequeue(){
	return queue[rear++];
}

void init(){

	rear = 0;
	front = 0;
	result = 0;
	kill = 0;
	live = 0;

	for(int i = 0; i <= x+1; i++){
		for(int j = 0; j <= y+1; j++){
			arr[i][j] = -1;
		}
	}

	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= y; j++){
			arr[i][j] = 0;
		}
	}
}



void func(int a, int b, int c){
	kill++;
	arr[a][b] = c;
	int flag = 0;
	if(arr[a+1][b] == 1){
		flag++;
		arr[a+1][b] = c+1;
		// func(a+1,b,c+1);
		enqueue((a+1) * 1000 + b);
	}
	if(arr[a-1][b] == 1){
		flag++;
		arr[a-1][b] = c+1;
		// func(a-1,b,c+1);
		enqueue((a-1) * 1000 + b);


	}
	if(arr[a][b+1] == 1){
		flag++;
		arr[a][b+1] = c+1;
		// func(a,b+1,c+1);
		enqueue((a) * 1000 + b+1);


	}
	if(arr[a][b-1] == 1){
		flag++;
		arr[a][b-1] = c+1;
		// func(a,b-1,c+1);
		enqueue((a) * 1000 + b-1);

	}

	if(flag == 0){
		result = c;
	}

	if(!empty()){
		int tmp = dequeue();
		int tmp_a = tmp / 1000;
		int tmp_b = tmp % 1000;
		func(tmp_a, tmp_b, arr[tmp_a][tmp_b]);
	}
}

void print_arr(){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}

// int strlen(){

// 	int i = 0;

// 	while(1){
// 		if(input[i] == NULL){
// 			break;
// 		}
// 		i++;
// 	}

// 	return i;

// }

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		result = 0;

		scanf("%d %d", &y, &x);
		init();

		for(int i = 1; i <= x; i++){
			// printf("??\n");
			scanf("%s", input);

			for(int j = 0; j < y; j++){
				// int tmp;
				// scanf("%d",&tmp);
				arr[i][j+1] = input[j] - '0';
				if(input[j] - '0' == 1){
					live++;
				}
			}
		}


		int a,b;
		scanf("%d %d",&b, &a);
		// print_arr();

		func(a,b,3);
		// print_arr();
		printf("%d %d\n", result, live - kill);


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}