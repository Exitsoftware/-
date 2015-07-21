/*

VC, GCC에서 사용

*/

#include <stdio.h>

int arr[1000][1000] = {0};

int x,y;
int a,b;

int result = 0;

void init(){
	for(int i = 0; i <= x+1; i++){
		for(int j = 0; j <= y+1; j++){
			arr[i][j] = -1;
		}
	}
}

void print_map(){
	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= y; j++){
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}


void func(int a, int b, int c){
	int flag = 0;

	arr[a][b] = c;

	if(arr[a+1][b] == 0){
		flag++;
		arr[a+1][b] = c+1;
		func(a+1, b, c+1);
	}
	if(arr[a-1][b] == 0){
		flag++;
		arr[a-1][b] = c+1;
		func(a-1, b, c+1);
		
	}
	if(arr[a][b+1] == 0){
		flag++;
		arr[a][b+1] = c+1;
		func(a, b+1, c+1);
		
	}
	if(arr[a][b-1] == 0){
		flag++;
		arr[a][b-1] = c + 1;
		func(a, b-1, c+1);
	}

	if(flag == 0){
		result = c;
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
		
		scanf("%d %d", &y, &x);

		init();

		for(int i = 1; i <= x; i++){
			for(int j = 1; j <= y; j++){
				int tmp;
				scanf("%d", &tmp);
				if(tmp == 0) {
					arr[i][j] = -1;
				}
				else{
					arr[i][j] = 0;
				}

			}
		}

		scanf("%d %d", &b, &a);

		func(a,b,1);
		print_map();
		printf("%d\n", result);




		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}