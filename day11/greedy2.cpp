#include "stdio.h"
#include "string.h"
#define SWAP(a,b) {int t = a; a = b; b = t;};

int len;
int s[3] = {0};
int palette[3] = {0}; 
int result = 0;
int color_count = 0;
char input[100];


void add_color(char n){
	for(int i = 0; i < 3; i++){
		if(s[i] == 0){
			palette[i] = n;
			break;
		}
	}
}

void search(int index){
	int count = 0;

	// s 초기화
	for(int i = 0; i < 3; i++){
		s[i] = 0;
	}

	for(int i = index; i < len; i++){
		if(input[i] == palette[0]){
			count++;
			s[0] = 1;
		}
		else if(input[i] == palette[1]){
			count++;
			s[1] = 1;
		}
		else if(input[i] == palette[2]){
			count++;
			s[2] = 1;
		}

		if(count == 2 && color_count >= 3){
			break;
		}
	}
}

bool isin(char n){
	for(int i = 0; i < 3; i++){
		if(palette[i] == n){
			return true;
		}
	}
	return false;
}
int main(){

	
	scanf("%d", &len);
	scanf("%s", input);

	for(int i = 0; i < len; i++){
		if(!isin(input[i])){
			result++;
			search(i);
			add_color(input[i]);
			printf("index = %d palette : %c %c %c\n", i, palette[0], palette[1], palette[2]);
			color_count++;
		}
	}
	if(result > 3){
		result -= 3;
		printf("%d\n", result);
	}
	else{
		printf("0\n");
	}
	// printf("%d\n", result);
	// for(int i = 0; i < len; i++){
	// 	printf("%c", input[i]);
	// }
	// printf("\n");

	return 0;
}