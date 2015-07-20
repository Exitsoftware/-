/*

VC, GCC에서 사용

*/

#include <stdio.h>

int used[27] = {0};
int card = 4;
int len = 2;

int count1;
int count2;
int tmp_count = 0;

void func(char n, int c){
	// printf("%c", n);
	used[n-65] = 1;

	if(c == 1){
		tmp_count++;
		if(tmp_count == count2){
			for(int i = 0; i < 26; i++){
				if(used[i] == 1){
					printf("%c", i+65);
				}
			}
			printf("\n");
		}
		return;
	}

	for(int i = (n - 65); i < card; i++){
		if(used[i] == 0){

			func(i + 65, c - 1);
			used[i] = 0;
		}

	}
	used[n-65] = 0;

}


int stack[100] = {0};
int top = -1;

void push(int n){
	stack[++top] = n;
}

int pop(){
	return stack[top--];
}


void func2(char n, int c){
	push(n);
	used[n-65] = 1;

	if(c == 1){
		tmp_count++;
		if(tmp_count == count1){
			for(int i = 0; i <= top; i++){
				printf("%c", stack[i]);
			}
			printf("\n");
		}
		pop();
		used[n-65] = 0;
		return;
	}

	for(int i = 0; i < card; i++){
		if(used[i] == 0 && i+65 != n){
			func2(i + 65, c - 1);
		}

	}
	used[n-65] = 0;
	pop();


}


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &card, &len);
		scanf("%d %d", &count1, &count2);

		tmp_count = 0;		


		for(int i = 0; i < card;i++){
			func2(i+65,len);
		}

		for(int i = 0; i < 27; i++){
			used[i] = 0;
		}

		tmp_count = 0;
		for(int i = 0; i < card;i++){
			func(i+65,len);
		}
		

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}