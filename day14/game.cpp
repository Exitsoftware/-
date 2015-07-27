#include "stdio.h"

int n;
int map[300][300] = {0};
int cache[300][300] = {0};

void init(){
	for(int i = 0; i < 300; i++){
		for(int j = 0; j < 300; j++){
			map[i][j] = 0;
			cache[i][j] = 0;
		}
	}
}

int get_max(int a, int b){
	return (a > b)? a : b;
}

int func(int x, int y){
	int val = map[x][y];

	if(!(x <= n && y <= n)){
		return false;
	}

	if(x == n && y == n){
		return true;
	}

	bool flag1 = false, flag2 = false;
	if(!cache[x+val][y]){
		cache[x+val][y] = 1;
		flag1 = func(x+val, y);
	}
	if(!cache[x][y+val]){
		cache[x][y+val] = 1;
		flag2 = func(x, y+val);
	}

	return (flag1 || flag2);

}

int main(){
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		init();

		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				scanf("%d", &map[i][j]);
			}
		}
		if(func(1,1)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}

	}

	return 0;
}