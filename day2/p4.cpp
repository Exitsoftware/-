/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <string.h>
int stack[10000];
int top = -1;

int pop(){
	top--;
	return stack[top+1];
}

void push(int n){
	top++;
	stack[top] = n;
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
		top = -1;
		printf("#testcase%d\n",itr+1);

		char input[1000];
		scanf("%s",input);

		int arr[100000];
		int count = 0;
		bool sw = true;

		for(int i = 0; i < strlen(input); i++){
			int temp;
			if(input[i] == '('){
				push(i);
			}
			else if(input[i] == ')'){
				if(!empty()){
					arr[count++] = pop();
					arr[count++] = i;

					// printf("%d %d\n", pop(), i);
				}
				else{
					printf("not match\n");
					sw = false;
					break;
				}
			}
		}

		if(sw && !empty()){
			printf("not match\n");
		}
		else if(sw){
			for(int i = 0; i < count; i++){
				printf("%d %d\n", arr[i], arr[i+1]);
				i++;
			}
		}
		

		// while(!empty()){
		// 	printf("%d\n", pop());
		// }

		
	}


	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}