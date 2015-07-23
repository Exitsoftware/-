#include<iostream>
using namespace std;

#define Nmax 1010

int N,Answer;
int A[Nmax][2];
int D[Nmax];

void input()
{
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i][0] >> A[i][1];
}

void process()
{
	int c;
	for(int i=0;i<N;i++){
		for(int j=0;j<N-1;j++){
			if(A[j][0] > A[j+1][0]){
				c = A[j][0];
				A[j][0] = A[j+1][0];
				A[j+1][0] = c;
				c = A[j][1];
				A[j][1] = A[j+1][1];
				A[j+1][1] = c;
			}
		}
	}
	D[0] = 1;
	for(int i=1;i<N;i++){
		D[i] = 1;
		for(int j=0;j<i;j++){
			if(A[j][1] > A[i][0]) continue;
			if(D[j] + 1 > D[i]) D[i] = D[j] + 1;
		}
		if(Answer < D[i]) Answer = D[i];
	}
	cout << Answer;
}

void output()
{
}

int main()
{
	input();
	process();
	output();
	return 0;
}