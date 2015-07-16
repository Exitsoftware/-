/*

VC, GCC에서 사용

*/

#include <stdio.h>

int dosu[100][100];
int max;

void init_dosu(void);
int gamyum(int n, int m, int s);
int gamyum_start(int i, int j);
void print_dosu(int n, int m);


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int n, m;
	int x, y;
	int result;
	int maxsec;

	int i, j, k;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		init_dosu();

		printf("#testcase%d\n",itr+1);
		scanf("%d %d", &m, &n);

		for (i = 1; i <= n; i++) {
			for (j=1; j <= m; j++) {
				scanf("%d", &dosu[i][j]);
			}
		}

		scanf("%d %d", &x, &y);
		max = gamyum_start(y, x);
		while(1) {
			result = gamyum(n, m, max);
			//print_dosu(n,m);
			//printf("            %d\n", max);
			if (result == 0) {
				break;
			}
		}
		printf("%d\n", max);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

int gamyum(int n, int m, int s) {
	int i, j;
	int c = 0;
	for (i = 1; i <= n ; i++) {
		for (j = 1; j <= m; j++) {
			if (dosu[i][j] == s) {
				if (dosu[i-1][j] == 1) {
					dosu[i-1][j] = s + 1;
					c = s + 1;
					max = c;
				} if (dosu[i+1][j] == 1) {
					dosu[i+1][j] = s + 1;
					c = s + 1;
					max = c;
				} if (dosu[i][j-1] == 1) {
					dosu[i][j-1] = s + 1;
					c = s + 1;
					max = c;
				} if (dosu[i][j+1] == 1) {
					dosu[i][j+1] = s + 1;
					c = s + 1;
					max = c;
				}
			}
		}
	}
	return c;
}

int gamyum_start(int i, int j) {
	int c = 1;

	if (dosu[i][j] == 0) {
		c = 0;
		return c;
	}
	else {
		dosu[i][j] = -1;
		if (dosu[i-1][j] == 1){
			dosu[i-1][j] = 2;
			c = 2;
		}
		if (dosu[i+1][j] == 1){
			dosu[i+1][j] = 2;
			c = 2;
		}
		if (dosu[i][j+1] == 1){
			dosu[i][j+1] = 2;
			c = 2;
		}
		if (dosu[i][j-1] == 1){
			dosu[i][j-1] = 2;
			c = 2;
		}
		return c;
	}
}


void print_dosu(int n, int m){
	int i, j;
	for (i = 0; i <= 15; i++) {
		for (j=0; j <= 15; j++) {
			printf(" %d", dosu[i][j]);
		}
		printf("\n");
	}
}


void init_dosu(void) {
	int i, j;
	for (i = 0; i < 100; i++) {
		for (j=0; j < 100; j++) {
			dosu[i][j] = 0;
		}
	}
}