#include <stdio.h>
#include <string.h>


char stack[1000000];
int top = -1;

char pop(){
	return stack[top--];
}

char get_top(){
	return stack[top];
}

void push(char n){
	stack[++top] = n;
}

bool empty(){
	return top == -1;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);


		char input[10000];
		int result = 0;
		bool sw = true;
		for(int i = 0; i < strlen(input); i++){
			if(input[i] == '[' || input[i] == '('){
				push(input[i]);
			}
			else if(input[i] == ')'){
				char temp = get_top();
				if(temp == '('){
					pop();
					if(empty()){
						result += 2;
					}
					else{
						result *= 3;
					}
				}
				else{
					sw = false;	
					break;
				}
			}
			else if(input[i] == ']'){
				char temp = get_top();
				if(temp == '['){
					pop();
					if(empty()){
						result += 2;
					}
					else{
						result *= 3;
					}
				}
				else{
					sw = false;
					break;
				}
			}
		}

		if(sw){
			printf("%d\n", result);
		}
		else{
			printf("%d\n", 0);
		}
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}