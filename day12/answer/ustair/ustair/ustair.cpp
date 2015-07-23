#include<iostream>
using namespace std;

#define Nmax 310

int N,A[Nmax],D[3][Nmax];
void input()
{
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
}

int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}

void process()
{
	D[1][0] = A[0];
	for(int i=1;i<N;i++){
		if(i>1) D[1][i] = max(D[1][i-2],D[2][i-2]) + A[i];
		D[2][i] = D[1][i-1] + A[i];
	}
}

void output()
{
	cout << max(D[1][N-1],D[2][N-1]);
}

int main()
{
	input();
	process();
	output();
	return 0;
}