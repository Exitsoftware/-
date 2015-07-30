/*

VC, GCC에서 사용

*/

#include <stdio.h>

int start, r;

int my_stack[10000] = {0};
int top = -1;

bool empty(){
	return top == -1;
}

void push(int n){
	my_stack[++top] = n;
}

int pop(){
	return my_stack[top--];
}


int isin(int n){
	for(int i = 0; i <= top; i++){
		if(my_stack[i] == n){
			return i;
		}
	}
	return -1;
}

int my_pow(int n, int r){
	if(r == 1){
		return n;
	}
	return n * my_pow(n, r-1);
}

int func(int start, int r){
	int result = 0;
	int start_cpy = start;
	while(start_cpy != 0){
		int tmp = start_cpy % 10;
		start_cpy /= 10;

		result += my_pow(tmp, r);
	}
	return result;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &start, &r);

		// printf("%d\n", func(start, r));

		// printf("%d ", start);
		top = -1;
		int start_cpy = start;
		while(1){
			int t = func(start_cpy, r);

			int search_index = isin(t);
			if(search_index == -1){
				push(t);			
			}
			else{
				printf("%d\n", search_index+1);
				break;
			}



			start_cpy = t;
			// printf("%d ", t);
		}
		// printf("\n");


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}