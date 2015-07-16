/*

VC, GCC에서 사용

*/

#include <stdio.h>


int size;
int arr[200][200] = {0};
int visited[200][200] = {0};
int count;



void init(){
	count = 0;
	for(int i = 0; i < 200; i++){
		for(int j = 0; j < 200; j++){
			arr[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void func(int x, int y, int water_height){
	// printf("x = %d y = %d\n", x, y);
	
	// arr[x][y] = 0;
	int flag = 0;

	if(arr[x+1][y] >= water_height && !visited[x+1][y]){
		visited[x+1][y] = 1;
		// arr[x+1][y] = 0;
		func(x+1, y, water_height);

		flag++;
	}
	if(arr[x-1][y] >= water_height && !visited[x-1][y]){
		visited[x-1][y] = 1;
		// arr[x-1][y] = 0;
		func(x-1, y, water_height);
		flag++;
	}
	if(arr[x][y+1] >= water_height && !visited[x][y+1]){
		visited[x][y+1] = 1;
		// arr[x][y+1] = 0;
		func(x, y+1, water_height);
		flag++;
	}
	if(arr[x][y-1] >= water_height && !visited[x][y-1]){
		visited[x][y-1] = 1;
		// arr[x][y-1] = 0;
		func(x, y-1, water_height);
		flag++;
	}

	if(flag == 0){
		// printf("x = %d y = %d\n", x, y);
		// count = count + 1;
	}
}



void printmap(){
	for(int i = 1; i <= size; i++){
		for(int j = 1; j <= size; j++){
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}



int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		init();

		scanf("%d",&size);

		int max_height = 0; 
		int max_count = 0;

		for(int i = 1; i <= size; i++){
			for(int j = 1; j <= size; j++){
				int tmp;
				scanf("%d",&tmp);
				arr[i][j] = tmp;
				if(tmp > max_height){
					max_height = tmp;
				}
			}
		}

		// printmap();
		// printf("max_height = %d\n", max_height);

		for(int k = 1; k < max_height; k++){
			count = 0;

			for(int i = 1; i <= size; i++){
				for(int j = 1; j <= size; j++){
					if(arr[i][j] >= k && !visited[i][j]){
						count++;
						func(i,j,k);
					}
				}
			}

			if(count > max_count){
				max_count = count;
			}
			// printf("water = %d count = %d\n",k, count);

			for(int i = 1; i <= size; i++){
				for(int j = 1; j <= size; j++){
					visited[i][j] = 0;
				}
			}
			// printmap();
		}

		printf("%d\n", max_count);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}