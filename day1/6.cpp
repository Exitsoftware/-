#include <stdio.h>
#include <stdlib.h>

int main(){
	int count = 0;
	int arr[300][300] = {0};
	int m = 0,n = 0;
	int x,y,x1,y1;

	scanf("%d %d", &m, &n);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	scanf("%d", &count);	

	for(int i = 0; i < count; i++){
		int sum = 0;
		scanf("%d %d %d %d", &x, &y, &x1, &y1);
		x--;
		y--;
		for(int j = x; j < x1; j++){
			for(int k = y; k < y1; k++){
				sum += arr[j][k];
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}