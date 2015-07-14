/*

VC, GCC에서 사용

*/

#include <stdio.h>
// int index[10000];

int stack[10000];
int result[10000];
char input[10000];
int top = -1;
int index_top = -1;

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

		// char input[10000];

		for(int i = 0; i < 30; i++){
			input[i] = 0;
			stack[i] = 0;
			result[i] = 0;
		}
		
		top = -1;

		scanf("%s",input);
		bool flag = true;
		for(int i = 0; i < 30; i++){
			if(input[i] == '(' || input[i] == '['){
				push(input[i] + i * 1000);
			}

			else if(input[i] == ')'){
				if(!empty()){
					int temp = pop();
					int start = temp / 1000;
					char c = temp % 1000;
					int sum = 0;
					if(c == '('){
						for(int j = start; j < i; j++){
							sum += result[j];
							result[j] = 0;
						}
						if(sum == 0){
							result[start] = 2;
						}
						else{
							result[start] = 2*sum;
						}
					}
					else{
						flag = false;
						break;	
					}
				}
				else{
					flag = false;
					break;
				}
			}
			else if(input[i] == ']'){
				if(!empty()){
					int temp = pop();
					int start = temp / 1000;
					char c = temp % 1000;
					int sum = 0;
					if(c == '['){
						for(int j = start; j < i; j++){
							sum += result[j];
							result[j] = 0;
						}
						if(sum == 0){
							result[start] = 3;
						}
						else{
							result[start] = 3*sum;
						}
					}
					else{
						flag = false;
						break;
					}
				}
				else{
					flag = false;
					break;
				}
			}



			// else if(input[i] == ')'|| input[i] == ']'){
			// 	if(!empty()){
			// 		int temp = pop();
			// 		int start = temp / 1000;
			// 		char c = temp % 1000;
			// 		int sum = 0;
			// 		for(int j = start; j < i; j++){
			// 			sum += result[j];
			// 			result[j] = 0;
			// 		}
			// 		if(sum == 0){
			// 			result[start] = (input[i] == ')')?2:3;
			// 		}
			// 		else{
			// 			result[start] = (input[i] == ')')?2*sum:3*sum;
			// 		}
			// 	}
			// 	else{
			// 		printf("0\n");
			// 		flag = false;
			// 		break;

			// 	}
			// }
		}

		if(!flag || !empty()){
			printf("0\n");
			continue;
		}

		int sum = 0;
		for(int i = 0; i < 30; i++){
			// printf("%d ", result[i]);
			sum += result[i];
		}
		// printf("\n");
		printf("%d\n", sum);

		// while(!empty()){
		// 	printf("%c\n", pop());
		// }
		// for(int i = 0; i 
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}