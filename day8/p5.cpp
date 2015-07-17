/*

VC, GCC에서 사용

*/

// 첫째 줄은 테스트케이스 T를 입력 받아야 한다.
// 둘째 줄부터 테스트케이스 길이의 수 만큼 L길이 만큼의 문자열이 입력되며 각 문자열의 구분은 공백 또는 개행으로 인식한다.(1<L<100000)

#include <stdio.h>
#include <string.h>


// int count[100000];
int count[100000] = {0};
char stack[100000] = {0};
int top = -1;
int result = 0;

bool empty(){
	return top == -1;
}

void push(char n){
	stack[++top] = n;
}

char pop(){
	return stack[top--];
}



char result_stack[100000] = {0};
int result_top = -1;

void result_push(char n){
	result_stack[++result_top] = n;
}


void func(){
	
}


int factorial(int n){
	if(n == 1){
		return 1;
	}
	return n * factorial(n-1);
}

int limit_factorial(int num, int c){
	if(c == 1){
		return num;
	}
	return num * limit_factorial(num-1, c-1);
}

int cal_c(int n, int r){
	return limit_factorial(n, r) / factorial(r);
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		char input[100000];
		scanf("%s", input);

		for(int i = 0; i < strlen(input); i++){
			if(count[input[i] == 0]){
				push(input[i]);
			}
			count[input[i]]++;
		}




		for(int i = 0; i <= top; i++){
			result_top = -1;



		}

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}