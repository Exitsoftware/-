/*

VC, GCC에서 사용

*/

#include <stdio.h>

char a_stack[10000] = {0};
char b_stack[10000] = {0};
char result[100000] = {0};
int a_top = -1;
int b_top = -1;
int result_top = -1;

void a_push(char n){
	a_stack[++a_top] = n;
}

char a_pop(){
	return a_stack[a_top--];
}

void b_push(char n){
	b_stack[++b_top] = n;
}

char b_pop(){
	return b_stack[b_top--];
}

bool a_empty(){
	return a_top == -1;
}

bool b_empty(){
	return b_top = -1;
}

void result_push(char n){
	result[++result_top] = n;
}

char result_pop(){
	return result[result_top--];
}

bool result_empty(){
	return result_top == -1;
}



int strlen(char *s){
	int count = 0;
	while(1){
		if(s[count] == '\0') return count;
		count++;
	}
}



void func(char *a, char *b, int a_len, int b_len){

	// for(int i = 0; i <= a_top; i++){
	// 	printf("%d", a[i]);
	// }
	// printf("\n");

	int min_len = (a_len < b_len)? a_len : b_len;
	int max_len = (a_len > b_len)? a_len : b_len;


	int up_num = 0;

	for(int i = 0; i < max_len; i++){
		int tmp_a;
		int tmp_b;

		if(i <= a_top){
			tmp_a = a_stack[i];
		}
		else if(i > a_top){
			tmp_a = 0;
		}

		if(i <= b_top){
			tmp_b = b_stack[i];
		}
		else if(i > b_top){
			tmp_b = 0;
		}

		// printf("tmp_a = %d tmp_b = %d\n", tmp_a, tmp_b);

		int tmp = tmp_a + tmp_b + up_num;
		up_num = tmp / 10;
		tmp %= 10;

		// printf("%d", tmp);
		result_push(tmp);
	}

	if(up_num != 0){
		printf("%d", up_num);
	}

	while(!result_empty()){
		printf("%d", result_pop());
	}
	printf("\n");



}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		a_top = -1;
		b_top = -1;
		result_top = -1;
		
		char a[10000];
		char b[10000];

		scanf("%s", a);
		scanf("%s", b);

		for(int i = strlen(a)-1; i >= 0; i--){
			a_push(a[i] - '0');
		}

		for(int i = strlen(b)-1; i >= 0; i--){
			b_push(b[i] - '0');
		}

		// for(int i = 0; i <= a_top; i++){
		// 	printf("%c", a_stack[i]);
		// }
		// printf("\n");
		func(a_stack, b_stack, strlen(a), strlen(b));




		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}