/*

VC, GCC에서 사용

*/

#include <stdio.h>

int stack[10] = {0};
int top = -1;

void init(){
	top = -1;
	for(int i = 0; i < 10; i++){
		stack[i] = 0;
	}
}
bool empty(){
	return top == -1;
}

void push(int n){
	stack[++top] = n;
}

int pop(){
	return stack[top--];
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

		char input[1000];
		scanf("%s",input);
		char arr[20][100] = {0};

		int c = 0;
		int d = 0;
		bool flag = true;
		for(int i = 0; i < 100; i++){
			if(input[i] == NULL){
				break;
			}
			if(input[i] == '-'){
				c++;
				d = 0;
				continue;
			}
			if(d > 3){
				flag = false;
				break;
			}
			arr[c][d] = input[i];
			d++;
		}

		

		// for(int i = 0; i < 4; i++){
		// 	for(int j = 0; j < 100; j++){
		// 		if(arr[i][j] == NULL){
		// 			break;
		// 		}
		// 		printf("%c", arr[i][j]);
		// 	}
		// 	printf("\n");
		// }

		int add_num, place;

		scanf("%d %d", &add_num, &place);
		place--;


		for(int i = 0; i < 100; i++){
			if(arr[place][i] == NULL){
				break;
			}

			int tmp = arr[place][i] - '0';
			tmp += add_num;
			push(tmp % 10);
		}

		if(!flag){
			printf("INPUT ERROR!\n");	
			continue;
		}

		if(top < 3){
			for(int i = 0; i < 3 - top; i++){
				printf("%d", add_num);
			}
			for(int i = 0; i <= top; i++){
				printf("%d", stack[i]);
			}
			printf("\n");
		}
		else if(top == 3){
			for(int i = 0; i <= top; i++){
				printf("%d", stack[i]);
			}
			printf("\n");	
		}




		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}