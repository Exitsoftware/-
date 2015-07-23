#include<iostream>
using namespace std;

#define Nmax 310

int N,M;
int A[Nmax][Nmax];
int D[Nmax][Nmax];
int P[Nmax][Nmax];

void input()
{
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++) cin >> A[i][j];
	}
}

void process()
{
	for(int i=1;i<=N;i++){
		D[i][0] = A[i][0];
		for(int j=1;j<M;j++){
			for(int k=0;k<=i;k++){
				if(D[i][j] < D[i-k][j-1] + A[k][j]){
					D[i][j] = D[i-k][j-1] + A[k][j];
					P[i][j] = k;
				}
			}
		}
	}
}

void dfs(int y,int x)
{
	if(x == 0){
		cout << y << " ";
		return;
	}
	dfs(y-P[y][x],x-1);
	cout << P[y][x] << " ";
}

void output()
{
	cout << D[N][M-1] << endl;
	dfs(N,M-1);
}

int main()
{
	input();
	process();
	output();
	return 0;
}