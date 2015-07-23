#include<iostream>
#include<stdio.h>
using namespace std;

#define Nmax 10010

int N;
double A[Nmax],D[Nmax],Answer;

void input()
{
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
}

void process()
{
	Answer = D[0] = A[0];
	for(int i=1;i<N;i++){
		if(D[i-1] < 1) D[i] = A[i];
		else D[i] = D[i-1] * A[i];
		if(D[i] > Answer) Answer = D[i];
	}
}

void output()
{
	printf("%.3lf",Answer);
}

int main()
{
	input();
	process();
	output();
	return 0;
}