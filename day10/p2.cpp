/*

VC, GCC에서 사용

*/

#include <stdio.h>
#define SIZE 101

int arr[SIZE][SIZE] = {0};
int result = 0;

void init(){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			arr[i][j] = -1;
		}
	}
	for(int i = 1; i < SIZE-1; i++){
		for(int j = 1; j < SIZE-1; j++){
			arr[i][j] = 0;
		}
	}


}

void print_arr(){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}

void add_paper(int a, int b){
	for(int i = a; i < a+10; i++){
		for(int j = b; j < b+10; j++){
			if(arr[i][j] == 0){
				arr[i][j] = 1;
			}
		}
	}
}

void func(int a, int b){
	arr[a][b] = 0;
	result++;

	if(arr[a+1][b] == 1){
		func(a+1,b);
	}
	if(arr[a-1][b] == 1){
		func(a-1,b);

	}
	if(arr[a][b+1] == 1){
		func(a,b+1);

	}
	if(arr[a][b-1] == 1){
		func(a,b-1);
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
		result = 0;

		int count;
		scanf("%d",&count);
		int x, y;

		int min_x = 9999, min_y = 9999;
		int max_x = -1, max_y = -1;

		for(int i = 0; i < count; i++){
			scanf("%d %d", &y, &x);
			x++;
			y++;
			add_paper(x,y);
			if(min_x > x){
				min_x = x;
			}
			if(min_y > y){
				min_y = y;
			}
			if(max_x < x){
				max_x = x;
			}
			if(max_y < y){
				max_y = y;
			}
		}
		// print_arr();
		// for(int i = min_x; i < max_x+1; i++){
		// 	for(int j = 1; j < SIZE-1; j++){
		// 		if(arr[i][j] == 1){
		// 			func(i,j);
		// 		}
		// 	}
		// }
		// print_arr();

		for(int i = min_x; i < max_x+1; i++){
			for(int j = min_y; j < max_y+1; j++){
				if(arr[i][j] == 1){
					func(i,j);
				}
			}
		}
		printf("%d\n", result);



		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}