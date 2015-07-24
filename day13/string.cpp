#include "stdio.h"

int my_strlen(char *str){
	int len = 0;
	while(str[len] != '\0'){
		len++;
	}
	return len;
}

char* my_strcat(char* s1, char* s2){
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);

	s1 += len1;

	for(int i = 0; i < len2; i++){
		*s1 = *s2;
		s1++;
		s2++;
	}

	s1 -= (len1 + len2);

	return s1;
}

char* my_strcat2(char* s1, char* s2){
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);

	for(int i = 0; i < len2; i++){
		s1[len1 + i] = s2[i];
	}

	return s1;
}


void my_strcpy(char* s1, char* s2){
	int len2 = my_strlen(s2);

	for(int i = 0; i < len2; i++){
		s1[i] = s2[i];
	}

	s1[len2] = '\0';
}

bool my_strcmp(char* s1, char* s2){
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);

	if(len1 != len2) return false;

	for(int i = 0; i < len1; i++){
		if(s1[i] != s2[i]) return false;
	}

	return true;

}


int strlen(char *s){
	int len = 0;
	while(s[len] != '\0'){
		len++;
	}
	return len;
}

char* strcat(char *s1, char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	for(int i = 0; i < len2; i++){
		s1[i+len1] = s2[i];
	}
	return s1;
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

char* strtok(char *s, char* delim){
	static char *pS;
	char *pDelim;

	if(s == NULL){
		s = pS;
	}
	else{
		pS = s;		
	}

	while(*pS){
		pDelim = delim;
		while(*pDelim){
			if(*pS == *pDelim){
				*pS = NULL;
				pS++;
				return s;
			}
			pDelim++;
		}
		pS++;
	}
	return s;

}

char* strlwr(char *s){
	int len = my_strlen(s);
	for(int i = 0; i < len; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = s[i] - 'A' + 'a';
		}
	}
	return s;
}

char* strupr(char *s){
	int len = my_strlen(s);
	for(int i = 0; i < len; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = s[i] - 'a' + 'A';
		}
	}
	return s;
}


char* replace(char* s, char* input, char* output){
	int len = my_strlen(s);
	int input_len = my_strlen(input);
	int output_len = my_strlen(output);

	for(int i = 0; i < len; i++){
		if(s[i] == input[0]){
			bool flag = true;
			for(int j = 1; j < input_len; j++){
				// if(s[i+j] == )
			}
		}
	}
	return s;
}

int main(){

	char str1[100] = "Hello";
	char str2[100] = "World!";

	printf("%d\n", my_strlen(str1));
	printf("%s\n", my_strcat2(str1,str2));
	my_strcpy(str1, str2);
	printf("%s\n", str1);
	char str3[100] = "AAA:BBB^CCC";
	char delim[100] = ":^";
	printf("%s\n", strtok(str3,delim));
	printf("%s\n", strtok(NULL,delim));
	printf("%s\n", strtok(NULL,delim));
	printf("%s\n", strlwr(str1));
	printf("%s\n", strupr(str1));

	return 0;
}