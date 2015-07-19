#include "stdio.h"
#define SIZE 110
int num;
int arr[SIZE][SIZE];
int count = 0;

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

void print_arr(){
	for(int i = 1; i <= num; i++){
		for(int j = 1; j <= num; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int search_top_node(){
	int target_index;

	for(int j = 1; j <= num; j++){
		bool flag = true;

		for(int i = 1; i <= num; i++){
			if(arr[i][j] != 0){
				flag = false;
				break;
			}
		}

		if(flag){
			arr[j][j] = -1;
			target_index = j;
			return j;
		}



	}

	return -1;
}

void func(int index){
	count++;
	enqueue(index);
	// printf("%d ", index);

	for(int j = 1; j <= num; j++){
		if(arr[index][j] > 0){
			arr[index][j]--;
		}
	}

	int target_index = search_top_node();

	if(target_index != -1){
		return func(target_index);
	}

	return;
}
int main(){
	scanf("%d", &num);
	int parent;
	int child;

	while(scanf("%d %d", &parent, &child) != EOF){
		if(parent == -1){
			break;
		}
		arr[parent][child]++;
	}
	// for(int i = 0; i < 8; i++){
	// 	scanf("%d %d", &parent, &child);
	// 	arr[parent][child] = 1;
	// }
	print_arr();
	// printf("\n");
	// printf("%d\n", search_top_node());
	// print_arr();
	func(search_top_node());

	if(count != num){
		printf("impossible\n");
	}
	else{
		while(!empty()){
			printf("%d ", dequeue());
		}
		printf("\n");
		
	}
	// printf("%d\n", count);
	// for(int i = 0; i < num; i++){

	// }
	return 0;
}