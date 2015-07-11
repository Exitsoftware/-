/*

VC, GCC에서 사용

*/

#include <stdio.h>

int queue[100];
int front = 0, rear = 0;
bool sw = false;

void enqueue(int n){
	queue[rear] = n;
	rear++;
}

int dequeue(){
	return queue[front++];
}

int kill_num(int n){
	n--;
	// if((rear - front) == 1){
	// 	sw = true;
	// 	return queue[0];
	// }
	

	// if(n > rear-front){
	n = (n % (rear-front));

	// }
	// else{
	// 	n--;
	// }
	
	// if(n >= 0){
		// printf("n %d\n", n);
		int val = queue[n];
		for(int i = n; i < rear+1; i++){
			queue[i] = queue[i+1];
		}
		rear--;

		return val;
	// }

}


void shift(int num){
	// if(rear != front){
		for(int i = 0; i < num; i++){
			int temp = queue[0];
			for(int j = 0; j < rear; j++){
				queue[j] = queue[j+1];
			}
			queue[rear-1] = temp;
		}

		// printf("shift, len : %d\n", rear - front);
		for(int i = 0; i < rear; i++){
			printf("%d ", queue[i]);
		}
		printf("\n");
	// }

}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		int num, kill;
		int arr[1000];

		front = 0;
		rear = 0;
		sw = false;

		
		scanf("%d %d", &num, &kill);
		for(int i = 0; i < num; i++){
			enqueue(i+1);
		}

		for(int i = 0; i < num; i++){
			printf("%d\n", kill_num(kill));
			if(sw){
				break;
			}
			shift(kill-1);
		}

		// for(int i = 0; i < rear; i++){
		// 	printf("%d\n", queue[i]);
		// }
		
		// scanf("%d", &num);

		// for(int i = 0; i < num; i++){
		// 	enqueue(i+1);
		// }
		

		// for(int i = front; i < rear; i++){
		// 	printf("%d ", queue[i]);
		// }

		// printf("\n");
		// shift(2);


		// for(int i = front; i < rear; i++){
		// 	printf("%d ", queue[i]);
		// }
		// printf("\n");


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
