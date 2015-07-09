#include <stdio.h>
#include <string.h>


char stack[1000000];
char input[10000];
int top = -1;
int result = 0;

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

char stack2[1000000];
int top2 = -1;

char pop2(){
	return stack2[top2--];
}

char get_top2(){
	return stack2[top2];
}

void push2(char n){
	stack2[++top2] = n;
}

bool empty2(){
	return top2 == -1;
}



int func(int count, int len){
	if(count == len-1){
		return 0;
	}

	if(input[count] == '[' || input[count] == '('){
		printf("dsfsd\n");
		printf("%d\n", count);
		push(input[count]);
		if(input[count + 1] == '[' || input[count + 1] == '('){
			if(input[count] == '('){
				return 2 * func(count+1, len);
			}
			else{
				return 3 * func(count+1, len);
			}
		}
		else{
			if(input[count] == '('){
				return 2 + func(count+1, len);
			}
			else{
				return 3 + func(count+1, len);
			}
		}
	}
	else if(input[count] == ')'){
		printf("dsfsd2\n");
		char temp = get_top();
		if(temp == '('){
			pop();

		}
		else{
			return 1;
		}
	}
	else if(input[count] == ']'){
		char temp = get_top();
		if(temp == '['){
			pop();
		}
		else{
			return 1;
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
		top = -1;
		scanf("%s", input);
		int temp_result = 0;
		bool sw = true;

		int result = 0;


		printf("%d\n",func(0, strlen(input)));

		// for(int i = 0; i < strlen(input); i++){
		// 	if(input[i] == '[' || input[i] == '('){
		// 		push(input[i]);
		// 		if(input[i+1] == '[' || input[i+1] == '('){
		// 			push2('*');
		// 		}
		// 		else{
		// 			push2('+');
		// 		}
		// 	}
		// 	else if(input[i] == ')'){
		// 		char temp = get_top();
		// 		if(temp == '('){
		// 			pop();

		// 			char get_op = pop2();
		// 			if(get_op == '+'){

		// 				result += 2;
		// 			}
		// 			else{
		// 				result *= 2;
		// 			}
		// 		}
		// 		else{
		// 			sw = false;	
		// 			break;
		// 		}
		// 	}
		// 	else if(input[i] == ']'){
		// 		char temp = get_top();
		// 		if(temp == '['){
		// 			pop();
		// 			// char temp = get_top();
		// 			char get_op = pop2();
		// 			if(get_op == '+'){

		// 				result += 3;
		// 			}
		// 			else{
		// 				result *= 3;
		// 			}
		// 		}
		// 		else{
		// 			sw = false;
		// 			break;
		// 		}
		// 	}
		// }

		// if(sw){
		// 	printf("%d\n", result);
		// }
		// else{
		// 	printf("%d\n", 0);
		// }
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}