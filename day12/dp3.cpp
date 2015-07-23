//  http://59.23.113.171/30stair/meeting/meeting.php?pname=meeting

#include "stdio.h"

int len;
int max = 0;
int arr[10010][2];
int result[10010];

void func(){
	
	for(int i = 0; i < len; i++){
		result[i] = 1;
	}

	for(int i = 0; i < len; i++){
		int end = arr[i][1];
		for(int j = i; j < len; j++){
			int start = arr[j][0];

			if(start >= end){
				result[j] = result[i] + 1;
				if(max < result[j]){
					max = result[j];
				}
			}
		}
	}
}

int main(){

	scanf("%d",&len);
	for(int i = 0; i < len; i++){
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	func();
	// for(int i = 0; i < len; i++){
	// 	printf("%d ", result[i]);
	// }
	// printf("\n");
	printf("%d\n", max);
	return 0;
}