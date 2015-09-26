#include "stdio.h"

int arr[21][21];
int win = 0;
int result_x, result_y;

void map_print(){
	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void func(int x, int y, int color, int dir, int count, int start_x, int start_y){
	// arr[x][y] = 0;
	// printf("%d\n", count);
	// bool flag = false;

	if(count == 5){
		bool flag = false;
		if(dir == 1 && arr[x][y+1] != color){
			flag = true;
		}
		else if(dir == 2 && arr[x+1][y] != color){
			flag = true;
		}
		else if(dir == 3 && arr[x+1][y+1] != color){
			flag = true;
		}
		else if(dir == 4 && arr[x-1][y+1] != color){
			flag = true;
		}

		if(flag){
			win = color;
			result_x = start_x;
			result_y = start_y;	
		}
		
		// return;
	}

	// dir 1 가로
	if(arr[x][y+1] == color){
		if(dir == 1){
			// flag = true;
			func(x, y+1, color, 1, count+1, start_x, start_y);
		}
		else if(arr[x][y-1] != color){
			func(x, y+1, color, 1, 2, x, y);
		}
	}
	// dir 2 세로
	if(arr[x+1][y] == color){
		if(dir == 2){
			// flag = true;
			func(x+1, y, color, 2, count+1, start_x, start_y);
		}
		else if(arr[x-1][y] != color){
			func(x+1, y, color, 2, 2, x, y);
		}
	}
	// dir 3 \ 방향
	if(arr[x+1][y+1] == color){
		if(dir == 3){
			// flag = true;
			func(x+1, y+1, color, 3, count+1, start_x, start_y);
		}
		else if(arr[x-1][y-1] != color){
			func(x+1, y+1, color, 3, 2, x, y);
		}
	}
	// dir 4 / 방향
	if(arr[x-1][y+1] ==  color){
		if(dir == 4){
			// flag = true;
			func(x-1, y+1, color, 4, count+1, start_x, start_y);
		}	
		else if(arr[x+1][y-1] != color){
			func(x-1, y+1, color, 4, 2, x, y);
		}
	}

	
	if(count >= 6){
		// win = 0;
		return;
	}
	// arr[x][y] = color;
}

int main(){
	int start_x, start_y;
	bool flag = true;
	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
			scanf("%d", &arr[i][j]);
			// if(arr[i][j] != 0 && flag){
			// 	start_x = i;
			// 	start_y = j;
			// 	flag = false;
			// }
		}
	}
	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
			if(arr[i][j] != 0){
				func(i, j, arr[i][j], 0, 1, i, j);
			}
		}
	}
	printf("%d\n", win);
	if(win != 0){
		printf("%d %d\n", result_x, result_y);

	}

	return 0;
}