
// http://59.23.113.171/30stair/ustair/ustair.php?pname=ustair

#include "stdio.h"

int len;
int max;
int count;
int test = 0;
int arr[10010] = {0};
int up1[10010] = {0};
int up2[10010] = {0};

void func(){
	for(int i = 1; i <= len; i++){
		if(i == 1){
			up1[i] = arr[i];
			up2[i] = 0;
		}
		max = (up1[i-2] > up2[i-2])? up1[i-2] : up2[i-2];
		up1[i] = max + arr[i];
		up2[i] = up1[i-1] + arr[i];
	}
	max = (up1[len] > up2[len])? up1[len] : up2[len];


}

int main(){

	scanf("%d", &len);
	for(int i = 0; i < len; i++){
		scanf("%d",&arr[i+1]);
	}
	func();

	printf("%d\n", max);



	return 0;
}