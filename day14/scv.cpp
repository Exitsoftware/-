
// http://59.23.113.171/30stair/scv/scv.php?pname=scv

#include "stdio.h"

int nCount;
int count;
int arr[200][200] = {0};
int d[200][200] = {0};

int get_max(int a, int b){
	// return (a > b)? a: b;
	if(a > b){
		return a;
	}
	return b;
}

int func(int x, int y){
	// if(x == nCount-1 && y == nCount-1){
	// 	return;
	// }

	// if(!visited[x+1][y] && x+1 < nCount && y < nCount){
	// 	visited[x+1][y] = 1;
	// 	if(arr[x+1][y] == 1){
	// 		count++;		
	// 	}
	// 	func(x+1, y);
	// }

	// if(!visited[x][y+1] && x < nCount && y+1 < nCount){
	// 	visited[x][y+1] = 1;
	// 	if(arr[x+1][y] == 1){
	// 		count++;
	// 	}
	// 	func(x, y+1);
	// // }
	// if(x <= nCount && y <= nCount && d[x][y] == 0){
	// 	d[x][y] = arr[x][y] + get_max(d[x-1][y], d[x][y-1]);
	// 	func(x+1, y);
	// 	func(x, y+1);	
	// }
	
	if(x == nCount && y == nCount)
		return arr[x][y];
	if(x > nCount || y > nCount)
		return 0;

	if(d[x][y] != 0)
		return d[x][y];

	return d[x][y] = arr[x][y] + get_max(func(x+1, y), func(x,y+1));
}


int main(){
	scanf("%d", &nCount);
	for(int i = 1; i <= nCount; i++){
		for(int j = 1; j <= nCount; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	// for(int i = 1; i <= nCount; i++){
	// 	for(int j = 1; j <= nCount; j++){
	// 		printf("%d ", d[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	printf("%d\n", func(1,1));

	return 0;
}