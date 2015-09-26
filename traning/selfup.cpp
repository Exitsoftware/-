#include "stdio.h"

int get_len(int n){
	int count = 1;
	while(n/10 != 0){
		count++;
		n /= 10;
	}
	return count;
}

int main(){
	for(int i = 1; i <= 10000; i++){
		int len = get_len(i);
		int origin = i;
		int prime = i * i;
		bool flag = true;
		while(len--){
			int a = origin % 10;
			int b = prime % 10;

			if(a != b){
				flag = false;
				break;
			}

			origin /= 10;
			prime /= 10;
		}

		if(flag){
			printf("%d\n", i);
		}

	}
	return 0;
}