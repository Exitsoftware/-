/*

VC, GCC에서 사용

*/

#include <stdio.h>

int max_a;
int max_b;

int min_a;
int min_b;

int len_a = 0;
int len_b = 0;
int queue[100000];
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

void funcA(int n){
	int i = 0;
	while(n != 0){
		enqueue(n % 10);
		n /= 10;
		i++;
	}
	int len = i;

	int res = 0;
	for(int i = 0; i < len; i++){
		int temp = dequeue();
		int mult = 1;

		for(int j = 1; j <= i; j++){
			mult *= 10;
		}


		if(temp == 5 || temp == 6){
			max_a += 6 * mult;
			min_a += 5 * mult;
		}
		else{
			max_a += temp * mult;
			min_a += temp * mult;
		}
		
	}

}

void funcB(int n){
	int i = 0;
	while(n != 0){
		enqueue(n % 10);
		n /= 10;
		i++;
	}
	int len = i;

	int res = 0;
	for(int i = 0; i < len; i++){
		int temp = dequeue();
		int mult = 1;

		for(int j = 1; j <= i; j++){
			mult *= 10;
		}


		if(temp == 5 || temp == 6){
			max_b += 6 * mult;
			min_b += 5 * mult;
		}
		else{
			max_b += temp * mult;
			min_b += temp * mult;
		}
		
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

		max_a = 0;
		max_b = 0;
		min_a = 0;
		min_b = 0;

		int a, b;

		scanf("%d %d", &a, &b);
		funcA(a);
		funcB(b);

		printf("%d %d\n", min_a + min_b, max_a + max_b);
		
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}