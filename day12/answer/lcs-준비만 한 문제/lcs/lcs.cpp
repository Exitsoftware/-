#include<iostream>
using namespace std;

#define Nmax 1010

int N,M;
int A[Nmax],B[Nmax];
int D[Nmax][Nmax][2];
int Answer,p1,p2;

void input()
{
	cin >> N >> M;
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<M;i++) cin >> B[i];
}

void process()
{
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(i!=0 && D[i][j][0] <D[i-1][j][0]){
				D[i][j][0] = D[i-1][j][0];
				D[i][j][1] = 1;
			}
			if(j != 0 && D[i][j][0] < D[i][j-1][0]){
				D[i][j][0] = D[i][j-1][0];
				D[i][j][1] = 2;
			}
			if(A[i] == B[j]){
				if(i != 0 && j != 0 && D[i][j][0] < D[i-1][j-1][0] + 1){
					D[i][j][0] = D[i-1][j-1][0] + 1;
					D[i][j][1] = 3;
				}
				if(D[i][j][0] == 0){
					D[i][j][0] = 1;
					D[i][j][1] = -1;
				}
			}
			if(D[i][j][0] > Answer){
				Answer = D[i][j][0];
				p1 = i;
				p2 = j;
			}
		}
	}
}

void dfs(int y,int x)
{
	if(D[y][x][1] == 0) return;
	if(D[y][x][1] == -1){
		cout << A[y] << " ";
		return;
	}
	if(D[y][x][1] == 1) dfs(y-1,x);
	if(D[y][x][1] == 2) dfs(y,x-1);
	if(D[y][x][1] == 3){
		dfs(y-1,x-1);
		cout << A[y] << " ";
		return;
	}
}
void output()
{
	cout << Answer << endl;
	dfs(p1,p2);
}

int main()
{
	input();
	process();
	output();
	return 0;
}