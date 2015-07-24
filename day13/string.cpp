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

int main(){

	char str1[100] = "Hello";
	char str2[100] = "World!";

	printf("%d\n", my_strlen(str1));
	printf("%s\n", my_strcat2(str1,str2));
	my_strcpy(str1, str2);
	printf("%s\n", str1);
	char str3[100] = "AAA:BBB^CCC";
	printf("%s\n", strtok(str3,":^"));
	printf("%s\n", strtok(NULL,":^"));
	printf("%s\n", strtok(NULL,":^"));


	return 0;
}