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
	// printf("push : %c\n", stack[top]);
}

int pop(){
	// printf("pop : %c\n", stack[top]);
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
		top = -1;
		int len;
		char input[110];
		scanf("%d %s", &len, input);

		for(int i = 0; i < len; i++){
			if(!empty()){
				if(input[i] == stack[top]){
					pop();
				}
				else{
					push(input[i]);
				}
			}
			else{
				push(input[i]);
			}
		}
		// while(!empty()){
		// 	pop();
		// }
		for(int i = 0; i < top+1; i++){
			printf("%c",stack[i]);
		}
		printf("\n");


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}