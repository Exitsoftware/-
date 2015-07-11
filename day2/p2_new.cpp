/*

VC, GCC에서 사용

*/

#include <stdio.h>

int queue[100];
int front = 0, rear = 0;
bool sw = false;

void enqueue(int n){
	queue[rear++] = n;
}

int dequeue(){
	return queue[front++];
}

int len(){
	return rear - front;
}

void shift(int n){
	for(int i = 0; i < n; i++){
		int temp = queue[front];
		for(int j = front; j < rear; j++){
			queue[j] = queue[j+1];
		}
		queue[rear-1] = temp;
	}
}

int killing(int n){
	n = n % len();
	int val = queue[n];
	for(int i = n; i < rear - 1; i++){
		queue[i] = queue[i+1];
	}
	rear--;
	return val;
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
		int arr[3000];
		kill--;

		scanf("%d %d", &num, &kill);
		for(int i = 0; i < num; i++){
			enqueue(i+1);
		}

		for(int i = 0; i < num; i++){
			printf("%d ", killing(kill));
			shift(kill);
		}
		printf("\n");


		





		// int arr[2000];
		// int n, m;
		// int m_count=1;
		
		// scanf("%d %d", &n, &m);

		// for(int i=0; i<n; i++) {
		// 	arr[i]=m_count++;
		// }
		
		// int i=0, result_count=0;
		// m_count=1;
		// while(1) {
		// 	if(arr[i%n]==0)
		// 		m_count--;
		// 	if(m_count==m) {
		// 		printf("%d ", arr[i%n]);
		// 		arr[i%n]=0;
		// 		m_count=0;
		// 		result_count++;
		// 	}
		// 	m_count++;
		// 	i++;
		// 	if(result_count==n)
		// 		break;
		// }
		// printf("\n");




		
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
