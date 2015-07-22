/*

VC, GCC에서 사용

*/

#include <stdio.h>

int num;
int arr[50];


int stack[100] = {0};
int top = -1;

// bool empty(){
// 	return top == -1;
// }

// void push(int n){
// 	stack[++top] = n;
// }

// int pop(){
// 	return stack[top--];
// }



void func(int n){

	if(n == num-1){
		int result = arr[0];

		// for(int i = 0; i < num-1; i++){
		// 		printf("%d", arr[i]);
		// 		printf("%c", stack[i]);
		// 	}
		// printf("%d\n",arr[num-1]);	


		for(int i = 0; i < num-1; i++){
			
			// if(stack[i] == '-'){
			// 	arr[i+1] *= -1;
			// }
			// else if(stack[i] == ' '){
			// 	if(arr[i] > 0){
			// 		arr[i+1] = (arr[i] * 10) + arr[i+1];
			// 	}
			// 	else if(arr[i] < 0){
			// 		arr[i+1] = (arr[i] * 10) - arr[i+1];
			// 	}
			// 	arr[i] = 0;
			// }

			if(stack[i] == '+'){
				result += arr[i+1];
			}
			else if(stack[i] == '-'){
				result -= arr[i+1];
			}
			else if(stack[i] == ' '){
				if(stack[i-1] == '+' || i == 0){
					result += (arr[i] * 10) + arr[i+1];
					result -= arr[i];
				}
				else if(stack[i-1] == '-'){
					result -= (arr[i] * 10) + arr[i+1];
					result += arr[i];
				}
				else if(stack[i-1] == ' '){
					result = -100;
				}

			}

		}

		// for(int i = 0; i < num; i++){
		// 	printf("%d ", arr[i]);
		// 	result += arr[i];
		// }
		// printf("\n");


		if(result == 0){
			// printf("result = %d\n", result);

			for(int i = 0; i < num-1; i++){
				printf("%d", arr[i]);
				printf("%c", stack[i]);
			}
			printf("%d\n",arr[num-1]);	
		}
		else{
			// printf("??\n");
		}



		
		return;
	}

	stack[n] = ' ';
	func(n+1);
	stack[n] = '+';
	func(n+1);
	stack[n] = '-';
	func(n+1);
	



}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d", &num);

		for(int i = 0; i < num; i++){
			arr[i] = i+1;
		}

		func(0);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}