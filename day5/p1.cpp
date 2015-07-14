/*

VC, GCC에서 사용

*/

#include <stdio.h>

int arr[1000][1000] = {0};
int check[] = {0,0,0,0};

int count = 0;

void check_func(char c){
	if(c == 'f'){
		check[0]++;
	}
	else if(c == 'a'){
		check[1]++;
	}
	else if(c == 'c'){
		check[2]++;
	}
	else if(c == 'e'){
		check[3]++;
	}
}

void func(int x, int y){
	for(int i = 0; i < 4; i++){
		check[i] = 0;
	}

	check_func(arr[x][y]);
	check_func(arr[x+1][y]);
	check_func(arr[x][y-1]);
	check_func(arr[x+1][y-1]);

	bool flag = true;
	for(int i = 0; i < 4; i++){
		if(check[i] != 1){
			flag = false;
			break;
		}
	}

	if(flag){
		count++;
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

		count = 0;
		int x,y;
		scanf("%d %d", &x, &y);
		// printf("??\n");

		// for(int i = 0; i <= x+1; i++){
		// 	for(int j = 0; j <= j+1; j++){
		// 		arr[i][j] = -1;
		// 	}
		// }


		for(int i = 1; i <= x; i++){
			char input[1000];
			scanf("%s",input);
			for(int j = 0; j < y; j++){
				arr[i][j+1] = input[j];
			}
		}

		for(int i = 1; i <= x; i++){
			for(int j = 1; j <= y; j++){
				func(i,j);
			}
		}


		printf("%d\n", count);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}