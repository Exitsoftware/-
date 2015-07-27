/*

VC, GCC에서 사용

*/

#include <stdio.h>

int arr[200][200]= {0};
int size;
bool flag = false;

void init(){

	flag = false;

	// for(int i = 0; i <= size+100; i++){
	// 	for(int j = 0; j <= size+100; j++){
	// 		arr[i][j] = -1;
	// 	}
	// }

	for(int i = 1; i <= size; i++){
		for(int j = 1; j <= size; j++){
			arr[i][j] = 0;
		}
	}	
}

void func(int x, int y){
	int val = arr[x][y];

	// printf("%d %d\n", x,y);
	if(x == size && y == size){
		flag = true;
		return;
	}

	if(arr[x][y+val] >= 0 && (y+val >= 1 && y+val <= size)){
		func(x, y+val);
	}
	if(arr[x+val][y] >= 0 && (x+val >= 1 && x+val <= size)){
		func(x+val, y);
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
		flag = false;
		// init();

		scanf("%d", &size);

		for(int i = 1; i <= size; i++){
			for(int j = 1; j <= size; j++){
				scanf("%d", &arr[i][j]);
			}
		}
		func(1,1);
		if(flag){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}