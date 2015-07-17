/*

VC, GCC에서 사용

*/

#include <stdio.h>

int stack[1000] = {0};
int top = -1;

bool empty(){
	return top == -1;
}

void push(int n){
	stack[++top] = n;
}

int pop(){

	return stack[top--];
	// }
	// else{
	// 	return -1;
	// }
}

int get_min(){
	if(empty()){
		return -1;
	}

	int min = stack[0];

	for(int i = 0; i <= top; i++){
		if(min > stack[i]){
			min = stack[i];
		}
	}

	return min;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		top = -1;
		int count;
		scanf("%d",&count);
		char tmp[100][100];
		char input[100];

		for(int i = 0; i < count; i++){
			scanf("%s",input);

			// *tmp[i] = *input;

			if(input[1] == 'u'){
				int new_input;
				scanf("%d", &new_input);
				push(new_input);
			}
			else if(input[0] == 'M'){
				if(empty()){
					printf("Empty\n");
					continue;
				}
				printf("Min %d\n", get_min());
			}
			else if(input[1] == 'o'){
				if(empty()){
					printf("Empty\n");
					continue;
				}
				printf("Pop %d\n", pop());
			}

			
		}

		// for(int i = 0; i <= top; i++){
		// 	printf("%d\n", stack[i]);
		// }

		// for(int i = 0; i < count; i++){
		// 	if(tmp[i][1] == 'u'){
		// 		push(tmp[i][5]);
		// 	}
		// 	else if(tmp[i][0] == 'M'){
		// 		printf("Min %c\n", get_min());
		// 	}
		// 	else if(tmp[i][1] == 'O'){
		// 		if(!empty()){
		// 			printf("Pop %c\n", pop());
		// 		}
		// 		else{
		// 			printf("Empty\n");
		// 		}
		// 	}
		// }


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}