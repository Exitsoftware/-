/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SWAP(a,b) {int t = a; a = b; b = t;};

int size;

int arr[1000][1000];
int map_count = 0;

// int q[10000] = {0};
// int rear = 0, front = 0;


// bool q_empty(){
// 	return rear == front;
// }

// void enq(int n){
// 	q[++rear] = n;
// }

// int deq(){
// 	return q[++front];
// }


int s[10000] = {0};
int top = -1;

bool empty(){
	return top == -1;
}

void push(int n){
	s[++top] = n;
}

int pop(){
	return s[top--];
}


int s2[10000] = {0};
int top2 = -1;

bool empty2(){
	return top2 == -1;
}

void push2(int n){
	s2[++top2] = n;
}

int pop2(){
	return s2[top2--];
}


void init(){

	map_count = 0;
	// rear = 0;
	// front = 0;
	top = -1;
	top2 = -1;

	for(int i = 0; i <= size+1; i++){
		for(int j = 0; j <= size+1; j++){
			arr[i][j] = -1;
		}
	}

	for(int i = 1; i <= size; i++){
		for(int j = 1; j <= size; j++){
			arr[i][j] = 0;
		}
	}

}

void arr_print(){
	for(int i = 1; i <= size; i++){
		for(int j = 1; j <= size; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void bfs(int x, int y){

	int count = 0;
	arr[x][y] = 0;

	if(arr[x+1][y] > 0){
		count++;
		bfs(x+1, y);
	}
	// if(arr[x-1][y] > 0){
	// 	count++;
	// 	bfs(x-1, y);
	// }
	else if(arr[x][y+1] > 0){
		count++;
		bfs(x, y+1);
	}
	// if(arr[x][y-1] > 0){
	// 	count++;
	// 	bfs(x, y-1);
	// }

	if(count == 0){
		map_count++;
		push(x*10000+y);
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

		init();

		scanf("%d", &size);
		int start_x = 0, start_y = 0;
		for(int i = 1; i <= size; i++){
			for(int j = 1; j <= size; j++){
				scanf("%d", &arr[i][j]);
				if(arr[i][j] != 0 && start_x == 0 && start_y == 0){
					start_x = i;
					start_y = j;
				}
			}
		}

		for(int i = start_x; i <= size; i++){
			for(int j = start_y; j <= size; j++){
				if(arr[i][j] > 0){
					bfs(i, j);
					int tmp = pop();
					// push2(tmp);
					int tmp_x = (tmp/10000);
					int tmp_y = (tmp%10000);
					// printf("%d %d %d\n", map_count,tmp_x - i + 1, tmp_y - j + 1 );
					// printf("%d %d %d\n", map_count,tmp_x, tmp_y);


					for(int k = i; k <= tmp_x; k++){
						for(int l = j; l <= tmp_y; l++){
							arr[k][l] = 0;
						}
					}
					// arr_print();
					tmp_x = (tmp/10000) - i + 1;
					tmp_y = (tmp%10000) - j + 1;
					push2(tmp_x*10000 + tmp_y);

				}
			}
		}

		for(int i = 0; i <= top2-1; i++){
			for(int j = 0; j <= top2-1-i; j++){
				int tmp = s2[j];
				int tmp_x = tmp/10000;
				int tmp_y = tmp%10000;

				int m1 = tmp_x * tmp_y;
				
				int tmp2 = s2[j+1];
				int tmp_x2 = tmp2/10000;
				int tmp_y2 = tmp2%10000;				

				int m2 = tmp_x2 * tmp_y2;

				if(m1 > m2){
					SWAP(s2[j], s2[j+1]);
				}

				if(m1 == m2){
					if(tmp_x > tmp_x2){
						SWAP(s2[j], s2[j+1]);

					}
				}
			}
		}
		printf("%d ", map_count);
		for(int i = 0; i <= top2; i++){
			int tmp = s2[i];
			int tmp_x = tmp/10000;
			int tmp_y = tmp%10000;

			printf("%d %d ", tmp_x, tmp_y);
		}
		printf("\n");
		
		// printf("%d %d\n", start_x, start_y);









	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}