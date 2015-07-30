#include "stdio.h"

char map[1000][1000];
int map_x, map_y;

void turn(int c){

}
int main(){

	int itr;
	scanf("%d", &itr);
	while(itr--){
		scanf("%d %d", &map_x, &map_y);
		for(int i = 0; i < map_x; i++){
			char input[1000];
			scanf("%s", input);
			for(int j = 0; j < map_y; j++){
				char tmp = input[j];
				map[i][j] = tmp;
			}
		}

		for(int i = 0; i < map_x; i++){
			for(int j = map_y-1; j >=0; j--){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}

	}
	return 0;
}