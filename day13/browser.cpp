/*

VC, GCC에서 사용

*/

#include <stdio.h>

char forward[100][80];
char backward[100][80];

int f_top = -1;
int b_top = -1;

int strlen(char *s){
	int count = 0;
	while(s[count] != '\0'){
		count++;
	}
	return count;
}

void strcpy(char *s1, char *s2){
	int len2 = strlen(s2);
	for(int i = 0; i < len2; i++){
		s1[i] = s2[i];
	}
	s1[len2] = '\0';
}

bool strcmp(char *s1, char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if(len1 != len2) return false;
	for(int i = 0; i < len1; i++){
		if(s1[i] != s2[i]) return false;
	}

	return true;
}
void strprint(char *s){
	int len = strlen(s);

	for(int i = 0; i < len; i++){
		printf("%c", s[i]);
	}
	printf("\n");
}

void strprint2(char *s){
	int len = strlen(s);

	for(int i = 0; i < len; i++){
		printf("%c", s[i]);
	}
	printf(" ");
}

bool f_empty(){
	return f_top == -1;
}

bool b_empty(){
	return b_top == -1;
}

void f_push(char* s){
	strcpy(forward[++f_top], s);
}

void b_push(char* s){
	strcpy(backward[++b_top], s);
}

char* f_pop(){
	strprint(forward[f_top]);
	return forward[f_top--];
}

char* b_pop(){
	strprint(backward[b_top]);
	return backward[b_top--];
}





int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		f_top = -1;
		b_top = -1;

		char input[80];
		char current[80] = "https://secmem.org/";
		// strprint(current);
		while(1){
			// printf("current : ");
			// strprint2(current);

			scanf("%s", input);

			if(strcmp(input, "QUIT")) break;
			// printf("Order : ");

			if(strcmp(input, "VISIT")){
				scanf("%s", input);
				strprint(input);
				b_push(current);
				strcpy(current, input);
				f_top = -1;
			}
			if(strcmp(input, "BACK")){
				if(!b_empty()){
					f_push(current);
					strcpy(current, b_pop());


				}
				else{
					printf("Ignored\n");
				}
			}
			if(strcmp(input, "FORWARD")){
				if(!f_empty()){
					b_push(current);
					strcpy(current, f_pop());

				}
				else{
					printf("Ignored\n");
				}

			}

		}




	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}