
// http://59.23.113.171/30stair/maxproduct/maxproduct.php?pname=maxproduct


#include "stdio.h"

int len;
double max;
double arr[10010] = {0};
double result[10010] = {0};


void func(){
	max = 0;
	result[0] = arr[0];

	for(int i = 1; i < len; i++){
		if(result[i-1] * arr[i] < arr[i]){
			result[i] = arr[i];
		}
		else{
			result[i] = result[i-1] * arr[i];
		}

		if(result[i] > max){
			max = result[i];
		}
	}

}
int main(){

	scanf("%d",&len);
	for(int i = 0; i < len; i++){
		scanf("%lf", &arr[i]);
	}
	func();
	printf("%.3lf\n", max);




	return 0;
}