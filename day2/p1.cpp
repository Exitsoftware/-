/*

VC, GCC에서 사용

*/

#include <stdio.h>


char queue[10000];
int front = 0, rear = 0;

void enqueue(char n){
	queue[rear++] = n;
}

char dequeue(){
	front++;
	return queue[front-1];
}

bool empty(){
	return front == rear;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		int num;
		scanf("%d", &num);

		front = 0;
		rear = 0;


		char input;

		for(int i = 0; i < num; i++){
			scanf("%c", &input);
		}


		for(int i = 0; i < num; i++){
			if(input[i] != '-'){
				enqueue(input[i]);
			}
			else{
				if(empty()){
					printf("error!\n");
					break;
				}
				else{
					dequeue();
				}
			}
		}



		while(!empty()){
			printf("%d\n", dequeue());
		}


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}